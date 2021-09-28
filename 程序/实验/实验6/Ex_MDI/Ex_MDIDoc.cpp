// Ex_MDIDoc.cpp : implementation of the CEx_MDIDoc class
//

#include "stdafx.h"
#include "Ex_MDI.h"

#include "Ex_MDIDoc.h"
#include "CourseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDoc

IMPLEMENT_DYNCREATE(CEx_MDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_MDIDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_MDIDoc)
	ON_COMMAND(ID_COURSEINFO_ADD, OnCourseinfoAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDoc construction/destruction

CEx_MDIDoc::CEx_MDIDoc()
{
	// TODO: add one-time construction code here

}

CEx_MDIDoc::~CEx_MDIDoc()
{
	int nIndex = GetCourseRecNum();
	while (nIndex--)
		delete m_courseObArray.GetAt(nIndex);	// 删除并释放对象的内存空间
	m_courseObArray.RemoveAll();
}

BOOL CEx_MDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDoc serialization

void CEx_MDIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		m_courseObArray.Serialize(ar);
	}
	else
	{
		m_courseObArray.Serialize(ar);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDoc diagnostics

#ifdef _DEBUG
void CEx_MDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_MDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIDoc commands

CCourseInfo* CEx_MDIDoc::GetCourseInfoAt(int nIndex)
{
	if ((nIndex < 0) || nIndex > m_courseObArray.GetUpperBound())
		return NULL;	// 超界处理
	return (CCourseInfo *)m_courseObArray.GetAt(nIndex);
}

int CEx_MDIDoc::GetCourseRecNum()
{
	return m_courseObArray.GetSize();
}

void CEx_MDIDoc::OnCourseinfoAdd() 
{
	// TODO: Add your command handler code here
	CCourseDlg dlg;
	if (dlg.DoModal() != IDOK) return;
	// 添加记录
	CCourseInfo *pCourse = new CCourseInfo(dlg.m_strNO, dlg.m_strName,
			dlg.m_strSpecial, dlg.m_strType, dlg.m_nOpen, dlg.m_nHours, dlg.m_fCredit);
	m_courseObArray.Add(pCourse);
	SetModifiedFlag();		// 设置文档更改标志
	UpdateAllViews(NULL);	// 更新视图
}
