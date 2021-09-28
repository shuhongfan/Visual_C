; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_StudentView
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_Student.h"
LastPage=0

ClassCount=9
Class1=CEx_StudentApp
Class2=CEx_StudentDoc
Class3=CEx_StudentView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CStudentTreeView
Class7=CStudentSet
Class8=CCourseSet
Class9=CScoreSet
Resource2=IDD_ABOUTBOX

[CLS:CEx_StudentApp]
Type=0
HeaderFile=Ex_Student.h
ImplementationFile=Ex_Student.cpp
Filter=N

[CLS:CEx_StudentDoc]
Type=0
HeaderFile=Ex_StudentDoc.h
ImplementationFile=Ex_StudentDoc.cpp
Filter=N

[CLS:CEx_StudentView]
Type=0
HeaderFile=Ex_StudentView.h
ImplementationFile=Ex_StudentView.cpp
Filter=C
BaseClass=CListView
VirtualFilter=VWC
LastObject=CEx_StudentView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_Student.cpp
ImplementationFile=Ex_Student.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CStudentTreeView]
Type=0
HeaderFile=StudentTreeView.h
ImplementationFile=StudentTreeView.cpp
BaseClass=CTreeView
Filter=C
LastObject=CStudentTreeView
VirtualFilter=VWC

[CLS:CStudentSet]
Type=0
HeaderFile=StudentSet.h
ImplementationFile=StudentSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CStudentSet

[DB:CStudentSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[studentname], 12, 40
Column2=[studentno], 12, 40
Column3=[xb], -7, 1
Column4=[birthday], 11, 16
Column5=[special], 12, 100
Column6=[totalcredit], 7, 4

[CLS:CCourseSet]
Type=0
HeaderFile=CourseSet.h
ImplementationFile=CourseSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CCourseSet

[DB:CCourseSet]
DB=1
DBType=ODBC
ColumnCount=7
Column1=[courseno], 12, 40
Column2=[special], 12, 100
Column3=[coursename], 12, 100
Column4=[coursetype], 12, 20
Column5=[openterm], -6, 1
Column6=[hours], -6, 1
Column7=[credit], 7, 4

[CLS:CScoreSet]
Type=0
HeaderFile=ScoreSet.h
ImplementationFile=ScoreSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CScoreSet

[DB:CScoreSet]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[studentno], 12, 16
Column2=[course], 12, 14
Column3=[score], 7, 4
Column4=[credit], 7, 4

