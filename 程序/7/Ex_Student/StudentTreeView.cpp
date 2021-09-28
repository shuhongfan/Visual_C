// StudentTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Student.h"
#include "StudentTreeView.h"
#include "StudentSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentTreeView

IMPLEMENT_DYNCREATE(CStudentTreeView, CTreeView)

CStudentTreeView::CStudentTreeView()
{
}

CStudentTreeView::~CStudentTreeView()
{
}


BEGIN_MESSAGE_MAP(CStudentTreeView, CTreeView)
	//{{AFX_MSG_MAP(CStudentTreeView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentTreeView drawing

void CStudentTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CStudentTreeView diagnostics

#ifdef _DEBUG
void CStudentTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CStudentTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStudentTreeView message handlers

BOOL CStudentTreeView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style |= (TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS );
	return CTreeView::PreCreateWindow(cs);
}

HTREEITEM CStudentTreeView::FindTreeItem(CTreeCtrl &treeCtrl, HTREEITEM hParent, CString str)
{
	HTREEITEM hNext;
	CString strItem;

	hNext = treeCtrl.GetChildItem( hParent);
	while (hNext != NULL) {
		strItem = treeCtrl.GetItemText( hNext );
		if ( strItem == str ) {
			return hNext;
		} else {
			hNext = treeCtrl.GetNextItem( hNext, TVGN_NEXT );
		}
	}
	return NULL;
}

void CStudentTreeView::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CTreeCtrl& m_TreeCtrl = GetTreeCtrl();
	m_ImageList.Create(16, 16, ILC_COLOR8 | ILC_MASK, 2, 1);
	m_TreeCtrl.SetImageList( &m_ImageList, TVSIL_NORMAL );
	SHFILEINFO fi;		// 定义一个文件信息结构变量
	SHGetFileInfo("C:\\Windows", 0, &fi, sizeof(SHFILEINFO),
		SHGFI_ICON | SHGFI_SMALLICON);	// 获取文件夹图标
	m_ImageList.Add( fi.hIcon );
	SHGetFileInfo("C:\\Windows", 0, &fi, sizeof(SHFILEINFO),
		SHGFI_ICON | SHGFI_SMALLICON | SHGFI_OPENICON);	// 获取打开文件夹图标
	m_ImageList.Add( fi.hIcon );

	HTREEITEM hRoot, hSpec, hClass;
	hRoot = m_TreeCtrl.InsertItem("学生成绩",0,1);
	CStudentSet sSet;
	sSet.m_strSort = "special";	// 按专业排序
	sSet.Open();
	while (!sSet.IsEOF()){
		hSpec = FindTreeItem( m_TreeCtrl, hRoot, sSet.m_special);	
		// 查找是否有重复的专业节点
		if (hSpec == NULL)	// 若没有重复的专业节点
			hSpec = m_TreeCtrl.InsertItem( sSet.m_special, 0, 1, hRoot);
		hClass = FindTreeItem( m_TreeCtrl, hSpec, sSet.m_studentno.Left(6));	
		// 查找是否有重复的班级节点
		if (hClass == NULL)	// 若没有重复的班级节点
			hClass = m_TreeCtrl.InsertItem(sSet.m_studentno.Left(6), 0, 1, hSpec);
		sSet.MoveNext();
	}
	sSet.Close();
}

void CStudentTreeView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	UINT uFlags;
	CTreeCtrl& m_TreeCtrl = GetTreeCtrl();
	HTREEITEM hSel = m_TreeCtrl.HitTest(point, &uFlags);	
	// 测试鼠标点是否一个节点项，若是，选中该节点
	if ((hSel != NULL) && (TVHT_ONITEM & uFlags))
	{
		m_TreeCtrl.SelectItem(hSel);
	} else {
		CTreeView::OnLButtonDown(nFlags, point);
		return;
	}
	// 如果击中的节点没有子节点，那说明该节点是班级号节点
	if (m_TreeCtrl.GetChildItem(hSel) == NULL)
	{
		CString strSelItem;
		strSelItem = m_TreeCtrl.GetItemText( hSel );
		GetDocument()->UpdateAllViews( NULL, 1, (CObject *)new CString(strSelItem));
	}
}
