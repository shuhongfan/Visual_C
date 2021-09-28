; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCourseDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_Ctrls.h"

ClassCount=5
Class1=CEx_CtrlsApp
Class2=CEx_CtrlsDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_EX_CTRLS_DIALOG
Class4=CStuInfoDlg
Class5=CCourseDlg
Resource4=IDD_COURSE

[CLS:CEx_CtrlsApp]
Type=0
HeaderFile=Ex_Ctrls.h
ImplementationFile=Ex_Ctrls.cpp
Filter=N

[CLS:CEx_CtrlsDlg]
Type=0
HeaderFile=Ex_CtrlsDlg.h
ImplementationFile=Ex_CtrlsDlg.cpp
Filter=D
LastObject=CEx_CtrlsDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_CtrlsDlg.h
ImplementationFile=Ex_CtrlsDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_EX_CTRLS_DIALOG]
Type=1
Class=CEx_CtrlsDlg
ControlCount=4
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_BUTTON_COURSE,button,1342242816
Control4=IDC_LIST1,listbox,1352728833

[CLS:CStuInfoDlg]
Type=0
HeaderFile=StuInfoDlg.h
ImplementationFile=StuInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=65535
VirtualFilter=dWC

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

[CLS:CCourseDlg]
Type=0
HeaderFile=CourseDlg.h
ImplementationFile=CourseDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

