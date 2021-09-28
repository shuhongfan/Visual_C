// Ex_FieldView.cpp : implementation of the CEx_FieldView class
//

#include "stdafx.h"
#include "Ex_Field.h"

#include "Ex_FieldDoc.h"
#include "Ex_FieldView.h"
#include "CourseSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_FieldView

IMPLEMENT_DYNCREATE(CEx_FieldView, CListView)

BEGIN_MESSAGE_MAP(CEx_FieldView, CListView)
	//{{AFX_MSG_MAP(CEx_FieldView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_FieldView construction/destruction

CEx_FieldView::CEx_FieldView()
{
	// TODO: add construction code here

}

CEx_FieldView::~CEx_FieldView()
{
}

BOOL CEx_FieldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style &= ~LVS_TYPEMASK;
	cs.style |= LVS_REPORT; 		// 报表方式

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_FieldView drawing

void CEx_FieldView::OnDraw(CDC* pDC)
{
	CEx_FieldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CEx_FieldView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	CListCtrl& m_ListCtrl = GetListCtrl();		// 获取内嵌在列表视图中的列表控件
	CCourseSet cSet;			
	cSet.Open();						// 打开记录集
	CODBCFieldInfo field;
	// 创建列表头
	for (UINT i=0; i<cSet.m_nFields; i++)	{
		cSet.GetODBCFieldInfo( i, field );
		m_ListCtrl.InsertColumn(i,field.m_strName,LVCFMT_LEFT,100);
	}
	// 添加列表项
	int nItem = 0;
	CString str;
	while (!cSet.IsEOF())	{
		for (UINT i=0; i<cSet.m_nFields; i++)	{
			cSet.GetFieldValue(i, str);	
			if ( i == 0)
				m_ListCtrl.InsertItem( nItem, str );
			else
				m_ListCtrl.SetItemText( nItem, i, str );
		}
		nItem++;
		cSet.MoveNext();
	}
	cSet.Close();					// 关闭记录集
}

/////////////////////////////////////////////////////////////////////////////
// CEx_FieldView printing

BOOL CEx_FieldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_FieldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_FieldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_FieldView diagnostics

#ifdef _DEBUG
void CEx_FieldView::AssertValid() const
{
	CListView::AssertValid();
}

void CEx_FieldView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CEx_FieldDoc* CEx_FieldView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_FieldDoc)));
	return (CEx_FieldDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_FieldView message handlers
