// StuInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Student.h"		// 将Ex_MDI.h修改成Ex_Student.h
#include "StuInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg dialog


CStuInfoDlg::CStuInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStuInfoDlg::IDD, pParent)
{
	m_bMale = FALSE;
	//{{AFX_DATA_INIT(CStuInfoDlg)
	m_strName = _T("");
	m_strNo = _T("");
	m_tBirth = 0;
	m_strSpecial = _T("");
	//}}AFX_DATA_INIT
}


void CStuInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStuInfoDlg)
	DDX_Control(pDX, IDC_COMBO_SPECIAL, m_comboSpecial);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NO, m_strNo);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_tBirth);
	DDX_CBString(pDX, IDC_COMBO_SPECIAL, m_strSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStuInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CStuInfoDlg)
	ON_BN_CLICKED(IDC_RADIO_MALE, OnRadioMale)
	ON_BN_CLICKED(IDC_RADIO_FEMALE, OnRadioFemale)
	ON_BN_CLICKED(IDC_BUTTON_PHOTO, OnButtonPhoto)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg message handlers

BOOL CStuInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 设置单选按钮初始选中状态
	if (!m_bMale)
		CheckRadioButton(IDC_RADIO_MALE, IDC_RADIO_FEMALE, IDC_RADIO_FEMALE);
	else
		CheckRadioButton(IDC_RADIO_MALE, IDC_RADIO_FEMALE, IDC_RADIO_MALE);

	// 这里对专业组合框进行初如化
	m_comboSpecial.AddString( "机械工程及其自动化" );
	m_comboSpecial.AddString( "电气工程及其自动化" );
	m_strSpecial = "机械工程及其自动化";

	// 对出生年月初始化
	m_tBirth = CTime(1986, 1, 1, 0, 0, 0);
	UpdateData(FALSE);
	if (!m_strPhotoFilePath.IsEmpty())
	{
		m_hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		m_strPhotoFilePath,IMAGE_BITMAP, 0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION); 
	}
	m_bPhotoChange = FALSE;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStuInfoDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	m_strName.TrimLeft();
	m_strNo.TrimLeft();
	if (m_strName.IsEmpty())
		MessageBox("必须要有姓名！");
	else if (m_strNo.IsEmpty())
		MessageBox("必须要有学号！");
	else 
		CDialog::OnOK();
}

void CStuInfoDlg::OnRadioMale() 
{
	// TODO: Add your control notification handler code here
	m_bMale = TRUE;
}

void CStuInfoDlg::OnRadioFemale() 
{
	// TODO: Add your control notification handler code here
	m_bMale = FALSE;	
}

void CStuInfoDlg::OnButtonPhoto() 
{
	static char BASED_CODE szFilter[] = "图片文件(*.bmp)|*.bmp||";
	CFileDialog dlg( TRUE,NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
	if (IDOK != dlg.DoModal()) return;
	m_bPhotoChange = TRUE;
	m_strPhotoFilePath = dlg.GetPathName();
	m_hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		m_strPhotoFilePath,IMAGE_BITMAP, 0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION); 
	Invalidate();	// 强制对话框无效，调用OnPaint
}

void CStuInfoDlg::DrawPhoto()
{
	if(!m_hBitmap) return;	 
	CBitmap m_bmp;
    m_bmp.Attach(m_hBitmap); 
	BITMAP bm;						// 定义一个BITMAP结构变量，以便获取位图参数
	m_bmp.GetObject(sizeof(BITMAP),&bm);

	float fScale;	// 高/宽
	fScale = (float)bm.bmHeight / (float)bm.bmWidth;
	
	CWnd* pWnd = GetDlgItem(IDC_DRAW);	// 获得IDC_DRAW控件窗口指针
	CDC* pDC = pWnd->GetDC();			// 获得窗口当前的设备环境指针

	// 调整可以显示的矩形大小
	CRect rcClient;

	int nWidth, nHeight, nX = 0, nY = 0;
	pWnd->GetClientRect( rcClient );
	nWidth = rcClient.Width();
	nHeight = (int)((float)nWidth * fScale);
	nX = 0;
	nY = ( rcClient.Height() - nHeight ) / 2;
	if ( nHeight > rcClient.Height() )
	{
		nHeight = rcClient.Height();
		nWidth = (int)((float)nHeight/fScale);
		nX = ( rcClient.Width() - nWidth )/2;
		nY = 0;
	}

	CDC dcMem;						// 定义并创建一个内存设备环境
	dcMem.CreateCompatibleDC(pDC);
	CBitmap *pOldbmp = dcMem.SelectObject(&m_bmp); 	// 将位图选入内存设备环境中

	rcClient.DeflateRect(-1, -1);
	pDC->Rectangle( rcClient );
	pDC->StretchBlt(nX, nY, nWidth, nHeight, 
		&dcMem,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY);
									// 将位图复制到实际的设备环境中
	dcMem.SelectObject(pOldbmp);	// 恢复原来的内存设备环境
}

void CStuInfoDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CWnd* pWnd = GetDlgItem(IDC_DRAW);
	pWnd->UpdateWindow();

	DrawPhoto();
	
	// Do not call CDialog::OnPaint() for painting messages
}
