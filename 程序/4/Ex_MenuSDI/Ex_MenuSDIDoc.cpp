// Ex_MenuSDIDoc.cpp : implementation of the CEx_MenuSDIDoc class
//

#include "stdafx.h"
#include "Ex_MenuSDI.h"

#include "Ex_MenuSDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuSDIDoc

IMPLEMENT_DYNCREATE(CEx_MenuSDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_MenuSDIDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_MenuSDIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuSDIDoc construction/destruction

CEx_MenuSDIDoc::CEx_MenuSDIDoc()
{
	// TODO: add one-time construction code here

}

CEx_MenuSDIDoc::~CEx_MenuSDIDoc()
{
}

BOOL CEx_MenuSDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_MenuSDIDoc serialization

void CEx_MenuSDIDoc::Serialize(CArchive& ar)
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
// CEx_MenuSDIDoc diagnostics

#ifdef _DEBUG
void CEx_MenuSDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_MenuSDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuSDIDoc commands
