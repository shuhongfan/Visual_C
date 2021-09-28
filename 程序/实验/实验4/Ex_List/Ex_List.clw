; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_ListDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_List.h"

ClassCount=4
Class1=CEx_ListApp
Class2=CEx_ListDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_EX_LIST_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CScoreDlg
Resource4=IDD_SCORE

[CLS:CEx_ListApp]
Type=0
HeaderFile=Ex_List.h
ImplementationFile=Ex_List.cpp
Filter=N

[CLS:CEx_ListDlg]
Type=0
HeaderFile=Ex_ListDlg.h
ImplementationFile=Ex_ListDlg.cpp
Filter=D
LastObject=IDC_LIST1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_ListDlg.h
ImplementationFile=Ex_ListDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_EX_LIST_DIALOG]
Type=1
Class=CEx_ListDlg
ControlCount=4
Control1=IDCANCEL,button,1342242816
Control2=IDC_LIST1,SysListView32,1350631425
Control3=IDC_BUTTON_SCORE,button,1342242816
Control4=IDC_BUTTON_CHANGE,button,1342242816

[DLG:IDD_SCORE]
Type=1
Class=CScoreDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_STUNO,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_COURSENO,edit,1350631552
Control7=IDC_EDIT_SCORE,edit,1350631552
Control8=IDC_EDIT_CREDIT,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352

[CLS:CScoreDlg]
Type=0
HeaderFile=ScoreDlg.h
ImplementationFile=ScoreDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CScoreDlg

