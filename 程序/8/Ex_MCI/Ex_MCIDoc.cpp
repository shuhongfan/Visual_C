// Ex_MCIDoc.cpp : implementation of the CEx_MCIDoc class
//

#include "stdafx.h"
#include "Ex_MCI.h"

#include "Ex_MCIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_MCIDoc

IMPLEMENT_DYNCREATE(CEx_MCIDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_MCIDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_MCIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_MCIDoc construction/destruction

CEx_MCIDoc::CEx_MCIDoc()
{
	// TODO: add one-time construction code here

}

CEx_MCIDoc::~CEx_MCIDoc()
{
}

BOOL CEx_MCIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_MCIDoc serialization

void CEx_MCIDoc::Serialize(CArchive& ar)
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
// CEx_MCIDoc diagnostics

#ifdef _DEBUG
void CEx_MCIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_MCIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_MCIDoc commands
