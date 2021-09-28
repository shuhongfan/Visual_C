// Ex_Ctrl7SDIDoc.cpp : implementation of the CEx_Ctrl7SDIDoc class
//

#include "stdafx.h"
#include "Ex_Ctrl7SDI.h"

#include "Ex_Ctrl7SDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl7SDIDoc

IMPLEMENT_DYNCREATE(CEx_Ctrl7SDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_Ctrl7SDIDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_Ctrl7SDIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl7SDIDoc construction/destruction

CEx_Ctrl7SDIDoc::CEx_Ctrl7SDIDoc()
{
	// TODO: add one-time construction code here

}

CEx_Ctrl7SDIDoc::~CEx_Ctrl7SDIDoc()
{
}

BOOL CEx_Ctrl7SDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl7SDIDoc serialization

void CEx_Ctrl7SDIDoc::Serialize(CArchive& ar)
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
// CEx_Ctrl7SDIDoc diagnostics

#ifdef _DEBUG
void CEx_Ctrl7SDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_Ctrl7SDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl7SDIDoc commands
