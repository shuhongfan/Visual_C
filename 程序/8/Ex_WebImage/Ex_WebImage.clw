; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_WebImageDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ex_WebImage.h"

ClassCount=3
Class1=CEx_WebImageApp
Class2=CEx_WebImageDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_EX_WEBIMAGE_DIALOG

[CLS:CEx_WebImageApp]
Type=0
HeaderFile=Ex_WebImage.h
ImplementationFile=Ex_WebImage.cpp
Filter=N

[CLS:CEx_WebImageDlg]
Type=0
HeaderFile=Ex_WebImageDlg.h
ImplementationFile=Ex_WebImageDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_IMAGE_OPEN

[CLS:CAboutDlg]
Type=0
HeaderFile=Ex_WebImageDlg.h
ImplementationFile=Ex_WebImageDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_EX_WEBIMAGE_DIALOG]
Type=1
Class=CEx_WebImageDlg
ControlCount=3
Control1=IDCANCEL,button,1342242816
Control2=IDC_EXPLORER1,{8856F961-340A-11D0-A96B-00C04FD705A2},1342242816
Control3=IDC_IMAGE_OPEN,button,1342242816

