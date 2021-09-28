// StudentTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Student.h"
#include "StudentTreeView.h"

#include "Ex_StudentDoc.h"

#include "StudentSet.h"
#include "StatScoreDlg.h"


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
	m_bEnableAnalyze = FALSE;
}

CStudentTreeView::~CStudentTreeView()
{
}


BEGIN_MESSAGE_MAP(CStudentTreeView, CTreeView)
	//{{AFX_MSG_MAP(CStudentTreeView)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_SEL_ANALYZE, OnSelAnalyze)
	ON_UPDATE_COMMAND_UI(ID_SEL_ANALYZE, OnUpdateSelAnalyze)
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

void CStudentTreeView::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CTreeCtrl& m_TreeCtrl = GetTreeCtrl();
	m_ImageList.Create(16, 16, ILC_COLOR8 | ILC_MASK, 2, 1);
	m_TreeCtrl.SetImageList( &m_ImageList, TVSIL_NORMAL );
	SHFILEINFO fi;		// ����һ���ļ���Ϣ�ṹ����
	SHGetFileInfo("C:\\Windows", 0, &fi, sizeof(SHFILEINFO),
		SHGFI_ICON | SHGFI_SMALLICON);	// ��ȡ�ļ���ͼ��
	m_ImageList.Add( fi.hIcon );
	SHGetFileInfo("C:\\Windows", 0, &fi, sizeof(SHFILEINFO),
		SHGFI_ICON | SHGFI_SMALLICON | SHGFI_OPENICON);	// ��ȡ���ļ���ͼ��
	m_ImageList.Add( fi.hIcon );
	ResetTreeItem();	
}

void CStudentTreeView::ResetTreeItem()
{
	CTreeCtrl& m_TreeCtrl = GetTreeCtrl();
	if (m_TreeCtrl.GetCount()>0)
		m_TreeCtrl.DeleteAllItems();

	HTREEITEM hRoot, hSpec, hClass;
	CString strRoot[3] = {"ѧ����Ϣ", "�γ���Ϣ", "ѧ���ɼ�"};

	for ( int nRoot=0; nRoot<3; nRoot++ )
	{
		hRoot = m_TreeCtrl.InsertItem(strRoot[nRoot],0,1);

		CStudentSet sSet;
		sSet.m_strSort = "special";	// ��רҵ����
		sSet.Open();
		while (!sSet.IsEOF())
		{
			hSpec = FindTreeItem( m_TreeCtrl, hRoot, sSet.m_special);	
			// �����Ƿ����ظ���רҵ�ڵ�
			if (hSpec == NULL)	// ��û���ظ���רҵ�ڵ�
				hSpec = m_TreeCtrl.InsertItem( sSet.m_special, 0, 1, hRoot);
			if (nRoot != 1)
			{
				hClass = FindTreeItem( m_TreeCtrl, hSpec, sSet.m_studentno.Left(6));	
				// �����Ƿ����ظ��İ༶�ڵ�
				if (hClass == NULL)	// ��û���ظ��İ༶�ڵ�
					hClass = m_TreeCtrl.InsertItem(sSet.m_studentno.Left(6), 0, 1, hSpec);
				//m_TreeCtrl.InsertItem(sSet.m_studentno, hClass);			
			}
			sSet.MoveNext();
		}
		sSet.Close();
	}
}

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

void CStudentTreeView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (lHint == 1)
		ResetTreeItem();	
}

void CStudentTreeView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CEx_StudentDoc* pDoc = (CEx_StudentDoc*)GetDocument();
	pDoc->m_nViewPos = 1;

	m_bEnableAnalyze = FALSE;

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

	CString strSelItem, strParentItem;
	strSelItem = m_TreeCtrl.GetItemText( hSel );

	HTREEITEM hParent = hSel;
	BOOL bIsClass = FALSE;
	if ((m_TreeCtrl.GetChildItem(hSel) == NULL) && (atol(strSelItem)>0))	
	{
		hParent = m_TreeCtrl.GetParentItem( hSel );
		bIsClass = TRUE;
	}
	hParent = m_TreeCtrl.GetParentItem( hParent );
	strParentItem = m_TreeCtrl.GetItemText( hParent );

	int nHint = 0;

	if (strParentItem.IsEmpty()) 
	{
		nHint = 13;
		strParentItem = strSelItem;
	} else
	{
		nHint = 12;
		if (bIsClass) nHint = 11;
	}
		
	if (strParentItem == "ѧ����Ϣ")
		pDoc->m_nInfoType = 1;
	if (strParentItem == "�γ���Ϣ")
		pDoc->m_nInfoType = 2;
	if (strParentItem == "ѧ���ɼ�")
	{
		pDoc->m_nInfoType = 3;
		if (nHint == 11) {
			m_bEnableAnalyze = TRUE;
			m_strClass = strSelItem;
		}
	}

	GetDocument()->UpdateAllViews( NULL, nHint, (CObject *)new CString(strSelItem) );
}

void CStudentTreeView::OnSelAnalyze() 
{
	// TODO: Add your command handler code here
	CStatScoreDlg dlg;
	dlg.m_strClass = m_strClass;
	dlg.DoModal();
}

void CStudentTreeView::OnUpdateSelAnalyze(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable( m_bEnableAnalyze ); 
}
