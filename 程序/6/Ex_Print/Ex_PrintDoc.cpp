// Ex_PrintDoc.cpp : implementation of the CEx_PrintDoc class
//

#include "stdafx.h"
#include "Ex_Print.h"

#include "Ex_PrintDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_PrintDoc

IMPLEMENT_DYNCREATE(CEx_PrintDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_PrintDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_PrintDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_PrintDoc construction/destruction

CEx_PrintDoc::CEx_PrintDoc()
{
	// TODO: add one-time construction code here

}

CEx_PrintDoc::~CEx_PrintDoc()
{
}

BOOL CEx_PrintDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_PrintDoc serialization

void CEx_PrintDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
		CString str;
		m_strContents.RemoveAll();
		while (ar.ReadString(str))
			m_strContents.Add(str);
		m_bNewDocument = TRUE;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_PrintDoc diagnostics

#ifdef _DEBUG
void CEx_PrintDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_PrintDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_PrintDoc commands
