// Ex_NETDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_NET.h"
#include "Ex_NETDlg.h"

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
// CEx_NETDlg dialog

CEx_NETDlg::CEx_NETDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEx_NETDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEx_NETDlg)
	m_strPassword = _T("");
	m_strURL = _T("");
	m_strUserName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx_NETDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_NETDlg)
	DDX_Control(pDX, IDC_LIST_CONTENT, m_List);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
	DDX_Text(pDX, IDC_EDIT_URL, m_strURL);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strUserName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEx_NETDlg, CDialog)
	//{{AFX_MSG_MAP(CEx_NETDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_HTTP, OnRadioHttp)
	ON_BN_CLICKED(IDC_RADIO_FTP, OnRadioFtp)
	ON_BN_CLICKED(IDC_BUTTON_DO, OnButtonDo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_NETDlg message handlers

BOOL CEx_NETDlg::OnInitDialog()
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
	
	CheckRadioButton( IDC_RADIO_HTTP,  IDC_RADIO_FTP,  IDC_RADIO_HTTP);
	OnRadioHttp();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEx_NETDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEx_NETDlg::OnPaint() 
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
HCURSOR CEx_NETDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEx_NETDlg::OnRadioHttp() 
{
	m_bFTP = FALSE;
	GetDlgItem(IDC_EDIT_USERNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(FALSE);
}

void CEx_NETDlg::OnRadioFtp() 
{
	m_bFTP = TRUE;
	GetDlgItem(IDC_EDIT_USERNAME)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_PASSWORD)->EnableWindow(TRUE);
}

void CEx_NETDlg::DoQueryHTTP()
{
	CInternetSession* pSession;
	CString head = "http://";
	CInternetFile* pFile = NULL;

	// ����CInternetSession��Ķ���
	pSession = new CInternetSession;
	// ��ʾ��Ϣ
	m_List.AddString("��ʼHTTP��ѯ...");
	m_List.AddString("��ͼ����HTTPվ��: " + m_strURL);
	
	// ��HTTPվ��
	pFile = (CInternetFile*)pSession->OpenURL(head + m_strURL);
	if (pFile){		// ��ȡ�ļ��ɹ�
		m_List.AddString("��HTTPվ��������Ѿ�������");
		m_List.AddString("���ݣ�");

		CString strLine;
		// ��ʾ�ļ�����
		for (int i=0;pFile->ReadString(strLine);i++)
			m_List.AddString(strLine);
		
		pFile->Close();		//�ر��ļ�
		delete pFile;		//ɾ���ļ�����

	}
	else
		m_List.AddString("�޷�����HTTP��������");
	m_List.AddString("----����----");
}

void CEx_NETDlg::DoQueryFTP()
{
	CInternetSession* pSession;
	CFtpConnection* pConnection = NULL;

	// ����CInternetSession��Ķ���
	pSession = new CInternetSession;
	// ��ʾ��Ϣ
	m_List.AddString("��ʼFTP��ѯ...");
	m_List.AddString("��ͼ����FTPվ��: " + m_strURL);
	
	// ������FTP������������
	pConnection = pSession->GetFtpConnection(m_strURL,m_strUserName,m_strPassword);

	if (pConnection) {		// �ɹ�����FTP����
		m_List.AddString("��FTPվ��������Ѿ�������");
		m_List.AddString("");
		CString strLine;
		// ���FTP������ȱʡĿ¼��
		pConnection->GetCurrentDirectory(strLine);
		m_List.AddString("FTP������ȱʡĿ¼: "+ strLine);
		pConnection->Close();	// �ر���FTP������������
		delete pConnection;		//ɾ�����������
	} else
		m_List.AddString("�޷�����FTP��������");

	m_List.AddString("----����----");
}

void CEx_NETDlg::OnButtonDo() 
{
	UpdateData();
	m_strURL.TrimLeft();
	if (m_strURL.IsEmpty()) {
		MessageBox("��ַ��IP����Ϊ�գ�");
		return;
	}
	// ����б��ԭ������ʾ����
	while(m_List.GetCount()!=0)
		m_List.DeleteString(0);

	if (m_bFTP)
		DoQueryFTP();
	else
		DoQueryHTTP();
}
