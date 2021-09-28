// Ex_USEDLLDoc.cpp : implementation of the CEx_USEDLLDoc class
//

#include "stdafx.h"
#include "Ex_USEDLL.h"

#include "Ex_USEDLLDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_USEDLLDoc

IMPLEMENT_DYNCREATE(CEx_USEDLLDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_USEDLLDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_USEDLLDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_USEDLLDoc construction/destruction

CEx_USEDLLDoc::CEx_USEDLLDoc()
{
	// TODO: add one-time construction code here

}

CEx_USEDLLDoc::~CEx_USEDLLDoc()
{
}

BOOL CEx_USEDLLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_USEDLLDoc serialization

void CEx_USEDLLDoc::Serialize(CArchive& ar)
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
// CEx_USEDLLDoc diagnostics

#ifdef _DEBUG
void CEx_USEDLLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_USEDLLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_USEDLLDoc commands
