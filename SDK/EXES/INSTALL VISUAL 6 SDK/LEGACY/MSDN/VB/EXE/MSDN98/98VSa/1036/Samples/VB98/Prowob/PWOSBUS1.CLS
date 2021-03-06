VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "SmallBusiness1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
' >> L'affichage complet du module donne de meilleurs r�sultats. <<
'
' Stockage pour le num�ro ID de d�bogage.
Private mlngDebugID As Long
Implements IDebug

' L'objet Collection de type Public
'   est facile � d�clarer mais il
'   conduit � des erreurs, comme le
'   montre la feuille frmStraw.
Public Employees As New Collection

Property Get NewEmployeeID() As String
    Static intEmpNum As Integer
    intEmpNum = intEmpNum + 1
    NewEmployeeID = "E" & Format$(intEmpNum, "00000")
End Property

Private Sub Class_Initialize()
    mlngDebugID = DebugInit(Me)
End Sub

Private Sub Class_Terminate()
    DebugTerm Me
End Sub

' -------- Impl�mentation de IDebug --------
'
' IDebug.DebugID permet de distinguer
' ====== -------    les diff�rents objets. Il
'   est requis par les proc�dures de d�bogage
'   DebugInit, DebugTerm et DebugShow
'   d�clar�es dans le module modFriend.
'
Private Property Get IDebug_DebugID() As Long
    IDebug_DebugID = mlngDebugID
End Property


