; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_StudentView
LastTemplate=CTreeView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_Student.h"
LastPage=0

ClassCount=6
Class1=CEx_StudentApp
Class2=CEx_StudentDoc
Class3=CEx_StudentView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CStudentTreeView
Resource2=IDD_ABOUTBOX
Resource3=IDD_STUINFO

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
LastObject=ID_STUINFO_ADD




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
Command16=ID_STUINFO_ADD
Command17=ID_APP_ABOUT
CommandCount=17

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

[DLG:IDD_STUINFO]
Type=1
Class=?
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=65535,static,1342308352
Control4=65535,static,1342308352
Control5=65535,static,1342308352
Control6=65535,static,1342308352
Control7=65535,static,1342308352
Control8=IDC_EDIT_NAME,edit,1350631552
Control9=IDC_EDIT_NO,edit,1350631552
Control10=IDC_RADIO_MALE,button,1342177289
Control11=IDC_RADIO_FEMALE,button,1342177289
Control12=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242848
Control13=65535,static,1342177296
Control14=IDC_COMBO_SPECIAL,combobox,1344340226

