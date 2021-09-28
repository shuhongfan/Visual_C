; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_ADOView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_ADO.h"
LastPage=0

ClassCount=5
Class1=CEx_ADOApp
Class2=CEx_ADODoc
Class3=CEx_ADOView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Resource3=IDD_STUINFO

[CLS:CEx_ADOApp]
Type=0
HeaderFile=Ex_ADO.h
ImplementationFile=Ex_ADO.cpp
Filter=N

[CLS:CEx_ADODoc]
Type=0
HeaderFile=Ex_ADODoc.h
ImplementationFile=Ex_ADODoc.cpp
Filter=N

[CLS:CEx_ADOView]
Type=0
HeaderFile=Ex_ADOView.h
ImplementationFile=Ex_ADOView.cpp
Filter=C
BaseClass=CListView
VirtualFilter=VWC
LastObject=ID_OP_DEL


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_OP_ADD




[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_ADO.cpp
ImplementationFile=Ex_ADO.cpp
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
Command16=ID_OP_ADD
Command17=ID_OP_CHA
Command18=ID_OP_DEL
Command19=ID_APP_ABOUT
CommandCount=19

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

