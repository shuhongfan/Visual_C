; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_chatDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_chat.h"

ClassCount=4
Class1=CEx_chatApp
Class2=CEx_chatDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_EX_CHAT_DIALOG

[CLS:CEx_chatApp]
Type=0
HeaderFile=Ex_chat.h
ImplementationFile=Ex_chat.cpp
Filter=N

[CLS:CEx_chatDlg]
Type=0
HeaderFile=Ex_chatDlg.h
ImplementationFile=Ex_chatDlg.cpp
Filter=D

[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_chatDlg.h
ImplementationFile=Ex_chatDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_EX_CHAT_DIALOG]
Type=1
Class=CEx_chatDlg
ControlCount=9
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_COMBO_TYPE,combobox,1344340226
Control4=IDC_BUTTON_RUN,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_LIST_MSG,listbox,1352728833
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_MSG,edit,1350631552
Control9=IDC_BUTTON_SEND,button,1342242816

