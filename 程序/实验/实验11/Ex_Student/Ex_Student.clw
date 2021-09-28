; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStatDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ex_student.h"
LastPage=0

ClassCount=17
Class1=CCourseDlg
Class2=CCourseSet
Class3=CEx_StudentApp
Class4=CAboutDlg
Class5=CEx_StudentDoc
Class6=CEx_StudentView
Class7=CMainFrame
Class8=CScoreDlg
Class9=CScoreSet
Class10=CSeekDlg
Class11=CSpecialDlg
Class12=CSpecialSet
Class13=CStatDlg
Class14=CStatScoreDlg
Class15=CStudentSet
Class16=CStudentTreeView
Class17=CStuInfoDlg

ResourceCount=9
Resource1=IDD_DIALOG_SEEK
Resource2=IDR_MAINFRAME
Resource3=IDD_STAT_SCORE
Resource4=IDD_DIALOG_STAT
Resource5=IDD_SCORE_TABLE
Resource6=IDD_STUINFO
Resource7=IDD_COURSEINFO
Resource8=IDD_ABOUTBOX
Resource9=IDD_DIALOG_SPECIAL

[CLS:CCourseDlg]
Type=0
BaseClass=CDialog
HeaderFile=CourseDlg.h
ImplementationFile=CourseDlg.cpp

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

[CLS:CScoreSet]
Type=0
HeaderFile=ScoreSet.h
ImplementationFile=ScoreSet.cpp

[CLS:CSeekDlg]
Type=0
BaseClass=CDialog
HeaderFile=SeekDlg.h
ImplementationFile=SeekDlg.cpp

[CLS:CSpecialDlg]
Type=0
BaseClass=CDialog
HeaderFile=SpecialDlg.h
ImplementationFile=SpecialDlg.cpp
LastObject=IDC_BUTTON_ADD

[CLS:CSpecialSet]
Type=0
HeaderFile=SpecialSet.h
ImplementationFile=SpecialSet.cpp

[CLS:CStatDlg]
Type=0
BaseClass=CDialog
HeaderFile=StatDlg.h
ImplementationFile=StatDlg.cpp

[CLS:CStatScoreDlg]
Type=0
BaseClass=CDialog
HeaderFile=StatScoreDlg.h
ImplementationFile=StatScoreDlg.cpp
LastObject=IDC_STATIC_OPEN

[CLS:CStudentSet]
Type=0
HeaderFile=StudentSet.h
ImplementationFile=StudentSet.cpp

[CLS:CStudentTreeView]
Type=0
BaseClass=CTreeView
HeaderFile=StudentTreeView.h
ImplementationFile=StudentTreeView.cpp

[CLS:CStuInfoDlg]
Type=0
BaseClass=CDialog
HeaderFile=StuInfoDlg.h
ImplementationFile=StuInfoDlg.cpp

[DB:CCourseSet]
DB=1

[DB:CScoreSet]
DB=1

[DB:CSpecialSet]
DB=1

[DB:CStudentSet]
DB=1

[DLG:IDD_COURSEINFO]
Type=1
Class=CCourseDlg
ControlCount=19
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
Control16=IDC_COMBO_SPECIAL1,combobox,1344340226
Control17=IDC_EDIT_OPEN,edit,1350631552
Control18=IDC_SPIN1,msctls_updown32,1342177334
Control19=IDC_BUTTON_SPECIAL,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SCORE_TABLE]
Type=1
Class=CScoreDlg
ControlCount=21
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STUNO,edit,1350631552
Control8=IDC_COURSENO,edit,1350631552
Control9=IDC_SCORE,edit,1350631552
Control10=IDC_CREDIT,edit,1350631552
Control11=IDC_STATIC,static,1342177297
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_NO,combobox,1344340226
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC_NAME,static,1342312961
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC_HOURS,static,1342312961
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC_OPEN,static,1342312961
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC_SPECIAL,static,1342312961

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

[DLG:IDD_DIALOG_SPECIAL]
Type=1
Class=CSpecialDlg
ControlCount=8
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_LIST1,listbox,1352728835
Control4=IDC_EDIT_SPECIAL,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BUTTON_ADD,button,1342242816
Control7=IDC_BUTTON_CHANGE,button,1342242816
Control8=IDC_BUTTON_DEL,button,1342242816

[DLG:IDD_DIALOG_STAT]
Type=1
Class=CStatDlg
ControlCount=7
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC_NUM,static,1342312961
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC_NO,static,1342312961
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COMBO1,combobox,1344340226

[DLG:IDD_STAT_SCORE]
Type=1
Class=CStatScoreDlg
ControlCount=11
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON_DISP,button,1342242816
Control3=65535,static,1342308352
Control4=IDC_COMBO_COURSENO,combobox,1344340226
Control5=65535,static,1342308352
Control6=IDC_STATIC_COURSE,static,1342312961
Control7=IDC_DRAW,static,1342312961
Control8=65535,static,1342308352
Control9=IDC_STATIC_CREDIT2,static,1342312961
Control10=65535,static,1342308352
Control11=IDC_STATIC_OPEN,static,1342312961

[DLG:IDD_STUINFO]
Type=1
Class=CStuInfoDlg
ControlCount=17
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
Control14=IDC_BUTTON_PHOTO,button,1342242816
Control15=IDC_DRAW,static,1342312961
Control16=IDC_COMBO_SPECIAL,combobox,1344340226
Control17=IDC_BUTTON_SPECIAL1,button,1342242816

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_OP_ADD
Command2=ID_OP_CHANGE
Command3=ID_OP_DEL
Command4=ID_FILE_PRINT
Command5=ID_FILE_PRINT_PREVIEW
Command6=ID_FILE_PRINT_SETUP
Command7=ID_APP_EXIT
Command8=ID_SEL_SEEK
Command9=ID_SEL_STAT
Command10=ID_SEL_ANALYZE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_OP_ADD
Command2=ID_OP_DEL
Command3=ID_OP_CHANGE
Command4=ID_SEL_SEEK
Command5=ID_SEL_STAT
Command6=ID_SEL_ANALYZE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

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

