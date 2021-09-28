// TreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Ctrl7SDI.h"
#include "TreeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeDlg dialog


CTreeDlg::CTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTreeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTreeDlg)
	DDX_Control(pDX, IDC_TREE1, m_TreeCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTreeDlg, CDialog)
	//{{AFX_MSG_MAP(CTreeDlg)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchangedTree1)
	ON_NOTIFY(NM_RCLICK, IDC_TREE1, OnRclickTree1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeDlg message handlers

void CTreeDlg::OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

BOOL CTreeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ImageList.Create(16, 16, ILC_COLOR8 | ILC_MASK, 2, 1);
	m_TreeCtrl.SetImageList( &m_ImageList, TVSIL_NORMAL );
	SHFILEINFO fi;		// 定义一个文件信息结构变量
	SHGetFileInfo("C:\\Windows", 0, &fi, sizeof(SHFILEINFO),
		SHGFI_ICON | SHGFI_SMALLICON);	// 获取文件夹图标
	m_ImageList.Add( fi.hIcon );
	SHGetFileInfo("C:\\Windows", 0, &fi, sizeof(SHFILEINFO),
		SHGFI_ICON | SHGFI_SMALLICON | SHGFI_OPENICON);	// 获取打开文件夹图标
	m_ImageList.Add( fi.hIcon );

	HTREEITEM hRoot, hParent;
	hRoot = m_TreeCtrl.InsertItem("电气与电子工程学院",0,1);
	hParent = m_TreeCtrl.InsertItem("电气工程及其自动化",hRoot);
	m_TreeCtrl.InsertItem("210101",0,1, hParent);
	hParent = m_TreeCtrl.InsertItem("机械电子工程",0,1, hRoot);
	m_TreeCtrl.InsertItem("210105",0,1, hParent);

	hRoot = m_TreeCtrl.InsertItem("数学与计算机科学学院",0,1);
	hParent = m_TreeCtrl.InsertItem("计算机应用技术",hRoot);
	m_TreeCtrl.InsertItem("160101",0,1, hParent);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTreeDlg::OnRclickTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CPoint point;		
	UINT uFlags;
	::GetCursorPos( &point );	// 获取当前鼠标所在的屏幕坐标
	m_TreeCtrl.ScreenToClient( &point );	// 将屏幕坐标转换成树控件中的客户坐标

	HTREEITEM hSel = m_TreeCtrl.HitTest(point, &uFlags);	
	// 测试鼠标点是否在一个节点项上，若是，选中该节点
	if ((hSel != NULL) && (TVHT_ONITEM & uFlags))
	{
		m_TreeCtrl.SelectItem(hSel);
		CString strItem = m_TreeCtrl.GetItemText( hSel );
		MessageBox( strItem );
	} 

	*pResult = 0;
}

