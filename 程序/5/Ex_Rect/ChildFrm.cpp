// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "Ex_Rect.h"

#include "ChildFrm.h"
#include "Ex_RectView.h"
#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
	
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers

BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	BOOL bRes = m_wndSplitter.CreateStatic(this, 1, 2);	// 创建2个水平静态窗格

	CRect rect;
	GetClientRect( &rect );
	
	m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CDrawView), 
		CSize(rect.Width()/2,0), pContext);
	m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CEx_RectView), 
		CSize(rect.Width()/2,0), pContext);

	m_wndSplitter.RecalcLayout();	// 重新布局切分窗口
	return bRes;	//CMDIChildWnd::OnCreateClient(lpcs, pContext);
}


