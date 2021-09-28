// Ex_ChatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Chat.h"
#include "Ex_ChatDlg.h"

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
// CEx_ChatDlg dialog

CEx_ChatDlg::CEx_ChatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEx_ChatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEx_ChatDlg)
	m_strMsg = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx_ChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_ChatDlg)
	DDX_Control(pDX, IDC_LIST_MSG, m_listMsg);
	DDX_Control(pDX, IDC_COMBO_TYPE, m_comboType);
	DDX_Text(pDX, IDC_EDIT_MSG, m_strMsg);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEx_ChatDlg, CDialog)
	//{{AFX_MSG_MAP(CEx_ChatDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_TYPE, OnSelchangeComboType)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_RUN, OnButtonRun)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ChatDlg message handlers

BOOL CEx_ChatDlg::OnInitDialog()
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
	m_comboType.AddString("服务器");
	m_comboType.AddString("客户机");
	m_comboType.SetCurSel(0);
	OnSelchangeComboType();
	m_asServer.m_pDlg = this;
	m_asClient.m_pDlg = this;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEx_ChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEx_ChatDlg::OnPaint() 
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
HCURSOR CEx_ChatDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEx_ChatDlg::OnSelchangeComboType() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_comboType.GetCurSel();
	if ( nIndex == CB_ERR) return;
	CString str;
	m_comboType.GetLBText( nIndex, str );
	if (str == "服务器"){
		m_bServer = TRUE;
		GetDlgItem(IDC_BUTTON_RUN)->SetWindowText("运行");
	} else {
		m_bServer = FALSE;
		GetDlgItem(IDC_BUTTON_RUN)->SetWindowText("连接");
	}
	GetDlgItem(IDCANCEL)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
}

void CEx_ChatDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if (m_bServer)
		m_asServer.Close();
	else
		m_asClient.Close();
	OnCancel();
	CDialog::OnClose();
}

void CEx_ChatDlg::OnButtonRun() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_COMBO_TYPE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_RUN)->EnableWindow(FALSE);
	if (m_bServer){		// 如果是服务器
		m_asServer.Create( 1000 );		 // 创建服务器，端口号为1000
		m_asServer.Listen();	 // 侦听
	} else {			// 如果客户机
		m_asClient.Create();
		m_asClient.Connect( "localhost", 1000);	
		// 连接，与服务器端口号相同，服务器地址设为"lacalhost"
	}
}

void CEx_ChatDlg::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if (m_strMsg.IsEmpty())	{
		MessageBox("不能发送空消息！");
		return;
	}
	char *pBuf = new char[1025];
	int nBufSize = 1024;
	int nLen = m_strMsg.GetLength();
	int nRes = m_asClient.Send( LPCTSTR(m_strMsg), nLen ); 
	if (nRes == SOCKET_ERROR ) {
		AfxMessageBox("消息发送失败！");
		return;
	}
	if (m_bServer){		// 如果是服务器发送的消息
		m_listMsg.AddString( "从服务器发送的消息：" );
		m_listMsg.AddString( m_strMsg );
		// 客户机接收到消息
	} else {			// 如果是客户机发送的消息
		m_listMsg.AddString( "从客户机发送的消息：" );
		m_listMsg.AddString( m_strMsg );
	}
	m_strMsg.Empty();
	UpdateData( FALSE );
}

void CEx_ChatDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	OnClose();
	//CDialog::OnCancel();
}

void CEx_ChatDlg::OnAccept()
{
	m_asServer.Accept( m_asClient);
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
}

void CEx_ChatDlg::OnReceive()
{
	char *pBuf = new char[1025];
	int nBufSize = 1024;
	CString strReceived;

	int nRes = m_asClient.Receive(pBuf,nBufSize);
	if (nRes == SOCKET_ERROR)
	{
		AfxMessageBox("无法接收消息！");
		return;
	}
		
	pBuf[nRes] = NULL;
	strReceived = pBuf;
	if (m_bServer){		// 如果是来自客户机发送发送的消息
		m_listMsg.AddString( "来自客户机发送的消息：" );
		m_listMsg.AddString( strReceived );
		// 客户机接收到消息
	} else {			// 如果是来自服务器发送的消息
		m_listMsg.AddString( "来自服务器发送的消息：" );
		m_listMsg.AddString( strReceived );
	}
}

void CEx_ChatDlg::OnConnect()
{
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
	GetDlgItem(IDCANCEL)->EnableWindow(TRUE);
}

void CEx_ChatDlg::DoClose()
{
	OnClose();
}
