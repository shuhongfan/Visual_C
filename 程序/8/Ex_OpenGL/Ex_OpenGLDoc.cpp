// Ex_OpenGLDoc.cpp : implementation of the CEx_OpenGLDoc class
//

#include "stdafx.h"
#include "Ex_OpenGL.h"

#include "Ex_OpenGLDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_OpenGLDoc

IMPLEMENT_DYNCREATE(CEx_OpenGLDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_OpenGLDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_OpenGLDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_OpenGLDoc construction/destruction

CEx_OpenGLDoc::CEx_OpenGLDoc()
{
	// TODO: add one-time construction code here

}

CEx_OpenGLDoc::~CEx_OpenGLDoc()
{
}

BOOL CEx_OpenGLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_OpenGLDoc serialization

void CEx_OpenGLDoc::Serialize(CArchive& ar)
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
// CEx_OpenGLDoc diagnostics

#ifdef _DEBUG
void CEx_OpenGLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_OpenGLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_OpenGLDoc commands
