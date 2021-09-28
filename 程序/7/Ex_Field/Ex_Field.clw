; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCourseSet
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_Field.h"
LastPage=0

ClassCount=6
Class1=CEx_FieldApp
Class2=CEx_FieldDoc
Class3=CEx_FieldView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CCourseSet
Resource2=IDD_ABOUTBOX

[CLS:CEx_FieldApp]
Type=0
HeaderFile=Ex_Field.h
ImplementationFile=Ex_Field.cpp
Filter=N

[CLS:CEx_FieldDoc]
Type=0
HeaderFile=Ex_FieldDoc.h
ImplementationFile=Ex_FieldDoc.cpp
Filter=N

[CLS:CEx_FieldView]
Type=0
HeaderFile=Ex_FieldView.h
ImplementationFile=Ex_FieldView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_Field.cpp
ImplementationFile=Ex_Field.cpp
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

