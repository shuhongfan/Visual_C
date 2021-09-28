; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_GridView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_Grid.h"
LastPage=0

ClassCount=6
Class1=CEx_GridApp
Class2=CEx_GridDoc
Class3=CEx_GridView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource7=IDD_EX_GRID_FORM
Class5=CEx_GridSet

[CLS:CEx_GridApp]
Type=0
HeaderFile=Ex_Grid.h
ImplementationFile=Ex_Grid.cpp
Filter=N

[CLS:CEx_GridDoc]
Type=0
HeaderFile=Ex_GridDoc.h
ImplementationFile=Ex_GridDoc.cpp
Filter=N

[CLS:CEx_GridView]
Type=0
HeaderFile=Ex_GridView.h
ImplementationFile=Ex_GridView.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=IDC_MSFLEXGRID1


[CLS:CEx_GridSet]
Type=0
HeaderFile=Ex_GridSet.h
ImplementationFile=Ex_GridSet.cpp
Filter=N

[DB:CEx_GridSet]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[studentno], 12, 16
Column2=[course], 12, 14
Column3=[score], 7, 4
Column4=[credit], 7, 4


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_Grid.cpp
ImplementationFile=Ex_Grid.cpp
Filter=D

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
Command14=ID_RECORD_FIRST
Command15=ID_RECORD_PREV
Command16=ID_RECORD_NEXT
Command17=ID_RECORD_LAST
Command18=ID_VIEW_TOOLBAR
Command19=ID_VIEW_STATUS_BAR
Command20=ID_APP_ABOUT
CommandCount=20

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

[DLG:IDD_EX_GRID_FORM]
Type=1
Class=CEx_GridView
ControlCount=1
Control1=IDC_MSFLEXGRID1,{6262D3A0-531B-11CF-91F6-C2863C385E30},1342242816

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
Command8=ID_RECORD_FIRST
Command9=ID_RECORD_PREV
Command10=ID_RECORD_NEXT
Command11=ID_RECORD_LAST
Command12=ID_APP_ABOUT
CommandCount=12

