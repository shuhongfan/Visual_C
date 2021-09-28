// Ex_StudentDoc.cpp : implementation of the CEx_StudentDoc class
//

#include "stdafx.h"
#include "Ex_Student.h"

#include "Ex_StudentDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc

IMPLEMENT_DYNCREATE(CEx_StudentDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_StudentDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_StudentDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc construction/destruction

CEx_StudentDoc::CEx_StudentDoc()
{
	// TODO: add one-time construction code here

}

CEx_StudentDoc::~CEx_StudentDoc()
{
	int nIndex = GetAllRecNum();
	while (nIndex--)
		delete m_stuObArray.GetAt(nIndex);	// 删除并释放对象的内存空间
	m_stuObArray.RemoveAll();
}

BOOL CEx_StudentDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc serialization

void CEx_StudentDoc::Serialize(CArchive& ar)
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
// CEx_StudentDoc diagnostics

#ifdef _DEBUG
void CEx_StudentDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_StudentDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc commands
CStudentInfo* CEx_StudentDoc::GetStudentInfoAt(int nIndex)
{
	if ((nIndex < 0) || nIndex > m_stuObArray.GetUpperBound())
		return NULL;	// 超界处理
	return (CStudentInfo *)m_stuObArray.GetAt(nIndex);

}

int CEx_StudentDoc::GetAllRecNum()
{
	return m_stuObArray.GetSize();
}
