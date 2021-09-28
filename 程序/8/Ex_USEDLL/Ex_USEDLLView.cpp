// Ex_USEDLLView.cpp : implementation of the CEx_USEDLLView class
//

#include "stdafx.h"
#include "Ex_USEDLL.h"

#include "Ex_USEDLLDoc.h"
#include "Ex_USEDLLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_USEDLLView

IMPLEMENT_DYNCREATE(CEx_USEDLLView, CView)

BEGIN_MESSAGE_MAP(CEx_USEDLLView, CView)
	//{{AFX_MSG_MAP(CEx_USEDLLView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_USEDLLView construction/destruction

CEx_USEDLLView::CEx_USEDLLView()
{
	// TODO: add construction code here

}

CEx_USEDLLView::~CEx_USEDLLView()
{
}

BOOL CEx_USEDLLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_USEDLLView drawing

void CEx_USEDLLView::OnDraw(CDC* pDC)
{
	CEx_USEDLLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_USEDLLView printing

BOOL CEx_USEDLLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_USEDLLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_USEDLLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_USEDLLView diagnostics

#ifdef _DEBUG
void CEx_USEDLLView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_USEDLLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_USEDLLDoc* CEx_USEDLLView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_USEDLLDoc)));
	return (CEx_USEDLLDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_USEDLLView message handlers
