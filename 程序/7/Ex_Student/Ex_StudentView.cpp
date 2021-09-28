// Ex_StudentView.cpp : implementation of the CEx_StudentView class
//

#include "stdafx.h"
#include "Ex_Student.h"

#include "Ex_StudentDoc.h"
#include "Ex_StudentView.h"
#include "StudentSet.h"
#include "CourseSet.h"
#include "ScoreSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView

IMPLEMENT_DYNCREATE(CEx_StudentView, CListView)

BEGIN_MESSAGE_MAP(CEx_StudentView, CListView)
	//{{AFX_MSG_MAP(CEx_StudentView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView construction/destruction

CEx_StudentView::CEx_StudentView()
{
	// TODO: add construction code here

}

CEx_StudentView::~CEx_StudentView()
{
}

BOOL CEx_StudentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= LVS_REPORT;		// 报表风格
	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView drawing

void CEx_StudentView::OnDraw(CDC* pDC)
{
	CEx_StudentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CEx_StudentView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strHeader[]={"学号","姓名", "课程号","课程所属专业", 
		"课程名称","课程类别","开课学期","课时数","学分","成绩"};
	int nLong[] = {80, 80, 80, 180, 180, 80, 80, 80, 80, 80};
	for (int nCol=0; nCol<sizeof(strHeader)/sizeof(CString); nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nLong[nCol]);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView printing

BOOL CEx_StudentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_StudentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_StudentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView diagnostics

#ifdef _DEBUG
void CEx_StudentView::AssertValid() const
{
	CListView::AssertValid();
}

void CEx_StudentView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CEx_StudentDoc* CEx_StudentView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_StudentDoc)));
	return (CEx_StudentDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView message handlers

void CEx_StudentView::DispScoreAndCourseInfo(CString strFilter)
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	m_ListCtrl.DeleteAllItems();		// 删除所有的列表项

	CScoreSet sSet;
	sSet.m_strFilter = strFilter;		// 设置过滤条件
	sSet.Open();		// 打开score表
	int nItem = 0;
	CString str;
	while (!sSet.IsEOF())
	{
		m_ListCtrl.InsertItem( nItem, sSet.m_studentno);		// 插入学号
		// 根据score表中的studentno(学号)获取student表中的"姓名"
		CStudentSet uSet;
		uSet.m_strFilter.Format("studentno='%s'", sSet.m_studentno);
		uSet.Open();
		if (!uSet.IsEOF()) 
			m_ListCtrl.SetItemText( nItem, 1, uSet.m_studentname);
		uSet.Close();
		m_ListCtrl.SetItemText( nItem, 2, sSet.m_course);

		// 根据score表中的course(课程号)获取course表中的课程信息
		CCourseSet cSet;
		cSet.m_strFilter.Format("courseno='%s'", sSet.m_course);
		cSet.Open();	
		UINT i = 7;
		if (!cSet.IsEOF()) {
			for (i=1; i<cSet.m_nFields; i++) {
				cSet.GetFieldValue(i, str);			// 获取指定字段值
				m_ListCtrl.SetItemText( nItem, i+2, str);	
			}
		}
		cSet.Close();
		str.Format("%0.1f", sSet.m_score);
		m_ListCtrl.SetItemText( nItem, i+2, str);	
		sSet.MoveNext();
		nItem++;
	}
	if (sSet.IsOpen()) sSet.Close();
}

void CEx_StudentView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if (lHint == 1)	{
		CString strHint, str;
		strHint = *((CString *)pHint);
		delete (CString *)pHint;
		str.Format("studentno LIKE '%s%%'", strHint.Left(6));
		DispScoreAndCourseInfo(str);
	}
}
