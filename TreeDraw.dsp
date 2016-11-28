# Microsoft Developer Studio Project File - Name="TreeDraw" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TreeDraw - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TreeDraw.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TreeDraw.mak" CFG="TreeDraw - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TreeDraw - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TreeDraw - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "s:\fltk\include" /I "p:\graphics\public\html\Gallery\LibTarga" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x404 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x404 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 fltk.lib libtarga_mtd.lib opengl32.lib glu32.lib glaux.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386 /libpath:"p:\graphics\public\html\Gallery\LibTarga" /libpath:"s:\fltk\lib"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "s:\fltk\include" /I "p:\graphics\public\html\Gallery\LibTarga" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x404 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x404 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 fltkd.lib libtargad_mtd.lib opengl32.lib glu32.lib glaux.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"p:\graphics\public\html\Gallery\LibTarga" /libpath:"s:\fltk\lib"

!ENDIF 

# Begin Target

# Name "TreeDraw - Win32 Release"
# Name "TreeDraw - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "math"

# PROP Default_Filter ""
# Begin Group "thinair"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\math\thinair\modarith.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\math\thinair\rand_rng.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\math\thinair\randcomp.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\math\thinair\randcong.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\math\thinair\randgen.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\math\thinair\randmcon.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\math\thinair\rndmconm.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\math\drand48.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "LOperation"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\LOperation\LlineClass.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\LOperation\LString.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\LOperation\LStringGetValue.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\LOperation\LStringInterface.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\LOperation\LStringIteration.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\LOperation\LStringMutation.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\LOperation\LTurtle.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\LOperation\Mutation.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "global"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\global\errorHandling.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\global\function.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\global\GenericException.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\global\libtarga.c

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Draw"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Draw\GLGraphics.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Ground.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\Viewer.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ViewWindow.cpp

!IF  "$(CFG)" == "TreeDraw - Win32 Release"

!ELSEIF  "$(CFG)" == "TreeDraw - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "mathH"

# PROP Default_Filter ""
# Begin Group "thinairH"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\math\thinair\environ.h
# End Source File
# Begin Source File

SOURCE=.\math\thinair\erndmcnm.h
# End Source File
# Begin Source File

SOURCE=.\math\thinair\modarith.h
# End Source File
# Begin Source File

SOURCE=.\math\thinair\rand_rng.h
# End Source File
# Begin Source File

SOURCE=.\math\thinair\randcomp.h
# End Source File
# Begin Source File

SOURCE=.\math\thinair\randcong.h
# End Source File
# Begin Source File

SOURCE=.\math\thinair\randgen.h
# End Source File
# Begin Source File

SOURCE=.\math\thinair\randmcon.h
# End Source File
# Begin Source File

SOURCE=.\math\thinair\rndmconm.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\math\drand48.h
# End Source File
# Begin Source File

SOURCE=.\math\ExtraMath.h
# End Source File
# Begin Source File

SOURCE=.\math\vect3.h
# End Source File
# End Group
# Begin Group "LOperationH"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\LOperation\LlineClass.h
# End Source File
# Begin Source File

SOURCE=.\LOperation\LString.h
# End Source File
# Begin Source File

SOURCE=.\LOperation\LTurtle.h
# End Source File
# Begin Source File

SOURCE=.\LOperation\Mutation.h
# End Source File
# End Group
# Begin Group "globalH"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\global\Defines.h
# End Source File
# Begin Source File

SOURCE=.\global\errorHandling.h
# End Source File
# Begin Source File

SOURCE=.\global\function.h
# End Source File
# Begin Source File

SOURCE=.\global\GenericException.h
# End Source File
# Begin Source File

SOURCE=.\global\globals.h
# End Source File
# Begin Source File

SOURCE=.\global\globals.inl
# End Source File
# Begin Source File

SOURCE=.\global\libtarga.h
# End Source File
# Begin Source File

SOURCE=.\global\typedefs.h
# End Source File
# End Group
# Begin Group "DrawH"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Draw\GLGraphics.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Ground.h
# End Source File
# Begin Source File

SOURCE=.\ViewWindow.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
