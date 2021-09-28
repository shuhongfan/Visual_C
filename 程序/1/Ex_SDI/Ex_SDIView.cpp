// Ex_SDIView.cpp : implementation of the CEx_SDIView class
//

#include "stdafx.h"
#include "Ex_SDI.h"

#include "Ex_SDIDoc.h"
#include "Ex_SDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIView

IMPLEMENT_DYNCREATE(CEx_SDIView, CView)

BEGIN_MESSAGE_MAP(CEx_SDIView, CView)
	//{{AFX_MSG_MAP(CEx_SDIView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIView construction/destruction

CEx_SDIView::CEx_SDIView()
{
	// TODO: add construction code here

}

CEx_SDIView::~CEx_SDIView()
{
}

BOOL CEx_SDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIView drawing

void CEx_SDIView::OnDraw(CDC* pDC)
{
	CEx_SDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect		rc;
	GetClientRect( &rc );
	pDC->DrawText( _T("Hello MFC!"), -1, &rc, 
				DT_SINGLELINE | DT_CENTER |DT_VCENTER ); 

}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIView printing

BOOL CEx_SDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_SDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_SDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIView diagnostics

#ifdef _DEBUG
void CEx_SDIView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_SDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_SDIDoc* CEx_SDIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_SDIDoc)));
	return (CEx_SDIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIView message handlers

void CEx_SDIView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	MessageBox ( _T("Hello, World!"),  _T("Hello"),	
	  			MB_ICONQUESTION | MB_ABORTRETRYIGNORE) ;			
	CView::OnLButtonDown(nFlags, point);
}
