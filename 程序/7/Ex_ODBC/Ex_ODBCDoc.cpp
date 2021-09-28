// Ex_ODBCDoc.cpp : implementation of the CEx_ODBCDoc class
//

#include "stdafx.h"
#include "Ex_ODBC.h"

#include "Ex_ODBCSet.h"
#include "Ex_ODBCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ODBCDoc

IMPLEMENT_DYNCREATE(CEx_ODBCDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_ODBCDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_ODBCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ODBCDoc construction/destruction

CEx_ODBCDoc::CEx_ODBCDoc()
{
	// TODO: add one-time construction code here

}

CEx_ODBCDoc::~CEx_ODBCDoc()
{
}

BOOL CEx_ODBCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_ODBCDoc serialization

void CEx_ODBCDoc::Serialize(CArchive& ar)
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
// CEx_ODBCDoc diagnostics

#ifdef _DEBUG
void CEx_ODBCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_ODBCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ODBCDoc commands
