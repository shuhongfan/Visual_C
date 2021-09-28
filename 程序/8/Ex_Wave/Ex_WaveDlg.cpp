// Ex_WaveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Wave.h"
#include "Ex_WaveDlg.h"

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
// CEx_WaveDlg dialog

CEx_WaveDlg::CEx_WaveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEx_WaveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEx_WaveDlg)
	m_strFileName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx_WaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_WaveDlg)
	DDX_Control(pDX, IDC_STOP, m_btnStop);
	DDX_Control(pDX, IDC_PLAY, m_btnPlay);
	DDX_Control(pDX, IDC_FILE, m_btnFile);
	DDX_Text(pDX, IDC_DISPFILE, m_strFileName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEx_WaveDlg, CDialog)
	//{{AFX_MSG_MAP(CEx_WaveDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FILE, OnFile)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
	ON_MESSAGE(MM_MCINOTIFY,OnMCINotify)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_WaveDlg message handlers

BOOL CEx_WaveDlg::OnInitDialog()
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

void CEx_WaveDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEx_WaveDlg::OnPaint() 
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
HCURSOR CEx_WaveDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEx_WaveDlg::OnFile() 
{
	// TODO: Add your control notification handler code here
	CString filter;
	filter = "波形音频文件(*.wav)|*.wav||";

	CFileDialog dlg (TRUE, NULL, NULL, OFN_HIDEREADONLY, filter);
	if (dlg.DoModal () == IDOK)
	{
		CString str;
		str = dlg.GetPathName();
		if (m_wave.Open(str)){
			m_btnPlay.EnableWindow(TRUE);
			m_btnPlay.SetFocus();
			m_strFileName = str;
			UpdateData( FALSE );
		}else 
			MessageBox(str+"文件打不开或操作失败！");
	}
}

void CEx_WaveDlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	if (m_wave.Play(this)){
		m_btnPlay.EnableWindow(FALSE);	// 禁用[播放]按钮
		m_btnFile.EnableWindow(FALSE);	// 禁用[波形文件]按钮
		m_btnStop.EnableWindow(TRUE);
		m_btnStop.SetFocus();
	}	
}

void CEx_WaveDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	m_wave.Stop();
	m_btnPlay.EnableWindow(TRUE);
	m_btnFile.EnableWindow(TRUE);
	m_btnStop.EnableWindow(FALSE);		// 禁用[停止]按钮
	m_btnPlay.SetFocus();
}

LRESULT CEx_WaveDlg::OnMCINotify(WPARAM wParam, LPARAM lParam)
{
	OnStop();
	return FALSE;
}
