// Ex_StudentView.cpp : implementation file
//

#include "stdafx.h"
#include "ex_mdi.h"
#include "Ex_StudentView.h"
#include "Ex_StudentDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView

IMPLEMENT_DYNCREATE(CEx_StudentView, CView)

CEx_StudentView::CEx_StudentView()
{
}

CEx_StudentView::~CEx_StudentView()
{
}


BEGIN_MESSAGE_MAP(CEx_StudentView, CView)
	//{{AFX_MSG_MAP(CEx_StudentView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView drawing

void CEx_StudentView::OnDraw(CDC* pDC)
{
	CEx_StudentDoc* pDoc = (CEx_StudentDoc*)GetDocument();
	// TODO: add draw code here
	int y = 0;
	for (int nIndex = 0; nIndex < pDoc->GetAllRecNum(); nIndex++) {
		pDoc->GetStudentInfoAt(nIndex)->Display(y, pDC);
		y += 16;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView diagnostics

#ifdef _DEBUG
void CEx_StudentView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_StudentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView message handlers
