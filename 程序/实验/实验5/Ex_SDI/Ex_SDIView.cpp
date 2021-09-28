// Ex_SDIView.cpp : implementation of the CEx_SDIView class
//

#include "stdafx.h"
#include "Ex_SDI.h"

#include "Ex_SDIDoc.h"
#include "Ex_SDIView.h"

#include "MainFrm.h"

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
	ON_WM_MOUSEMOVE()
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

void CEx_SDIView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMainFrame* pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd; 	// 获得主窗口指针
	CStatusBar* pStatus=&pFrame->m_wndStatusBar;	// 获得主窗口中的状态栏指针
	CString str;
	if (pFrame->m_bIsMouse)
		str.Format("%d,%d",point.x, point.y);		// 格式化文本
	else
		str.Empty();	// 为空字符
	if (pStatus) 
		pStatus->SetPaneText(1,str);				// 更新第二个窗格的文本
	
	CView::OnMouseMove(nFlags, point);
}
