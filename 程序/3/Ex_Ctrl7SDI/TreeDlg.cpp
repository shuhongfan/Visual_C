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
	SHFILEINFO fi;		// ����һ���ļ���Ϣ�ṹ����
	SHGetFileInfo("C:\\Windows", 0, &fi, sizeof(SHFILEINFO),
		SHGFI_ICON | SHGFI_SMALLICON);	// ��ȡ�ļ���ͼ��
	m_ImageList.Add( fi.hIcon );
	SHGetFileInfo("C:\\Windows", 0, &fi, sizeof(SHFILEINFO),
		SHGFI_ICON | SHGFI_SMALLICON | SHGFI_OPENICON);	// ��ȡ���ļ���ͼ��
	m_ImageList.Add( fi.hIcon );

	HTREEITEM hRoot, hParent;
	hRoot = m_TreeCtrl.InsertItem("��������ӹ���ѧԺ",0,1);
	hParent = m_TreeCtrl.InsertItem("�������̼����Զ���",hRoot);
	m_TreeCtrl.InsertItem("210101",0,1, hParent);
	hParent = m_TreeCtrl.InsertItem("��е���ӹ���",0,1, hRoot);
	m_TreeCtrl.InsertItem("210105",0,1, hParent);

	hRoot = m_TreeCtrl.InsertItem("��ѧ��������ѧѧԺ",0,1);
	hParent = m_TreeCtrl.InsertItem("�����Ӧ�ü���",hRoot);
	m_TreeCtrl.InsertItem("160101",0,1, hParent);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTreeDlg::OnRclickTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CPoint point;		
	UINT uFlags;
	::GetCursorPos( &point );	// ��ȡ��ǰ������ڵ���Ļ����
	m_TreeCtrl.ScreenToClient( &point );	// ����Ļ����ת�������ؼ��еĿͻ�����

	HTREEITEM hSel = m_TreeCtrl.HitTest(point, &uFlags);	
	// ���������Ƿ���һ���ڵ����ϣ����ǣ�ѡ�иýڵ�
	if ((hSel != NULL) && (TVHT_ONITEM & uFlags))
	{
		m_TreeCtrl.SelectItem(hSel);
		CString strItem = m_TreeCtrl.GetItemText( hSel );
		MessageBox( strItem );
	} 

	*pResult = 0;
}

