# Microsoft Visual C++ Generated NMAKE File, Format Version 20054
# MSVCPRJ: version 2.00.4215
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Release" && "$(CFG)" != "Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "mygl.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "Win32 Debug"
MTL=MkTypLib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALL : $(OUTDIR)/mygl.exe $(OUTDIR)/mygl.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE CPP /nologo /MT /W3 /GX /YX /Ox /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_X86_" /D "_MBCS" /FR /c
# ADD CPP /nologo /MT /W3 /GX /Ox /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_X86_" /D "_MBCS" /FR /Yu"STDAFX.H" /c
CPP_PROJ=/nologo /MT /W3 /GX /Ox /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_X86_" /D "_MBCS" /FR$(INTDIR)/ /Fp$(OUTDIR)/"mygl.pch" /Yu"STDAFX.H"\
 /Fo$(INTDIR)/ /c 
CPP_OBJS=.\WinRel/
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"mygl.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"mygl.bsc" 
BSC32_SBRS= \
	$(INTDIR)/stdafx.sbr \
	$(INTDIR)/mygl.sbr \
	$(INTDIR)/mainfrm.sbr \
	$(INTDIR)/mygldoc.sbr \
	$(INTDIR)/myglview.sbr \
	$(INTDIR)/drawgl.sbr \
	$(INTDIR)/copengl.sbr \
	$(INTDIR)/pixform.sbr \
	$(INTDIR)/morepfd.sbr \
	$(INTDIR)/pfdinfo.sbr

$(OUTDIR)/mygl.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 nafxcw.lib olecli32.lib olesvr32.lib opengl32.lib glu32.lib glaux.lib /NOLOGO /SUBSYSTEM:windows /MACHINE:IX86
# ADD LINK32 nafxcw.lib olecli32.lib olesvr32.lib opengl32.lib glu32.lib glaux.lib /NOLOGO /SUBSYSTEM:windows /MACHINE:IX86
LINK32_FLAGS=nafxcw.lib olecli32.lib olesvr32.lib opengl32.lib glu32.lib\
 glaux.lib /NOLOGO /SUBSYSTEM:windows /INCREMENTAL:no /PDB:$(OUTDIR)/"mygl.pdb"\
 /MACHINE:IX86 /OUT:$(OUTDIR)/"mygl.exe" 
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/mygl.res \
	$(INTDIR)/stdafx.obj \
	$(INTDIR)/mygl.obj \
	$(INTDIR)/mainfrm.obj \
	$(INTDIR)/mygldoc.obj \
	$(INTDIR)/myglview.obj \
	$(INTDIR)/drawgl.obj \
	$(INTDIR)/copengl.obj \
	$(INTDIR)/pixform.obj \
	$(INTDIR)/morepfd.obj \
	$(INTDIR)/pfdinfo.obj

$(OUTDIR)/mygl.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WinDebug"
# PROP Intermediate_Dir "WinDebug"
OUTDIR=.\WinDebug
INTDIR=.\WinDebug

ALL : $(OUTDIR)/mygl.exe $(OUTDIR)/mygl.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /YX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_X86_" /D "_MBCS" /FR /c
# ADD CPP /nologo /MT /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_X86_" /D "_MBCS" /FR /Yu"STDAFX.H" /c
CPP_PROJ=/nologo /MT /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D\
 "_X86_" /D "_MBCS" /FR$(INTDIR)/ /Fp$(OUTDIR)/"mygl.pch" /Yu"STDAFX.H"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"mygl.pdb" /c 
CPP_OBJS=.\WinDebug/
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"mygl.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"mygl.bsc" 
BSC32_SBRS= \
	$(INTDIR)/stdafx.sbr \
	$(INTDIR)/mygl.sbr \
	$(INTDIR)/mainfrm.sbr \
	$(INTDIR)/mygldoc.sbr \
	$(INTDIR)/myglview.sbr \
	$(INTDIR)/drawgl.sbr \
	$(INTDIR)/copengl.sbr \
	$(INTDIR)/pixform.sbr \
	$(INTDIR)/morepfd.sbr \
	$(INTDIR)/pfdinfo.sbr

$(OUTDIR)/mygl.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 olecli32.lib olesvr32.lib opengl32.lib glu32.lib glaux.lib nafxcwd.lib /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:IX86
# ADD LINK32 olecli32.lib olesvr32.lib opengl32.lib glu32.lib glaux.lib nafxcwd.lib /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:IX86
LINK32_FLAGS=olecli32.lib olesvr32.lib opengl32.lib glu32.lib glaux.lib\
 nafxcwd.lib /NOLOGO /SUBSYSTEM:windows /INCREMENTAL:yes\
 /PDB:$(OUTDIR)/"mygl.pdb" /DEBUG /MACHINE:IX86 /OUT:$(OUTDIR)/"mygl.exe" 
DEF_FILE=
LINK32_OBJS= \
	$(INTDIR)/mygl.res \
	$(INTDIR)/stdafx.obj \
	$(INTDIR)/mygl.obj \
	$(INTDIR)/mainfrm.obj \
	$(INTDIR)/mygldoc.obj \
	$(INTDIR)/myglview.obj \
	$(INTDIR)/drawgl.obj \
	$(INTDIR)/copengl.obj \
	$(INTDIR)/pixform.obj \
	$(INTDIR)/morepfd.obj \
	$(INTDIR)/pfdinfo.obj

$(OUTDIR)/mygl.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Group "Source Files"

################################################################################
# Begin Source File

SOURCE=.\mygl.rc
DEP_MYGL_=\
	.\RES\MYGL.ICO\
	.\RES\TOOLBAR.BMP\
	.\RES\CURSOR1.CUR\
	.\res\mygl.rc2

$(INTDIR)/mygl.res :  $(SOURCE)  $(DEP_MYGL_) $(INTDIR)
   $(RSC) $(RSC_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\stdafx.cpp
DEP_STDAF=\
	.\stdafx.h

!IF  "$(CFG)" == "Win32 Release"

# ADD BASE CPP /Yc"STDAFX.H"
# ADD CPP /Yc"STDAFX.H"

$(INTDIR)/stdafx.obj :  $(SOURCE)  $(DEP_STDAF) $(INTDIR)
   $(CPP) /nologo /MT /W3 /GX /Ox /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_X86_" /D "_MBCS" /FR$(INTDIR)/ /Fp$(OUTDIR)/"mygl.pch" /Yc"STDAFX.H"\
 /Fo$(INTDIR)/ /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

# ADD BASE CPP /Yc"STDAFX.H"
# ADD CPP /Yc"STDAFX.H"

$(INTDIR)/stdafx.obj :  $(SOURCE)  $(DEP_STDAF) $(INTDIR)
   $(CPP) /nologo /MT /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D\
 "_X86_" /D "_MBCS" /FR$(INTDIR)/ /Fp$(OUTDIR)/"mygl.pch" /Yc"STDAFX.H"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"mygl.pdb" /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\mygl.cpp
DEP_MYGL_C=\
	.\stdafx.h\
	.\mygl.h\
	.\mainfrm.h\
	.\mygldoc.h\
	.\myglview.h\
	.\COpenGL.h

$(INTDIR)/mygl.obj :  $(SOURCE)  $(DEP_MYGL_C) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\mainfrm.cpp
DEP_MAINF=\
	.\stdafx.h\
	.\mygl.h\
	.\mainfrm.h

$(INTDIR)/mainfrm.obj :  $(SOURCE)  $(DEP_MAINF) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\mygldoc.cpp
DEP_MYGLD=\
	.\stdafx.h\
	.\mygl.h\
	.\mygldoc.h

$(INTDIR)/mygldoc.obj :  $(SOURCE)  $(DEP_MYGLD) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\myglview.cpp
DEP_MYGLV=\
	.\stdafx.h\
	.\COpenGL.h\
	.\mygl.h\
	.\mygldoc.h\
	.\myglview.h\
	.\drawgl.h\
	.\pixform.h\
	.\pfdinfo.h

$(INTDIR)/myglview.obj :  $(SOURCE)  $(DEP_MYGLV) $(INTDIR)\
 $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\drawgl.cpp
DEP_DRAWG=\
	.\stdafx.h\
	.\drawgl.h\
	.\COpenGL.h

$(INTDIR)/drawgl.obj :  $(SOURCE)  $(DEP_DRAWG) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\copengl.cpp
DEP_COPEN=\
	.\stdafx.h\
	.\COpenGL.h

$(INTDIR)/copengl.obj :  $(SOURCE)  $(DEP_COPEN) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\pixform.cpp
DEP_PIXFO=\
	.\stdafx.h\
	.\mygl.h\
	.\pixform.h\
	.\morepfd.h\
	.\mygldoc.h\
	.\myglview.h\
	.\COpenGL.h

$(INTDIR)/pixform.obj :  $(SOURCE)  $(DEP_PIXFO) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\morepfd.cpp
DEP_MOREP=\
	.\stdafx.h\
	.\mygl.h\
	.\morepfd.h

$(INTDIR)/morepfd.obj :  $(SOURCE)  $(DEP_MOREP) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
################################################################################
# Begin Source File

SOURCE=.\pfdinfo.cpp
DEP_PFDIN=\
	.\stdafx.h\
	.\mygl.h\
	.\pfdinfo.h\
	.\mygldoc.h\
	.\myglview.h\
	.\COpenGL.h

$(INTDIR)/pfdinfo.obj :  $(SOURCE)  $(DEP_PFDIN) $(INTDIR) $(INTDIR)/stdafx.obj

# End Source File
# End Group
# End Project
################################################################################