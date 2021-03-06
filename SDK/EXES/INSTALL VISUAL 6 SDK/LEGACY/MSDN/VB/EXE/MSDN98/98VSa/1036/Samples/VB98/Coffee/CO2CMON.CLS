VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "CoffeeMonitor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit
' > Pour plus d'informations sur cet exemple d'application,
'   recherchez "Coffee" dans l'aide en ligne.
' > Le fichier AboutCof.Txt, pr�sent dans le dossier
'   Documents associ�s de CoffWat2.vbp, contient �galement
'   des informations sur cet exemple.

' La classe CoffeeMonitor surveille le fonctionnement
'   d'une cafeti�re "high tech" connect�e � une interface
'   s�rie imaginaire, en utilisant une minuterie de
'   rappel (objet XTimer) qui d�termine la fr�quence
'   avec laquelle il faut v�rifier le caf�. Lorsque
'   le caf� est pr�t, l'objet CoffeeMonitor d�clenche
'   un �v�nement pour en informer les clients. Bien
'   entendu, ce type de cafeti�re "high tech" n'ayant
'   pas encore �t� invent�, cet exemple
'   d'application d�clenche donc simplement un �vennement
'   CoffeeReady tous les dix secondes.
'
' (Reportez-vous �galement � la classe CoffeeMonitor2
'   qui illustre une notification en utilisant une
'   m�thode de rappel au lieu d'un �v�nement.)
'
' Note: la valeur PublicNotCreatable a �t� affect�e � la
'   propri�t� Instancing de la classe CoffeeMonitor.
'   Cela signifie que les clients ne peuvent pas cr�er
'   des objets CoffeeMonitor; ils ne peuvent qu'obtenir
'   une r�f�rence � l'objet partag�e CoffeeMonitor
'   en cr�ant un objet Connector et en acc�dant � sa
'   propri�t� CoffeeMonitor.
'
' En utilisant une minuterie en code seul, cette version
'   de CoffeeMonitor corrige le bogue d�crit dans la section
'   "Utilisation du CoffeeMonitor partag�" du chapitre
'   "Cr�ation d'un composant EXE ActiveX", des Manuels
'   en ligne, au moyen duquel des objets CoffeeMonitor
'   multiples peuvent parfois �tre cr��s.
'
' Ce bogue �tait provoqu� par le code 'compte d'utilisation'
'   que l'objet Connector utilisait pour lib�rer la
'   r�f�rence globale � l'objet partag� CoffeeMonitor.
'   Le compte d'utilisation �tait requis parce que les
'   proc�dures pas � pas des Manuels en ligne utilisaient
'   une feuille cach�e pour maintenir un contr�le Timer;
'   les feuilles cach�es emp�chent le d�chargement des
'   composants (comme le d�crit la section "D�marrage et
'   arr�t d'un composant" des Manuels en ligne), ainsi que
'   la lib�ration de la m�moire globale, et l'affectation
'   de la valeur Nothing � la variable gCoffeeMonitor.
'
' Contrairement � ce que fait la feuille cach�e avec le contr�le
'   Timer, l'objet XTimer n'emp�che pas le d�chargement du composant
'   Coffee2 lorsque le dernier client lib�re sa derni�re
'   r�f�rence. Vous remarquerez, cependant, que la variable
'   globale gCoffeeMonitor maintiendra l'objet CoffeeMonitor
'   en vie jusqu'� ce que tous les objets fournis par Coffee2
'   soient lib�r�s par leurs clients respectifs.

' =======================================================
'  AVERTISSEMENT!  Les minuteries en code seul sont
'   implicitement dangereuses dans l'environnement de
'   d�veloppement Visual Basic car le syst�me effectue
'   sans rel�che des appels dans votre code jusqu'� ce
'   que la minuterie soit arr�t�e par un appel d'API.
'   Il est plus s�r d'utiliser des contr�les Timer pendant
'   une grande partie de la proc�dure de d�veloppement,
'   et de repasser � des minuteries de rappel tout � la fin.
' =======================================================

' mwTimer maintient une r�f�rence � la minuterie en code
' -------   seul qui indique � l'objet CoffeeMonitor
'   � quel moment il faut surveiller le caf�. La
'   variable �tant d�clar�e en tant que WithEvents,
'   l'objet CoffeeMonitor re�oit les �v�nements Tick
'   de l'objet XTimer (reportez-vous � Sub mwXTimer_Tick,
'   plus bas). Le code pour l'objet XTimer se trouve
'   dans le fichier XTimers.vbp.
Private WithEvents mwXTimer As XTimer
Attribute mwXTimer.VB_VarHelpID = -1

' CoffeeReady est l'�v�nement que CoffeeMonitor d�clenche
' -----------   pour ses clients lorsque le caf� est pr�t.
'   Le mot cl� Public est omis de la d�claration de
'   l'�v�nement car les �v�nements sont toujours publics.
Event CoffeeReady()
    
Private Sub Class_Initialize()
    ' La premi�re chose que fait un objet CoffeeMonitor est de cr�er
    '   l'objet XTimer. Lorsque l'affectation est faite,
    '   Visual Basic connecte l'�v�nement Tick de l'objet
    '   XTimer � la proc�dure d'�v�nement mwXTimer_Tick
    '   (Voir ci-dessous).
    Set mwXTimer = New XTimer
    '
    ' La minuterie est d�finie pour �mettre un �v�nement
    '   Tick toutes les dix secondes (10.000 millisecondes).
    mwXTimer.Interval = 10000
    mwXTimer.Enabled = True
End Sub

Private Sub Class_Terminate()
' Il est important de d�sactiver l'objet XTimer
    '   avant de le lib�rer. Comme cela est d�crit
    '   dans le fichier XTimers.vbp, l'abandon de
    '   l'ex�cution d'un objet XTimer provoque
    '   essentiellement une perte de la minuterie du
    '   syst�me, jusqu'� ce que XTimers.DLL ne soit
    '   d�charg�.
    mwXTimer.Enabled = False
    Set mwXTimer = Nothing
    '
    Debug.Print "CoffeeMonitor (�v�nements) s'est termin� � " & Now
End Sub

' mwXTimer_Tick est la proc�dure d'�v�nement que CoffeeMonitor2
' -------------   utilise pour recevoir les �v�nements Tick
'   de l'objet XTimer. Le nom d'une proc�dure d'�v�nement
'   associ�e avec une variable WithEvents prend toujours le
'   nom de la variable comme pr�fixe.
'
Private Sub mwXTimer_Tick()
    ' (Code de test du port s�rie omis.)
'
    ' Informe le client.
    RaiseEvent CoffeeReady
End Sub
