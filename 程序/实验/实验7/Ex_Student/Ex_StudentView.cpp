// Ex_StudentView.cpp : implementation of the CEx_StudentView class
//

#include "stdafx.h"
#include "Ex_Student.h"

#include "Ex_StudentDoc.h"
#include "Ex_StudentView.h"
#include "StuInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView

IMPLEMENT_DYNCREATE(CEx_StudentView, CListView)

BEGIN_MESSAGE_MAP(CEx_StudentView, CListView)
	//{{AFX_MSG_MAP(CEx_StudentView)
	ON_COMMAND(ID_STUINFO_ADD, OnStuinfoAdd)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView construction/destruction

CEx_StudentView::CEx_StudentView()
{
	// TODO: add construction code here

}

CEx_StudentView::~CEx_StudentView()
{
}

BOOL CEx_StudentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= LVS_REPORT;		// ������
	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView drawing

void CEx_StudentView::OnDraw(CDC* pDC)
{
	CEx_StudentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CEx_StudentView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strHeader[]={"ѧ��","����", "�Ա�", "��������", "��ѧרҵ"};
	int nLong[] = {80, 80, 60, 100, 180};
	for (int nCol=0; nCol<sizeof(strHeader)/sizeof(CString); nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nLong[nCol]);

	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView printing

BOOL CEx_StudentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_StudentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_StudentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView diagnostics

#ifdef _DEBUG
void CEx_StudentView::AssertValid() const
{
	CListView::AssertValid();
}

void CEx_StudentView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CEx_StudentDoc* CEx_StudentView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_StudentDoc)));
	return (CEx_StudentDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView message handlers

void CEx_StudentView::DispStudentInfo(CString strSpecial, CString strClass)
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	m_ListCtrl.DeleteAllItems();		// ɾ�����е��б���
	CEx_StudentDoc* pDoc = (CEx_StudentDoc*)GetDocument();
	CString strName, strNO, strSex, strBirth, strStuSpecial;
	int nItem = 0;
	for (int nIndex = 0; nIndex < pDoc->GetAllRecNum(); nIndex++) {
		strName		= pDoc->GetStudentInfoAt(nIndex)->strName;
		strNO		= pDoc->GetStudentInfoAt(nIndex)->strNO;
		if (pDoc->GetStudentInfoAt(nIndex)->bMale)
			strSex = "��";
		else
			strSex = "Ů";
		strBirth	= pDoc->GetStudentInfoAt(nIndex)->tBirth.Format("%Y-%m-%d");
		strStuSpecial = pDoc->GetStudentInfoAt(nIndex)->strSpecial;
		BOOL bAdd = FALSE;
		if (!strSpecial.IsEmpty()){		// ָ��רҵ����
			if (strStuSpecial == strSpecial)
				bAdd = TRUE;
		} else	if (!strClass.IsEmpty()) {	// ָ���༶����
			if (strNO.Left(6) == strClass)
				bAdd = TRUE;
		} else 
			bAdd = TRUE;

		if (bAdd) {
			m_ListCtrl.InsertItem( nItem, strNO );
			m_ListCtrl.SetItemText( nItem, 1, strName );
			m_ListCtrl.SetItemText( nItem, 2, strSex );
			m_ListCtrl.SetItemText( nItem, 3, strBirth );
			m_ListCtrl.SetItemText( nItem, 4, strStuSpecial );
			nItem++;
		}
	}
}

void CEx_StudentView::OnStuinfoAdd() 
{
	CStuInfoDlg dlg;
	if (dlg.DoModal() != IDOK) return;
	CEx_StudentDoc* pDoc = (CEx_StudentDoc*)GetDocument();
	// ��Ӽ�¼
	CStudentInfo *pStudent = new CStudentInfo(dlg.m_strName,
			dlg.m_strNo, dlg.m_bMale, dlg.m_tBirth, dlg.m_strSpecial);
	pDoc->m_stuObArray.Add(pStudent);
	DispStudentInfo( "", dlg.m_strNo.Left(6));	// ���༶��ʾѧ��������Ϣ
	pDoc->UpdateAllViews(NULL, 1);	// ������ͼ
}

void CEx_StudentView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	CString strHint;
	if (pHint) {
		strHint = *((CString *)pHint);
		delete (CString *)pHint;
	}
	switch ((int)lHint) {
		case 1:		DispStudentInfo("","");		// ȫ��ѧ����Ϣ
					break;
		case 2:		DispStudentInfo(strHint,"");		// ��רҵ
					break;
		case 3:		DispStudentInfo("",strHint);		// �����
					break;
	}
}
