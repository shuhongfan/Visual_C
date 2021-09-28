// Ex_CtrlsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Ctrls.h"
#include "Ex_CtrlsDlg.h"

#include "CourseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_CtrlsDlg dialog

CEx_CtrlsDlg::CEx_CtrlsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEx_CtrlsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEx_CtrlsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx_CtrlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_CtrlsDlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEx_CtrlsDlg, CDialog)
	//{{AFX_MSG_MAP(CEx_CtrlsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_COURSE, OnButtonCourse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_CtrlsDlg message handlers

BOOL CEx_CtrlsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEx_CtrlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEx_CtrlsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEx_CtrlsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/*void CEx_CtrlsDlg::OnButtonStuinfo() 
{
	// TODO: Add your control notification handler code here
	CStuInfoDlg dlg;
	if (IDOK != dlg.DoModal()) return;
	// 清除列表框原来的显示内容
	while(m_List.GetCount()!=0)	m_List.DeleteString(0);
	CString strSex("女");
	if (dlg.m_bMale) strSex = "男";
	m_List.AddString( "姓名："+dlg.m_strName);
	m_List.AddString( "学号："+dlg.m_strNo);
	m_List.AddString( "性别："+strSex);
	m_List.AddString( "专业："+dlg.m_strSpecial);
}
*/
void CEx_CtrlsDlg::OnButtonCourse() 
{
	// TODO: Add your control notification handler code here
	CCourseDlg dlg;
	if (IDOK != dlg.DoModal()) return;
	// 清除列表框原来的显示内容
	while(m_List.GetCount()!=0)
		m_List.DeleteString(0);
	m_List.AddString( "课 程 号："+dlg.m_strNO);
	m_List.AddString( "课程名称："+dlg.m_strName);
	m_List.AddString( "所属专业："+dlg.m_strSpecial);
	m_List.AddString( "课程类型："+dlg.m_strType);
	CString str;
	str.Format("开课学期：%d", dlg.m_nOpen );
	m_List.AddString( str );
	str.Format("课 时 数：%d", dlg.m_nHours );
	m_List.AddString( str );
	str.Format("学    分：%4.1f", dlg.m_fCredit);
	m_List.AddString( str );	
}
