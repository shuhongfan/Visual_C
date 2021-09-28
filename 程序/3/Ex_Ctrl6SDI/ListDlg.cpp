// ListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Ctrl6SDI.h"
#include "ListDlg.h"
#include "StuInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListDlg dialog


CListDlg::CListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CListDlg, CDialog)
	//{{AFX_MSG_MAP(CListDlg)
	ON_BN_CLICKED(IDC_RADIO_LARGE, OnRadioLarge)
	ON_BN_CLICKED(IDC_RADIO_SMALL, OnRadioSmall)
	ON_BN_CLICKED(IDC_RADIO_LIST, OnRadioList)
	ON_BN_CLICKED(IDC_RADIO_REPORT, OnRadioReport)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListDlg message handlers

void CListDlg::SetCtrlStyle(HWND hWnd, DWORD dwNewStyle)
{
	DWORD	dwOldStyle;
	dwOldStyle = GetWindowLong(hWnd, GWL_STYLE);		// 获取当前风格
	if ((dwOldStyle&LVS_TYPEMASK) != dwNewStyle) 
	{
		dwOldStyle &= ~LVS_TYPEMASK;
		dwNewStyle |= dwOldStyle;
		SetWindowLong(hWnd, GWL_STYLE, dwNewStyle);		// 设置新风格
	}
}

BOOL CListDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 设置单选按钮组初始选中状态
	CheckRadioButton(IDC_RADIO_LARGE, IDC_RADIO_REPORT, IDC_RADIO_REPORT);
	// 将列表控件设置为“报表”显示方式
	SetCtrlStyle( m_ListCtrl.m_hWnd, LVS_REPORT );
	// 创建列表控件的标题头
	CString strHeader[5]={"学号", "姓名",  "性别", "出生年月", "专业"};
	int nWidth[5] = {80, 100, 60, 100, 200};
	for (int nCol=0; nCol<5; nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nWidth[nCol]);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CListDlg::OnRadioLarge() 
{
	// TODO: Add your control notification handler code here
	SetCtrlStyle( m_ListCtrl.m_hWnd, LVS_ICON );
	
}

void CListDlg::OnRadioSmall() 
{
	// TODO: Add your control notification handler code here
	SetCtrlStyle( m_ListCtrl.m_hWnd, LVS_SMALLICON );
	
}

void CListDlg::OnRadioList() 
{
	// TODO: Add your control notification handler code here
	SetCtrlStyle( m_ListCtrl.m_hWnd, LVS_LIST );
	
}

void CListDlg::OnRadioReport() 
{
	// TODO: Add your control notification handler code here
	SetCtrlStyle( m_ListCtrl.m_hWnd, LVS_REPORT );
	
}

void CListDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	CStuInfoDlg dlg;
	if (IDOK != dlg.DoModal()) return;

	// 根据学号来判断学生基本信息是不是已经添加过
	LVFINDINFO info;
	info.flags = LVFI_PARTIAL|LVFI_STRING;
	info.psz = dlg.m_strNo;
	if (m_ListCtrl.FindItem( &info ) != -1) // 若找到
	{
		CString str;
		str.Format("学号为%s的学生基本信息已添加过！", dlg.m_strNo);
		MessageBox(str);
		return;
	}
	// 添加学生基本信息
	int nIndex = m_ListCtrl.InsertItem(m_ListCtrl.GetItemCount(), dlg.m_strNo);
	m_ListCtrl.SetItemText( nIndex, 1, dlg.m_strName );
	if (dlg.m_bMale)
		m_ListCtrl.SetItemText( nIndex, 2, "男" );
	else
		m_ListCtrl.SetItemText( nIndex, 2, "女" );
	m_ListCtrl.SetItemText( nIndex, 3, dlg.m_tBirth.Format("%Y-%m-%d"));
	m_ListCtrl.SetItemText( nIndex, 4, dlg.m_strSpecial);
}
