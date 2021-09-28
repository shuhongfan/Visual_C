// Ex_DBCtrlView.cpp : implementation of the CEx_DBCtrlView class
//

#include "stdafx.h"
#include "Ex_DBCtrl.h"

#include "Ex_DBCtrlDoc.h"
#include "Ex_DBCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_DBCtrlView

IMPLEMENT_DYNCREATE(CEx_DBCtrlView, CFormView)

BEGIN_MESSAGE_MAP(CEx_DBCtrlView, CFormView)
	//{{AFX_MSG_MAP(CEx_DBCtrlView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_DBCtrlView construction/destruction

CEx_DBCtrlView::CEx_DBCtrlView()
	: CFormView(CEx_DBCtrlView::IDD)
{
	//{{AFX_DATA_INIT(CEx_DBCtrlView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CEx_DBCtrlView::~CEx_DBCtrlView()
{
}

void CEx_DBCtrlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_DBCtrlView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CEx_DBCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CEx_DBCtrlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CEx_DBCtrlView printing

BOOL CEx_DBCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_DBCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_DBCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CEx_DBCtrlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_DBCtrlView diagnostics

#ifdef _DEBUG
void CEx_DBCtrlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CEx_DBCtrlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CEx_DBCtrlDoc* CEx_DBCtrlView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_DBCtrlDoc)));
	return (CEx_DBCtrlDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_DBCtrlView message handlers
