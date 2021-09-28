// Ex_TestDLLView.cpp : implementation of the CEx_TestDLLView class
//

#include "stdafx.h"
#include "Ex_TestDLL.h"

#include "Ex_TestDLLDoc.h"
#include "Ex_TestDLLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_TestDLLView

IMPLEMENT_DYNCREATE(CEx_TestDLLView, CView)

BEGIN_MESSAGE_MAP(CEx_TestDLLView, CView)
	//{{AFX_MSG_MAP(CEx_TestDLLView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_TestDLLView construction/destruction

CEx_TestDLLView::CEx_TestDLLView()
{
	// TODO: add construction code here

}

CEx_TestDLLView::~CEx_TestDLLView()
{
}

BOOL CEx_TestDLLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_TestDLLView drawing

void CEx_TestDLLView::OnDraw(CDC* pDC)
{
	CEx_TestDLLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_TestDLLView printing

BOOL CEx_TestDLLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_TestDLLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_TestDLLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_TestDLLView diagnostics

#ifdef _DEBUG
void CEx_TestDLLView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_TestDLLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_TestDLLDoc* CEx_TestDLLView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_TestDLLDoc)));
	return (CEx_TestDLLDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_TestDLLView message handlers
