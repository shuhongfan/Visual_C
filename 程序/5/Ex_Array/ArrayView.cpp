// ArrayView.cpp : implementation file
//

#include "stdafx.h"
#include "ex_array.h"
#include "ArrayView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CArrayView

IMPLEMENT_DYNCREATE(CArrayView, CFormView)

CArrayView::CArrayView()
	: CFormView(CArrayView::IDD)
{
	//{{AFX_DATA_INIT(CArrayView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CArrayView::~CArrayView()
{
}

void CArrayView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArrayView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CArrayView, CFormView)
	//{{AFX_MSG_MAP(CArrayView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CArrayView diagnostics

#ifdef _DEBUG
void CArrayView::AssertValid() const
{
	CFormView::AssertValid();
}

void CArrayView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CArrayView message handlers
