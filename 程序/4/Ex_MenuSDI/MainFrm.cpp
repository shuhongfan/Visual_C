// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Ex_MenuSDI.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_TEST_RETURN, OnTestReturn)
	ON_COMMAND(ID_VIEW_TEST, OnViewTest)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	int nRes = m_wndTestBar.CreateEx(this, TBSTYLE_FLAT, 
		WS_CHILD | WS_VISIBLE | 
		CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC,
		CRect(0,0,0,0),
		AFX_IDW_TOOLBAR + 10);
	if (!nRes || !m_wndTestBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndTestBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_wndTestBar);
	ShowControlBar( &m_wndTestBar, FALSE, FALSE );	// 关闭测试工具栏
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnViewTest() 
{
	m_NewMenu.Detach();				// 使菜单对象和菜单句柄分离
	m_NewMenu.LoadMenu( IDR_MENU1 ); 
	SetMenu(NULL); 				// 清除应用程序菜单
	SetMenu( &m_NewMenu ); 		// 设置应用程序菜单
	ShowControlBar( &m_wndTestBar, TRUE, FALSE );	// 显示测试工具栏
	ShowControlBar( &m_wndToolBar, FALSE, FALSE );	// 关闭主工具栏
}

void CMainFrame::OnTestReturn() 
{
	m_NewMenu.Detach();
	m_NewMenu.LoadMenu( IDR_MAINFRAME );
	SetMenu(NULL);
	SetMenu( &m_NewMenu );	
	ShowControlBar( &m_wndTestBar, FALSE, FALSE );	// 关闭测试工具栏
	ShowControlBar( &m_wndToolBar, TRUE, FALSE );	// 显示主工具栏
} 


void CMainFrame::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	CMenu* pSysMenu = GetMenu();					// 获得程序菜单指针
	int nCount = pSysMenu->GetMenuItemCount();		// 获得顶层菜单个数
	int nSubMenuPos = -1;
	for (int i=0; i<nCount; i++)						// 查找菜单
	{
		CString str;
		pSysMenu->GetMenuString(i, str, MF_BYPOSITION);
		if ((str.Left(4) == "查看") || (str.Left(4) == "测试"))	{
			nSubMenuPos = i;		break;
		}
	}
	if (nSubMenuPos<0) return;						// 没有找到，返回
	pSysMenu->GetSubMenu( nSubMenuPos) 
		->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, point.x, point.y, this);
}
