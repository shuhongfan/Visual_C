; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_MenuSDI.h"
LastPage=0

ClassCount=5
Class1=CEx_MenuSDIApp
Class2=CEx_MenuSDIDoc
Class3=CEx_MenuSDIView
Class4=CMainFrame

ResourceCount=9
Resource1=IDR_MAINFRAME
Resource2=IDR_MENU1
Class5=CAboutDlg
Resource7=IDR_MAINFRAME1
Resource8=IDR_TOOLBAR1
Resource9=IDD_ABOUTBOX

[CLS:CEx_MenuSDIApp]
Type=0
HeaderFile=Ex_MenuSDI.h
ImplementationFile=Ex_MenuSDI.cpp
Filter=N

[CLS:CEx_MenuSDIDoc]
Type=0
HeaderFile=Ex_MenuSDIDoc.h
ImplementationFile=Ex_MenuSDIDoc.cpp
Filter=N

[CLS:CEx_MenuSDIView]
Type=0
HeaderFile=Ex_MenuSDIView.h
ImplementationFile=Ex_MenuSDIView.cpp
Filter=C


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
HeaderFile=Ex_MenuSDI.cpp
ImplementationFile=Ex_MenuSDI.cpp
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
Command16=ID_VIEW_TEST
Command17=ID_APP_ABOUT
CommandCount=17

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_VIEW_TEST
Command2=ID_TEST_RETURN
Command3=ID_EDIT_COPY
Command4=ID_FILE_NEW
Command5=ID_FILE_OPEN
Command6=ID_FILE_PRINT
Command7=ID_FILE_SAVE
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_NEXT_PANE
Command12=ID_PREV_PANE
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_EDIT_CUT
Command16=ID_EDIT_UNDO
CommandCount=16

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_TEST_RETURN
CommandCount=1

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_TEST_RETURN
Command8=ID_VIEW_TEST
Command9=ID_FILE_PRINT
Command10=ID_APP_ABOUT
CommandCount=10

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=ID_TEST_RETURN
Command2=ID_VIEW_TEST
Command3=ID_APP_ABOUT
CommandCount=3

[TB:IDR_MAINFRAME1]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_TEST_RETURN
Command8=ID_VIEW_TEST
Command9=ID_FILE_PRINT
Command10=ID_APP_ABOUT
CommandCount=10

