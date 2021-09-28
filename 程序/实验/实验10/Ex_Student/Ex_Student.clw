; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEx_StudentView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ex_student.h"
LastPage=0

ClassCount=11
Class1=CCourseSet
Class2=CEx_StudentApp
Class3=CAboutDlg
Class4=CEx_StudentDoc
Class5=CEx_StudentView
Class6=CMainFrame
Class7=CScoreDlg
Class8=CScoreSet
Class9=CSpecialSet
Class10=CStudentSet

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SCORE
Class11=CSeekDlg
Resource4=IDD_DIALOG_SEEK

[CLS:CCourseSet]
Type=0
HeaderFile=CourseSet.h
ImplementationFile=CourseSet.cpp

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

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CScoreDlg]
Type=0
BaseClass=CDialog
HeaderFile=ScoreDlg.h
ImplementationFile=ScoreDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CScoreDlg

[CLS:CScoreSet]
Type=0
HeaderFile=ScoreSet.h
ImplementationFile=ScoreSet.cpp

[CLS:CSpecialSet]
Type=0
HeaderFile=SpecialSet.h
ImplementationFile=SpecialSet.cpp

[CLS:CStudentSet]
Type=0
HeaderFile=StudentSet.h
ImplementationFile=StudentSet.cpp

[DB:CCourseSet]
DB=1

[DB:CScoreSet]
DB=1

[DB:CSpecialSet]
DB=1

[DB:CStudentSet]
DB=1

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SCORE]
Type=1
Class=CScoreDlg
ControlCount=22
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
Control11=IDC_STATIC,static,1342177297
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_NAME,combobox,1344340226
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC_TERM,static,1342312961
Control16=IDC_STATIC_SPECIAL,static,1342312961
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC_TYPE,static,1342312961
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC_HOURS,static,1342312961
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342177297

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
Command16=ID_SCORE_ADD
Command17=ID_SCORE_DEL
Command18=ID_SCORE_CHANGE
Command19=ID_SCORE_SEEK
Command20=ID_APP_ABOUT
CommandCount=20

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

[DLG:IDD_DIALOG_SEEK]
Type=1
Class=CSeekDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC_SEEK,static,1342308352
Control4=IDC_COMBO1,combobox,1344340226
Control5=IDC_STATIC_TERM,static,1342308352
Control6=IDC_COMBO2,combobox,1344340226

[CLS:CSeekDlg]
Type=0
HeaderFile=SeekDlg.h
ImplementationFile=SeekDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_SCORE_SEEK
VirtualFilter=dWC

