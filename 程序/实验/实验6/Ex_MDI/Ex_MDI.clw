; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_StudentDoc
LastTemplate=CView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ex_mdi.h"
LastPage=0

ClassCount=10
Class1=CChildFrame
Class2=CCourseDlg
Class3=CEx_MDIApp
Class4=CAboutDlg
Class5=CEx_MDIDoc
Class6=CEx_MDIView
Class7=CMainFrame
Class8=CStuInfoDlg

ResourceCount=6
Resource1=IDD_STUINFO
Resource2=IDR_STUDENT
Resource3=IDR_MAINFRAME
Resource4=IDR_EX_MDITYPE
Class9=CEx_StudentDoc
Class10=CEx_StudentView
Resource5=IDD_ABOUTBOX
Resource6=IDD_COURSE

[CLS:CChildFrame]
Type=0
BaseClass=CMDIChildWnd
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp

[CLS:CCourseDlg]
Type=0
BaseClass=CDialog
HeaderFile=CourseDlg.h
ImplementationFile=CourseDlg.cpp

[CLS:CEx_MDIApp]
Type=0
BaseClass=CWinApp
HeaderFile=Ex_MDI.h
ImplementationFile=Ex_MDI.cpp
LastObject=CEx_MDIApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Ex_MDI.cpp
ImplementationFile=Ex_MDI.cpp
LastObject=CAboutDlg

[CLS:CEx_MDIDoc]
Type=0
BaseClass=CDocument
HeaderFile=Ex_MDIDoc.h
ImplementationFile=Ex_MDIDoc.cpp
LastObject=ID_COURSEINFO_ADD
Filter=N
VirtualFilter=DC

[CLS:CEx_MDIView]
Type=0
BaseClass=CView
HeaderFile=Ex_MDIView.h
ImplementationFile=Ex_MDIView.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CMDIFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CStuInfoDlg]
Type=0
BaseClass=CDialog
HeaderFile=StuInfoDlg.h
ImplementationFile=StuInfoDlg.cpp

[DLG:IDD_COURSE]
Type=1
Class=CCourseDlg
ControlCount=18
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342177296
Control10=IDC_EDIT_COURSENO,edit,1350631552
Control11=IDC_EDIT_COURSENAME,edit,1350631552
Control12=IDC_EDIT_COURSEHOURS,edit,1350631552
Control13=IDC_EDIT_CREDIT,edit,1350631552
Control14=IDC_COMBO_TYPE,combobox,1344340226
Control15=IDC_STATIC,static,1342308352
Control16=IDC_COMBO_SPECIAL,combobox,1344340226
Control17=IDC_EDIT_OPEN,edit,1350631552
Control18=IDC_SPIN1,msctls_updown32,1342177334

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_STUINFO]
Type=1
Class=CStuInfoDlg
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

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_EX_MDITYPE]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_COURSEINFO_ADD
Command22=ID_APP_ABOUT
CommandCount=22

[ACL:IDR_MAINFRAME]
Type=1
Class=?
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

[CLS:CEx_StudentDoc]
Type=0
HeaderFile=Ex_StudentDoc.h
ImplementationFile=Ex_StudentDoc.cpp
BaseClass=CDocument
Filter=N
LastObject=CEx_StudentDoc
VirtualFilter=DC

[CLS:CEx_StudentView]
Type=0
HeaderFile=Ex_StudentView.h
ImplementationFile=Ex_StudentView.cpp
BaseClass=CView
Filter=C
LastObject=ID_STUINFO_ADD

[MNU:IDR_STUDENT]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_STUINFO_ADD
Command12=ID_APP_ABOUT
CommandCount=12

