// Ex_StudentView.cpp : implementation of the CEx_StudentView class
//

#include "stdafx.h"
#include "Ex_Student.h"

#include "Ex_StudentDoc.h"
#include "Ex_StudentView.h"

#include "ScoreSet.h"
#include "ScoreDlg.h"
#include "SeekDlg.h"
#include "CourseSet.h"

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
	ON_COMMAND(ID_SCORE_ADD, OnScoreAdd)
	ON_COMMAND(ID_SCORE_CHANGE, OnScoreChange)
	ON_COMMAND(ID_SCORE_DEL, OnScoreDel)
	ON_COMMAND(ID_SCORE_SEEK, OnScoreSeek)
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

	DispScoreInfo( "" );
	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
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

void CEx_StudentView::DispScoreInfo(CString strFilter)
{
	DeleteAllColumn();	// 删除表头
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strHeader[]={"学号", "课程号","成绩","学分"};
	for (int nCol=0; nCol<sizeof(strHeader)/sizeof(CString); nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,100);
	m_ListCtrl.DeleteAllItems();		// 删除所有的列表项

	CScoreSet sSet;
	sSet.m_strFilter = strFilter;
	sSet.m_strSort = "studentno,course";
	sSet.Open();
	int nItem = 0;
	CString str;
	while (!sSet.IsEOF())
	{
		m_ListCtrl.InsertItem( nItem, sSet.m_studentno);		// 插入学号
		m_ListCtrl.SetItemText( nItem, 1, sSet.m_course);
		str.Format("%4.1f", sSet.m_score);
		m_ListCtrl.SetItemText( nItem, 2, str);
		str.Format("%3.1f", sSet.m_credit);
		m_ListCtrl.SetItemText( nItem, 3, str);
		nItem++;
		sSet.MoveNext();
	}
	sSet.Close();
}

void CEx_StudentView::DeleteAllColumn()
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	int nCount = 0;
	CHeaderCtrl* pHeaderCtrl = m_ListCtrl.GetHeaderCtrl();
	if ( pHeaderCtrl!= NULL)
		nCount = pHeaderCtrl->GetItemCount();

	for (int i=0;i < nCount;i++)
		m_ListCtrl.DeleteColumn(0);
}

void CEx_StudentView::OnScoreAdd() 
{
	// TODO: Add your command handler code here
	CScoreDlg dlg;
	if (dlg.DoModal()!= IDOK) return;
	CScoreSet sSet;
	sSet.Open();

	sSet.AddNew();
	sSet.m_course		= dlg.m_strCourseNo;
	sSet.m_studentno	= dlg.m_strStuNo;
	sSet.m_score		= dlg.m_fScore;
	sSet.m_credit		= dlg.m_fCredit;
	sSet.Update();
	sSet.Requery();

	sSet.Close();

	// 更新列表视图
	MessageBox("稍等几秒钟后，单击[确定]按钮！","特别提示",MB_OK|MB_ICONINFORMATION);
	m_strFilter.Format("studentno='%s'", dlg.m_strStuNo);
	// 打开并显示所有学号为dlg.m_strStuNo的记录
	DispScoreInfo( m_strFilter );
}

void CEx_StudentView::OnScoreChange() 
{
	int nItem = GetListCtrlCurSel();
	if (nItem<0) return;
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strStudentNO = m_ListCtrl.GetItemText( nItem, 0 );
	CString strCourseNO = m_ListCtrl.GetItemText( nItem, 1 );

	CScoreSet sSet;
	sSet.m_strFilter.Format("studentno='%s' AND course='%s'", strStudentNO, strCourseNO);
	sSet.Open();

	CScoreDlg dlg;
	dlg.m_strOKText		= "修改";
	dlg.m_strCourseNo	= sSet.m_course;
	dlg.m_strStuNo		= sSet.m_studentno;
	dlg.m_fScore		= sSet.m_score;
	dlg.m_fCredit		= sSet.m_credit;

	if (IDOK != dlg.DoModal())
	{
		if (sSet.IsOpen()) sSet.Close();
		return;
	}
	sSet.Edit();
	sSet.m_score		= dlg.m_fScore;	// 只能修改成绩

	sSet.Update();
	sSet.Requery();
	if (sSet.IsOpen()) sSet.Close();

	// 更新列表视图
	MessageBox("稍等几秒钟后，单击[确定]按钮！","特别提示",MB_OK|MB_ICONINFORMATION);	
	m_strFilter.Format("studentno='%s'", dlg.m_strStuNo);
	// 打开并显示所有学号为dlg.m_strStuNo的记录
	DispScoreInfo( m_strFilter );
}

void CEx_StudentView::OnScoreDel() 
{
	int nItem = GetListCtrlCurSel();
	if (nItem<0) return;
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strItem, str;
	strItem = m_ListCtrl.GetItemText( nItem, 0 );
	str.Format("你确实要删除 %s 列表项(记录)吗？", strItem );
	if ( IDOK != MessageBox(str, "删除确认", MB_ICONQUESTION | MB_OKCANCEL ))
		return;
		
	CString strStudentNO = m_ListCtrl.GetItemText( nItem, 0 );
	CString strCourseNO = m_ListCtrl.GetItemText( nItem, 1 );

	CScoreSet infoSet;
	infoSet.m_strFilter.Format("studentno='%s' AND course='%s'", strStudentNO, strCourseNO);
	infoSet.Open();
	if (!infoSet.IsEOF()) {	
		CRecordsetStatus status;
		infoSet.GetStatus(status);			// 获取当前记录集状态
		infoSet.Delete();				// 删除当前记录
		if (status.m_lCurrentRecord==0)		// 当前记录索引号，0表示第一条记录
			infoSet.MoveNext();			// 下移一个记录
		else
			infoSet.MoveFirst();			// 移动到第一个记录处
	}
	if (infoSet.IsOpen()) infoSet.Close();
	// 更新列表视图
	MessageBox("稍等几秒钟后，单击[确定]按钮！","特别提示",MB_OK|MB_ICONINFORMATION);
	DispScoreInfo( m_strFilter );
}

int CEx_StudentView::GetListCtrlCurSel()
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL){
		MessageBox("你还没有选中列表项！");
		return -1;
	}
	return m_ListCtrl.GetNextSelectedItem( pos );
}

void CEx_StudentView::OnScoreSeek() 
{
	CSeekDlg dlg;
	dlg.m_strTitle = "选择学号：";
	// 获取列表项第一列内容
	CString strTemp;
	CListCtrl& m_ListCtrl = GetListCtrl();
	int nItemCount = m_ListCtrl.GetItemCount();
	dlg.m_strItemArray.RemoveAll();
	for ( int nItem=0; nItem<nItemCount; nItem++){
		strTemp = m_ListCtrl.GetItemText(nItem, 0);
		dlg.m_strItemArray.Add( strTemp );
	}
	if (IDOK != dlg.DoModal()) return;

	CString str;
	str.Format("studentno = '%s'", dlg.m_strSeek);
	DispScoreAndCourseInfo( str, dlg.m_nTerm);
}

void CEx_StudentView::DispScoreAndCourseInfo(CString strFilter, int nOpenTerm)
{
	DeleteAllColumn();	// 删除表头
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strHeader[]={"学号", "课程号", "课程所属专业", "课程名称","课程类别","开课学期","课时数","学分","成绩"};
	int nLong[] = {80, 80, 180, 180, 80, 80, 80, 80, 80};
	for (int nCol=0; nCol<sizeof(strHeader)/sizeof(CString); nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nLong[nCol]);
	m_ListCtrl.DeleteAllItems();		// 删除所有的列表项

	CScoreSet sSet;
	sSet.m_strFilter = strFilter;
	sSet.m_strSort = "studentno";
	sSet.Open();
	int nItem = 0;
	CString str;
	while (!sSet.IsEOF())
	{
		CCourseSet cSet;
		if (nOpenTerm == 0)		// 所有学期
			cSet.m_strFilter.Format("courseno='%s'", sSet.m_course);
		else
			cSet.m_strFilter.Format("courseno='%s' AND openterm=%d",sSet.m_course,nOpenTerm);
		cSet.Open();
		UINT i;
		if (!cSet.IsEOF()){
			// 通过Get获取相关字段记录内容
			m_ListCtrl.InsertItem( nItem, sSet.m_studentno);		// 插入学号
			for (i=0; i<cSet.m_nFields; i++)
			{
				cSet.GetFieldValue(i, str);			// 获取指定字段值
				m_ListCtrl.SetItemText( nItem, i+1, str);	
			}
			str.Format("%0.1f", sSet.m_score);
			m_ListCtrl.SetItemText( nItem, i+1, str);	
			nItem++;
		}
		cSet.Close();
		sSet.MoveNext();
	}
	sSet.Close();
}
