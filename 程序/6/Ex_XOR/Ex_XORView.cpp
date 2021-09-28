// Ex_XORView.cpp : implementation of the CEx_XORView class
//

#include "stdafx.h"
#include "Ex_XOR.h"

#include "Ex_XORDoc.h"
#include "Ex_XORView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_XORView

IMPLEMENT_DYNCREATE(CEx_XORView, CView)

BEGIN_MESSAGE_MAP(CEx_XORView, CView)
	//{{AFX_MSG_MAP(CEx_XORView)
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_XORView construction/destruction

CEx_XORView::CEx_XORView()
{
	// TODO: add construction code here

}

CEx_XORView::~CEx_XORView()
{
}

BOOL CEx_XORView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_XORView drawing

void CEx_XORView::OnDraw(CDC* pDC)
{
	CEx_XORDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	m_bCursorFirst	= TRUE;
	pDC->SetBkMode( TRANSPARENT );			// 设置透明背景模式
}

/////////////////////////////////////////////////////////////////////////////
// CEx_XORView printing

BOOL CEx_XORView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_XORView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_XORView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_XORView diagnostics

#ifdef _DEBUG
void CEx_XORView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_XORView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_XORDoc* CEx_XORView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_XORDoc)));
	return (CEx_XORDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_XORView message handlers

void CEx_XORView::DrawCursor(CDC *pDC, CPoint pt)
{
	CRect	rcClip;
	pDC->GetClipBox( rcClip );					// 当前裁剪区大小
	CPen	pen( PS_SOLID, 1, RGB( 128, 128, 128 ) );	// 灰色画笔
	CPen	*oldPen = pDC->SelectObject( &pen );		// 选入画笔
	// 设置XOR光栅操作模式
	int nOldROP	= pDC->SetROP2( R2_XORPEN );			
	// 绘制水平线
	pDC->MoveTo( rcClip.left, pt.y );	pDC->LineTo( rcClip.right, pt.y );
	//绘制垂直线
	pDC->MoveTo( pt.x, rcClip.top );	pDC->LineTo( pt.x, rcClip.bottom );
	// 恢复原来的光栅模式
	pDC->SetROP2( nOldROP );							
	// 恢复原来的画笔

}

void CEx_XORView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDC* pDC		= this->GetDC();
	if ( m_bCursorFirst )
	{
		m_bCursorFirst	= FALSE;
		m_ptCurPos		= point;
		DrawCursor( pDC, m_ptCurPos );
	} else
	{
		DrawCursor( pDC, m_ptCurPos );
		m_ptCurPos		= point;
		DrawCursor( pDC, m_ptCurPos );
	}
	
	CView::OnMouseMove(nFlags, point);
}

BOOL CEx_XORView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	SetCursor( NULL );
	
	return TRUE;//CView::OnSetCursor(pWnd, nHitTest, message);
}
