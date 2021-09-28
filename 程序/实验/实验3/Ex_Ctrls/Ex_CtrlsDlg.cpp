// Ex_CtrlsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Ctrls.h"
#include "Ex_CtrlsDlg.h"

#include "CourseDlg.h"
#include "StuInfoDlg.h"

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
	m_nBlue = 0;
	m_nGreen = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx_CtrlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_CtrlsDlg)
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_sliderGreen);
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_sliderBlue);
	DDX_Control(pDX, IDC_SCROLLBAR_RED, m_scrollRed);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Slider(pDX, IDC_SLIDER_BLUE, m_nBlue);
	DDX_Slider(pDX, IDC_SLIDER_GREEN, m_nGreen);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEx_CtrlsDlg, CDialog)
	//{{AFX_MSG_MAP(CEx_CtrlsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_COURSE, OnButtonCourse)
	ON_BN_CLICKED(IDC_BUTTON_STUINFO, OnButtonStuinfo)
	ON_WM_VSCROLL()
	ON_WM_CTLCOLOR()
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
	m_scrollRed.SetScrollRange(0, 255);
	m_sliderBlue.SetRange(0, 255);
	m_sliderGreen.SetRange(0, 255);
	m_nBlue = m_nGreen = m_nRed = 192;
	UpdateData( FALSE );
	m_scrollRed.SetScrollPos(m_nRed);
	
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
	// ����б��ԭ������ʾ����
	while(m_List.GetCount()!=0)	m_List.DeleteString(0);
	CString strSex("Ů");
	if (dlg.m_bMale) strSex = "��";
	m_List.AddString( "������"+dlg.m_strName);
	m_List.AddString( "ѧ�ţ�"+dlg.m_strNo);
	m_List.AddString( "�Ա�"+strSex);
	m_List.AddString( "רҵ��"+dlg.m_strSpecial);
}
*/
void CEx_CtrlsDlg::OnButtonCourse() 
{
	// TODO: Add your control notification handler code here
	CCourseDlg dlg;
	if (IDOK != dlg.DoModal()) return;
	// ����б��ԭ������ʾ����
	while(m_List.GetCount()!=0)
		m_List.DeleteString(0);
	m_List.AddString( "�� �� �ţ�"+dlg.m_strNO);
	m_List.AddString( "�γ����ƣ�"+dlg.m_strName);
	m_List.AddString( "����רҵ��"+dlg.m_strSpecial);
	m_List.AddString( "�γ����ͣ�"+dlg.m_strType);
	CString str;
	str.Format("����ѧ�ڣ�%d", dlg.m_nOpen );
	m_List.AddString( str );
	str.Format("�� ʱ ����%d", dlg.m_nHours );
	m_List.AddString( str );
	str.Format("ѧ    �֣�%4.1f", dlg.m_fCredit);
	m_List.AddString( str );	
}

void CEx_CtrlsDlg::OnButtonStuinfo() 
{
	// TODO: Add your control notification handler code here
	CStuInfoDlg dlg;
	if (IDOK != dlg.DoModal()) return;
	// ����б��ԭ������ʾ����
	while(m_List.GetCount()!=0)	m_List.DeleteString(0);
	CString strSex("Ů");
	if (dlg.m_bMale) strSex = "��";
	m_List.AddString( "������"+dlg.m_strName);
	m_List.AddString( "ѧ�ţ�"+dlg.m_strNo);
	m_List.AddString( "�Ա�"+strSex);
	m_List.AddString( "�������£�"+dlg.m_tBirth.Format("%Y-%m-%d"));
	m_List.AddString( "��ѧרҵ��"+dlg.m_strSpecial);
	
}

void CEx_CtrlsDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	int nID = pScrollBar->GetDlgCtrlID();		// ��ȡ�Ի����пؼ�ID��
	if (nID == IDC_SCROLLBAR_RED) {		// ���ǹ�����������ˮƽ������Ϣ
		switch(nSBCode){
			case SB_LINEUP:	m_nRed--;		// ������������߼�ͷ
								break;
			case SB_LINEDOWN:	m_nRed++;		// �����������ұ߼�ͷ
								break;
			case SB_PAGEUP:	m_nRed -= 10;	
								break;
			case SB_PAGEDOWN:	m_nRed += 10;	
								break;
			case SB_THUMBTRACK:	m_nRed = nPos;	
								break;
		}
		if (m_nRed<0) m_nRed = 0;
		if (m_nRed>255) m_nRed = 255;
		m_scrollRed.SetScrollPos(m_nRed);
	}
	Invalidate();		// ʹ�Ի�����Ч��ǿ��ϵͳ�ػ�Ի���
	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

HBRUSH CEx_CtrlsDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	UpdateData(TRUE);
	COLORREF color = RGB(m_nRed, m_nGreen, m_nBlue);
	m_Brush.Detach();				// ʹ��ˢ�Ͷ������
	m_Brush.CreateSolidBrush(color);		// ������ɫ��ˢ
	pDC->SetBkColor( color );			// ���ñ�����ɫ
	return (HBRUSH)m_Brush;			// ���ػ�ˢ������Ա�ϵͳʹ�˻�ˢ���ƶԻ���
	
	// TODO: Return a different brush if the default is not desired
//	return hbr;
}
