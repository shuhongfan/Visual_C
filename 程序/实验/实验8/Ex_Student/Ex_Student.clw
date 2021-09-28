; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_StudentView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ex_student.h"
LastPage=0

ClassCount=6
Class1=CEx_StudentApp
Class2=CAboutDlg
Class3=CEx_StudentDoc
Class4=CEx_StudentView
Class5=CMainFrame
Class6=CStuInfoDlg

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Resource3=IDD_STUINFO

[CLS:CEx_StudentApp]
Type=0
BaseClass=CWinApp
HeaderFile=Ex_Student.h
ImplementationFile=Ex_Student.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Ex_Student.cpp
ImplementationFile=Ex_Student.cpp
LastObject=CAboutDlg

[CLS:CEx_StudentDoc]
Type=0
BaseClass=CDocument
HeaderFile=Ex_StudentDoc.h
ImplementationFile=Ex_StudentDoc.cpp

[CLS:CEx_StudentView]
Type=0
BaseClass=CListView
HeaderFile=Ex_StudentView.h
ImplementationFile=Ex_StudentView.cpp
Filter=C
VirtualFilter=VWC
LastObject=CEx_StudentView

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CStuInfoDlg]
Type=0
BaseClass=CDialog
HeaderFile=StuInfoDlg.h
ImplementationFile=StuInfoDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=ID_STUINFO_ADD

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
ControlCount=16
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
Control15=IDC_DRAW,static,1342312448
Control16=IDC_BUTTON_PHOTO,button,1342242816

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

