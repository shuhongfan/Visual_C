// Ex_XORDoc.cpp : implementation of the CEx_XORDoc class
//

#include "stdafx.h"
#include "Ex_XOR.h"

#include "Ex_XORDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_XORDoc

IMPLEMENT_DYNCREATE(CEx_XORDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_XORDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_XORDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_XORDoc construction/destruction

CEx_XORDoc::CEx_XORDoc()
{
	// TODO: add one-time construction code here

}

CEx_XORDoc::~CEx_XORDoc()
{
}

BOOL CEx_XORDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_XORDoc serialization

void CEx_XORDoc::Serialize(CArchive& ar)
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
// CEx_XORDoc diagnostics

#ifdef _DEBUG
void CEx_XORDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_XORDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_XORDoc commands
