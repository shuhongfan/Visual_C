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
	// ɾ��ԭ�������нڵ�
	if (m_TreeCtrl.GetCount()>0) m_TreeCtrl.DeleteAllItems();

	CEx_StudentDoc* pDoc = (CEx_StudentDoc*)GetDocument();

	HTREEITEM hRoot, hSpec, hClass;
	CString strSpecial, strClass;
	hRoot = m_TreeCtrl.InsertItem("ѧ����Ϣ",0,1);
	for (int nIndex = 0; nIndex < pDoc->GetAllRecNum(); nIndex++) {
		strSpecial = pDoc->GetStudentInfoAt(nIndex)->strSpecial;
		strClass = pDoc->GetStudentInfoAt(nIndex)->strNO.Left(6);
		// ѧ�ŵ�ǰ6λ�ǰ༶��
		hSpec = FindTreeItem( m_TreeCtrl, hRoot, strSpecial);	
		// �����Ƿ����ظ���רҵ�ڵ�
		if (hSpec == NULL)	// ��û���ظ���רҵ�ڵ�
			hSpec = m_TreeCtrl.InsertItem( strSpecial, 0, 1, hRoot);
		hClass = FindTreeItem( m_TreeCtrl, hSpec, strClass);	
		// �����Ƿ����ظ��İ༶�ڵ�
		if (hClass == NULL)	// ��û���ظ��İ༶�ڵ�
			hClass = m_TreeCtrl.InsertItem(strClass, 0, 1, hSpec);
	}
}

void CStudentTreeView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if (lHint == 1)		// �Ǵ�����б���ͼ���ݹ�������Ϣ
		ResetTreeItem();	
}

void CStudentTreeView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	UINT uFlags;
	CTreeCtrl& m_TreeCtrl = GetTreeCtrl();
	HTREEITEM hSel = m_TreeCtrl.HitTest(point, &uFlags);	
	// ���������Ƿ�һ���ڵ�����ǣ�ѡ�иýڵ�
	if ((hSel != NULL) && (TVHT_ONITEM & uFlags))
	{
		m_TreeCtrl.SelectItem(hSel);
	} else {
		CTreeView::OnLButtonDown(nFlags, point);
		return;
	}
	CString strSelItem;
	strSelItem = m_TreeCtrl.GetItemText( hSel );
	int nHint;		// 1��ʾ��ѧ����Ϣ����2��ʾ��רҵ����3��ʾ�༶
	// ������еĽڵ�û���ӽڵ㣬��˵���ýڵ��ǰ༶�Žڵ�
	if (m_TreeCtrl.GetChildItem(hSel) == NULL)
		nHint = 3;
	else
		if (strSelItem == "ѧ����Ϣ" )
			nHint = 1;
		else
			nHint = 2;
	GetDocument()->UpdateAllViews( NULL, nHint, (CObject *)new CString(strSelItem));
}
