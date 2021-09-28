// Ex_TestDLLDoc.cpp : implementation of the CEx_TestDLLDoc class
//

#include "stdafx.h"
#include "Ex_TestDLL.h"

#include "Ex_TestDLLDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_TestDLLDoc

IMPLEMENT_DYNCREATE(CEx_TestDLLDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_TestDLLDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_TestDLLDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_TestDLLDoc construction/destruction

CEx_TestDLLDoc::CEx_TestDLLDoc()
{
	// TODO: add one-time construction code here

}

CEx_TestDLLDoc::~CEx_TestDLLDoc()
{
}

BOOL CEx_TestDLLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_TestDLLDoc serialization

void CEx_TestDLLDoc::Serialize(CArchive& ar)
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
// CEx_TestDLLDoc diagnostics

#ifdef _DEBUG
void CEx_TestDLLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_TestDLLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_TestDLLDoc commands
