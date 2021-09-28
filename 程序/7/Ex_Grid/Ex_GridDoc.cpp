// Ex_GridDoc.cpp : implementation of the CEx_GridDoc class
//

#include "stdafx.h"
#include "Ex_Grid.h"

#include "Ex_GridSet.h"
#include "Ex_GridDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_GridDoc

IMPLEMENT_DYNCREATE(CEx_GridDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_GridDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_GridDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_GridDoc construction/destruction

CEx_GridDoc::CEx_GridDoc()
{
	// TODO: add one-time construction code here

}

CEx_GridDoc::~CEx_GridDoc()
{
}

BOOL CEx_GridDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_GridDoc serialization

void CEx_GridDoc::Serialize(CArchive& ar)
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
// CEx_GridDoc diagnostics

#ifdef _DEBUG
void CEx_GridDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_GridDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_GridDoc commands
