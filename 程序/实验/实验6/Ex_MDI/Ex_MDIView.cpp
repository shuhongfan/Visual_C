// Ex_MDIView.cpp : implementation of the CEx_MDIView class
//

#include "stdafx.h"
#include "Ex_MDI.h"

#include "Ex_MDIDoc.h"
#include "Ex_MDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIView

IMPLEMENT_DYNCREATE(CEx_MDIView, CView)

BEGIN_MESSAGE_MAP(CEx_MDIView, CView)
	//{{AFX_MSG_MAP(CEx_MDIView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIView construction/destruction

CEx_MDIView::CEx_MDIView()
{
	// TODO: add construction code here

}

CEx_MDIView::~CEx_MDIView()
{
}

BOOL CEx_MDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIView drawing

void CEx_MDIView::OnDraw(CDC* pDC)
{
	CEx_MDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int y = 0;
	for (int nIndex = 0; nIndex < pDoc->GetCourseRecNum(); nIndex++) {
		pDoc->GetCourseInfoAt(nIndex)->Display(y, pDC);
		y += 16;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIView printing

BOOL CEx_MDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_MDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_MDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIView diagnostics

#ifdef _DEBUG
void CEx_MDIView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_MDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_MDIDoc* CEx_MDIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_MDIDoc)));
	return (CEx_MDIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIView message handlers
