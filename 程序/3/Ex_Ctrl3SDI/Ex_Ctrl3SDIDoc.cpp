// Ex_Ctrl3SDIDoc.cpp : implementation of the CEx_Ctrl3SDIDoc class
//

#include "stdafx.h"
#include "Ex_Ctrl3SDI.h"

#include "Ex_Ctrl3SDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl3SDIDoc

IMPLEMENT_DYNCREATE(CEx_Ctrl3SDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_Ctrl3SDIDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_Ctrl3SDIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl3SDIDoc construction/destruction

CEx_Ctrl3SDIDoc::CEx_Ctrl3SDIDoc()
{
	// TODO: add one-time construction code here

}

CEx_Ctrl3SDIDoc::~CEx_Ctrl3SDIDoc()
{
}

BOOL CEx_Ctrl3SDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl3SDIDoc serialization

void CEx_Ctrl3SDIDoc::Serialize(CArchive& ar)
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
// CEx_Ctrl3SDIDoc diagnostics

#ifdef _DEBUG
void CEx_Ctrl3SDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_Ctrl3SDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl3SDIDoc commands
