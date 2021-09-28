// Ex_MenuSDIView.cpp : implementation of the CEx_MenuSDIView class
//

#include "stdafx.h"
#include "Ex_MenuSDI.h"

#include "Ex_MenuSDIDoc.h"
#include "Ex_MenuSDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuSDIView

IMPLEMENT_DYNCREATE(CEx_MenuSDIView, CView)

BEGIN_MESSAGE_MAP(CEx_MenuSDIView, CView)
	//{{AFX_MSG_MAP(CEx_MenuSDIView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuSDIView construction/destruction

CEx_MenuSDIView::CEx_MenuSDIView()
{
	// TODO: add construction code here

}

CEx_MenuSDIView::~CEx_MenuSDIView()
{
}

BOOL CEx_MenuSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuSDIView drawing

void CEx_MenuSDIView::OnDraw(CDC* pDC)
{
	CEx_MenuSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuSDIView printing

BOOL CEx_MenuSDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_MenuSDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_MenuSDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuSDIView diagnostics

#ifdef _DEBUG
void CEx_MenuSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_MenuSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_MenuSDIDoc* CEx_MenuSDIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_MenuSDIDoc)));
	return (CEx_MenuSDIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuSDIView message handlers
