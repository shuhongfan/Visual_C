// Ex_MCIView.cpp : implementation of the CEx_MCIView class
//

#include "stdafx.h"
#include "Ex_MCI.h"

#include "Ex_MCIDoc.h"
#include "Ex_MCIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_MCIView

IMPLEMENT_DYNCREATE(CEx_MCIView, CView)

BEGIN_MESSAGE_MAP(CEx_MCIView, CView)
	//{{AFX_MSG_MAP(CEx_MCIView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_MESSAGE(MCIWNDM_NOTIFYSIZE,OnNotifySize)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_MCIView construction/destruction

CEx_MCIView::CEx_MCIView()
{
	// TODO: add construction code here
	m_hMyMCIWnd = NULL;
}

CEx_MCIView::~CEx_MCIView()
{
}

BOOL CEx_MCIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MCIView drawing

void CEx_MCIView::OnDraw(CDC* pDC)
{
	CEx_MCIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MCIView printing

BOOL CEx_MCIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_MCIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_MCIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MCIView diagnostics

#ifdef _DEBUG
void CEx_MCIView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_MCIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_MCIDoc* CEx_MCIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_MCIDoc)));
	return (CEx_MCIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_MCIView message handlers

void CEx_MCIView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_hMyMCIWnd = MCIWndCreate(m_hWnd,AfxGetInstanceHandle(),
		MCIWNDF_NOTIFYSIZE |MCIWNDF_NOERRORDLG |
		WS_CHILD|WS_VISIBLE,NULL);
	if (m_hMyMCIWnd==NULL) return;
	const CString &filename = GetDocument()->GetPathName();
	if (filename.GetLength()>0)
		MCIWndOpen(m_hMyMCIWnd,(LPCSTR)filename,0);
	
}
LONG CEx_MCIView::OnNotifySize(UINT wParam, LONG lParam)
{
	CRect rc;
	CFrameWnd* pParent = GetParentFrame();	// 获取主框架窗口指针
	if (m_hMyMCIWnd)
	{
		::GetWindowRect(m_hMyMCIWnd,rc);
		pParent->CalcWindowRect(rc,CWnd::adjustBorder);
		CSize size(rc.Width(),rc.Height());
		if (GetExStyle()&WS_EX_CLIENTEDGE)
		{
			size.cx+=4;
			size.cy+=4;
		}
		pParent->SetWindowPos(NULL,0,0,size.cx,size.cy,
			SWP_NOZORDER|SWP_NOACTIVATE|SWP_NOMOVE);
	}
	else 
	{
		pParent->SetWindowPos(NULL,0,0,200,160,
			SWP_NOZORDER|SWP_NOACTIVATE|SWP_NOMOVE);
	}
	return 1;
}
