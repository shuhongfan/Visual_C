// StudentTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Student.h"
#include "StudentTreeView.h"

#include "Ex_StudentDoc.h"

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

void CStudentTreeView::ResetTreeItem()
{
	CTreeCtrl& m_TreeCtrl = GetTreeCtrl();
	// 删除原来的所有节点
	if (m_TreeCtrl.GetCount()>0) m_TreeCtrl.DeleteAllItems();

	CEx_StudentDoc* pDoc = (CEx_StudentDoc*)GetDocument();

	HTREEITEM hRoot, hSpec, hClass;
	CString strSpecial, strClass;
	hRoot = m_TreeCtrl.InsertItem("学生信息",0,1);
	for (int nIndex = 0; nIndex < pDoc->GetAllRecNum(); nIndex++) {
		strSpecial = pDoc->GetStudentInfoAt(nIndex)->strSpecial;
		strClass = pDoc->GetStudentInfoAt(nIndex)->strNO.Left(6);
		// 学号的前6位是班级号
		hSpec = FindTreeItem( m_TreeCtrl, hRoot, strSpecial);	
		// 查找是否有重复的专业节点
		if (hSpec == NULL)	// 若没有重复的专业节点
			hSpec = m_TreeCtrl.InsertItem( strSpecial, 0, 1, hRoot);
		hClass = FindTreeItem( m_TreeCtrl, hSpec, strClass);	
		// 查找是否有重复的班级节点
		if (hClass == NULL)	// 若没有重复的班级节点
			hClass = m_TreeCtrl.InsertItem(strClass, 0, 1, hSpec);
	}
}

void CStudentTreeView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if (lHint == 1)		// 是从左边列表视图传递过来的消息
		ResetTreeItem();	
}

void CStudentTreeView::OnLButtonDown(UINT nFlags, CPoint point) 
{
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
	CString strSelItem;
	strSelItem = m_TreeCtrl.GetItemText( hSel );
	int nHint;		// 1表示“学生信息”，2表示“专业”，3表示班级
	// 如果击中的节点没有子节点，那说明该节点是班级号节点
	if (m_TreeCtrl.GetChildItem(hSel) == NULL)
		nHint = 3;
	else
		if (strSelItem == "学生信息" )
			nHint = 1;
		else
			nHint = 2;
	GetDocument()->UpdateAllViews( NULL, nHint, (CObject *)new CString(strSelItem));
}
