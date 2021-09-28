// Ex_DBCtrlDoc.cpp : implementation of the CEx_DBCtrlDoc class
//

#include "stdafx.h"
#include "Ex_DBCtrl.h"

#include "Ex_DBCtrlDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_DBCtrlDoc

IMPLEMENT_DYNCREATE(CEx_DBCtrlDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_DBCtrlDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_DBCtrlDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_DBCtrlDoc construction/destruction

CEx_DBCtrlDoc::CEx_DBCtrlDoc()
{
	// TODO: add one-time construction code here

}

CEx_DBCtrlDoc::~CEx_DBCtrlDoc()
{
}

BOOL CEx_DBCtrlDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_DBCtrlDoc serialization

void CEx_DBCtrlDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_DBCtrlDoc diagnostics

#ifdef _DEBUG
void CEx_DBCtrlDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_DBCtrlDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_DBCtrlDoc commands
