// Ex_FieldDoc.cpp : implementation of the CEx_FieldDoc class
//

#include "stdafx.h"
#include "Ex_Field.h"

#include "Ex_FieldDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_FieldDoc

IMPLEMENT_DYNCREATE(CEx_FieldDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_FieldDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_FieldDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_FieldDoc construction/destruction

CEx_FieldDoc::CEx_FieldDoc()
{
	// TODO: add one-time construction code here

}

CEx_FieldDoc::~CEx_FieldDoc()
{
}

BOOL CEx_FieldDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_FieldDoc serialization

void CEx_FieldDoc::Serialize(CArchive& ar)
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
// CEx_FieldDoc diagnostics

#ifdef _DEBUG
void CEx_FieldDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_FieldDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_FieldDoc commands
