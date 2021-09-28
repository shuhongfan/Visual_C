// Ex_StudentDoc.cpp : implementation file
//

#include "stdafx.h"
#include "ex_mdi.h"
#include "Ex_StudentDoc.h"
#include "StuInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc

IMPLEMENT_DYNCREATE(CEx_StudentDoc, CDocument)

CEx_StudentDoc::CEx_StudentDoc()
{
}

BOOL CEx_StudentDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CEx_StudentDoc::~CEx_StudentDoc()
{
	int nIndex = GetAllRecNum();
	while (nIndex--)
		delete m_stuObArray.GetAt(nIndex);	// 删除并释放对象的内存空间
	m_stuObArray.RemoveAll();
}


BEGIN_MESSAGE_MAP(CEx_StudentDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_StudentDoc)
	ON_COMMAND(ID_STUINFO_ADD, OnStuinfoAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

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
// CEx_StudentDoc serialization

void CEx_StudentDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		m_stuObArray.Serialize(ar);
	}
	else
	{
		// TODO: add loading code here
		m_stuObArray.Serialize(ar);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc commands

void CEx_StudentDoc::OnStuinfoAdd() 
{
	// TODO: Add your command handler code here
	CStuInfoDlg dlg;
	if (dlg.DoModal() != IDOK) return;
	// 添加记录
	CStudentInfo *pStudent = new CStudentInfo(dlg.m_strName,
			dlg.m_strNo, dlg.m_bMale, dlg.m_tBirth, dlg.m_strSpecial);
	m_stuObArray.Add(pStudent);
	SetModifiedFlag();		// 设置文档更改标志
	UpdateAllViews(NULL);	// 更新视图
	
}

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
