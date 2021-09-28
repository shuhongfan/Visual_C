// Ex_StudentView.cpp : implementation of the CEx_StudentView class
//

#include "stdafx.h"
#include "Ex_Student.h"

#include "Ex_StudentDoc.h"
#include "Ex_StudentView.h"

#include "StudentSet.h"
#include "ScoreSet.h"
#include "CourseSet.h"

#include "StuInfoDlg.h"
#include "ScoreDlg.h"
#include "CourseDlg.h"

#include "SeekDlg.h"
#include "StatDlg.h"

#include "MainFrm.h"

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
	ON_COMMAND(ID_OP_CHANGE, OnOpChange)
	ON_COMMAND(ID_OP_DEL, OnOpDel)
	ON_COMMAND(ID_SEL_SEEK, OnSelSeek)
	ON_COMMAND(ID_SEL_STAT, OnSelStat)
	ON_UPDATE_COMMAND_UI(ID_SEL_STAT, OnUpdateSelStat)
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
	memset(&m_pageInfo, 0, sizeof(m_pageInfo));		// 所有成员置为0

	double fontScale = 254.0/72.0;	// 一个点相当于多少0.1mm
	// 页眉字体
	m_pageInfo.lfHead.lfHeight = - (int)(9 * fontScale + 0.5);		// 9号字
	m_pageInfo.lfHead.lfWeight = FW_BOLD;
	m_pageInfo.lfHead.lfCharSet = GB2312_CHARSET;
	strcpy((LPSTR)&(m_pageInfo.lfHead.lfFaceName), "黑体");

	// 页脚字体
	m_pageInfo.lfFoot.lfHeight = - (int)(9 * fontScale + 0.5);		// 9号字
	m_pageInfo.lfFoot.lfWeight = FW_NORMAL;
	m_pageInfo.lfFoot.lfCharSet = GB2312_CHARSET;
	strcpy((LPSTR)&(m_pageInfo.lfFoot.lfFaceName), "楷体_GB2312");

	// 正文字体
	m_pageInfo.lfText.lfHeight = - (int)(9 * fontScale + 0.5);		// 9号字
	m_pageInfo.lfText.lfWeight = FW_NORMAL;
	m_pageInfo.lfText.lfCharSet = GB2312_CHARSET;
	strcpy((LPSTR)&(m_pageInfo.lfText.lfFaceName), "宋体");
}

CEx_StudentView::~CEx_StudentView()
{
}

BOOL CEx_StudentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= LVS_REPORT;

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


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView printing

BOOL CEx_StudentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	ReadListViewData();
	int nSize =m_strContents.GetSize();
	if (nSize<1) pInfo->SetMaxPage(1);
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

void CEx_StudentView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	CEx_StudentDoc* pDoc = GetDocument();
	CString strHint, str;
	if (pHint)
	{
		strHint = *((CString *)pHint);
		delete (CString *)pHint;
	}
	if (pDoc->m_nInfoType == 1) { // 学生信息
		switch ((int)lHint)
		{
			case 1:	
			case 2:
			case 3:
					str.Format("studentno LIKE '%s%%'", strHint.Left(6));
					DispStudentInfo( str, "studentno");
					break;
			case 11:	
					str.Format("studentno LIKE '%s%%'", strHint.Left(6));
					DispStudentInfo( str, "studentno");
					break;
			case 12:
					str.Format("special = '%s'", strHint);
					DispStudentInfo( str, "studentno");
					break;
			case 13:
					str = "";
					DispStudentInfo( str, "studentno");
					break;
		}
	} else
	if (pDoc->m_nInfoType == 2) {	// 课程信息
		switch ((int)lHint)
		{
			case 1:	
			case 2:
			case 3:
					str.Format("courseno = '%s'", strHint);
					DispCourseInfo( str, "");
					break;
			case 11:	
					str.Format("special = '%s'", strHint);
					DispCourseInfo( str, "courseno");
					break;
			case 12:
					str.Format("special = '%s'", strHint);
					DispCourseInfo( str, "courseno");
					break;
			case 13:
					str = "";
					DispCourseInfo( str, "courseno");
					break;
		}
	} else
	if (pDoc->m_nInfoType == 3) {	// 学生成绩
		switch ((int)lHint)
		{
			case 1:	
			case 2:
			case 3:
					str.Format("studentno = '%s'", strHint);
					DispScoreAndCourseInfo( str);
					break;
			case 11:	
					str.Format("studentno LIKE '%s%%'", strHint.Left(6));
					DispScoreAndCourseInfo( str);
					break;
			case 12:
					str.Format("special = '%s'", strHint);
					DispScoreAndCourseInfo2( str);
					break;
			case 13:
					str = "";
					DispScoreAndCourseInfo( str);
					break;
		}
	}
	DispStatusRecord();
}

void CEx_StudentView::DispStudentInfo(CString strFilter, CString strSort)
{
	DeleteAllColumn();	// 删除表头
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strHeader[]={"学号", "姓名","性别","出生日期",
		"专业"};
	int nColWidth[] = {100,100,50,100,200};
	for (int nCol=0; nCol<sizeof(strHeader)/sizeof(CString); nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nColWidth[nCol]);

	m_ListCtrl.DeleteAllItems();		// 删除所有的列表项

	CStudentSet sSet;
	sSet.m_strFilter = strFilter;
	sSet.m_strSort = strSort;
	sSet.Open();
	int nItem = 0;
	CString str;
	while (!sSet.IsEOF())
	{
		m_ListCtrl.InsertItem( nItem, sSet.m_studentno);		// 插入学号
		m_ListCtrl.SetItemText( nItem, 1, sSet.m_studentname);	// 设置姓名
		// 通过Get获取相关字段记录内容
		if (sSet.m_xb)
			m_ListCtrl.SetItemText( nItem, 2, "男");	// 设置性别
		else
			m_ListCtrl.SetItemText( nItem, 2, "女");	// 设置性别


		for (UINT i=3; i<sSet.m_nFields; i++)
		{
			sSet.GetFieldValue(i, str);			// 获取指定字段值
			m_ListCtrl.SetItemText( nItem, i, str);	
		}
		sSet.MoveNext();
		nItem++;
	}
	if (sSet.IsOpen()) sSet.Close();
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


void CEx_StudentView::DispCourseInfo(CString strFilter, CString strSort)
{
	DeleteAllColumn();	// 删除表头
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strHeader[]={"课程号","所属专业", "课程名称","课程类别","开课学期","课时数","学分"};
	int nLong[] = {80, 180, 180, 80, 80, 80, 80};
	for (int nCol=0; nCol<sizeof(strHeader)/sizeof(CString); nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nLong[nCol]);
	m_ListCtrl.DeleteAllItems();		// 删除所有的列表项

	CCourseSet sSet;
	sSet.m_strFilter = strFilter;
	sSet.m_strSort = strSort;
	sSet.Open();
	int nItem = 0;
	CString str;
	while (!sSet.IsEOF())
	{
		m_ListCtrl.InsertItem( nItem, sSet.m_courseno);		// 插入课程号
		// 通过Get获取相关字段记录内容
		for (UINT i=1; i<sSet.m_nFields; i++)
		{
			sSet.GetFieldValue(i, str);			// 获取指定字段值
			m_ListCtrl.SetItemText( nItem, i, str);	
		}
		sSet.MoveNext();
		nItem++;
	}
	if (sSet.IsOpen()) sSet.Close();
}

void CEx_StudentView::DispScoreAndCourseInfo(CString strFilter, CString strFilter2)
{
	DeleteAllColumn();	// 删除表头
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strHeader[]={"学号", "课程号","课程所属专业", "课程名称","课程类别","开课学期","课时数","学分","成绩"};
	int nLong[] = {80, 80, 180, 180, 80, 80, 80, 80, 80};
	for (int nCol=0; nCol<sizeof(strHeader)/sizeof(CString); nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nLong[nCol]);
	m_ListCtrl.DeleteAllItems();		// 删除所有的列表项

	CScoreSet sSet;
	sSet.m_strFilter = strFilter;
	sSet.Open();
	int nItem = 0;
	CString str;
	while (!sSet.IsEOF())
	{
		CCourseSet cSet;
		cSet.m_strFilter.Format("courseno='%s' %s", sSet.m_course, strFilter2);
		cSet.Open();
		UINT i;
		// 通过Get获取相关字段记录内容
		if (!cSet.IsEOF()) {
			m_ListCtrl.InsertItem( nItem, sSet.m_studentno);		// 插入学号
			m_ListCtrl.SetItemText( nItem, 1, sSet.m_course);
			for (i=1; i<cSet.m_nFields; i++)
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
	if (sSet.IsOpen()) sSet.Close();
}

void CEx_StudentView::DispScoreAndCourseInfo2(CString strSpecFilter, CString strFilter2)
{
	DeleteAllColumn();	// 删除表头
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strHeader[]={"学号", "课程号", "课程所属专业", "课程名称","课程类别","开课学期","课时数","学分","成绩"};
	int nLong[] = {80, 80, 180, 180, 80, 80, 80, 80, 80};
	for (int nCol=0; nCol<sizeof(strHeader)/sizeof(CString); nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nLong[nCol]);
	m_ListCtrl.DeleteAllItems();		// 删除所有的列表项

	CStudentSet sSet;
	sSet.m_strFilter = strSpecFilter;
	sSet.m_strSort = "studentno";
	sSet.Open();
	int nItem = 0;
	CString str;
	while (!sSet.IsEOF())
	{
		CScoreSet oSet;
		oSet.m_strFilter.Format("studentno='%s'", sSet.m_studentno);
		oSet.Open();
		while (!oSet.IsEOF())
		{

			CCourseSet cSet;
			cSet.m_strFilter.Format("courseno='%s' %s", oSet.m_course, strFilter2);
			cSet.Open();
			UINT i;
			// 通过Get获取相关字段记录内容
			if (!cSet.IsEOF()) {
				m_ListCtrl.InsertItem( nItem, oSet.m_studentno);		// 插入学号
				for (i=0; i<cSet.m_nFields; i++)
				{
					cSet.GetFieldValue(i, str);			// 获取指定字段值
					m_ListCtrl.SetItemText( nItem, i+1, str);	
				}
				str.Format("%0.1f", oSet.m_score);
				m_ListCtrl.SetItemText( nItem, i+1, str);	
				nItem++;
			}
			cSet.Close();
			oSet.MoveNext();
		}

		oSet.Close();
		sSet.MoveNext();
	}
	if (sSet.IsOpen()) sSet.Close();
}

void CEx_StudentView::OnOpChange() 
{
	// TODO: Add your command handler code here
	// 判断是否有选择的列表项
	CListCtrl& m_ListCtrl = GetListCtrl();
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox("你还没有选中列表项！");
		return;
	}
	int nItem = m_ListCtrl.GetNextSelectedItem( pos );

	CEx_StudentDoc* pDoc = GetDocument();

	if (pDoc->m_nInfoType == 1)
		ChangeStudentInfo(nItem);
	else if (pDoc->m_nInfoType == 2)
		ChangeCourseInfo(nItem);
	else if (pDoc->m_nInfoType == 3)
		ChangeScoreInfo(nItem);
	
}

void CEx_StudentView::OnOpDel() 
{
	// TODO: Add your command handler code here
	CListCtrl& m_ListCtrl = GetListCtrl();
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox("你还没有选中列表项！");
		return;
	}
	int nItem = m_ListCtrl.GetNextSelectedItem( pos );
	CString strItem;
	strItem = m_ListCtrl.GetItemText( nItem, 0 );
	CString str;
	str.Format("你确实要删除 %s 列表项(记录)吗？", strItem );
	if ( IDOK != MessageBox(str, "删除确认", MB_ICONQUESTION | MB_OKCANCEL ))
		return;


	CEx_StudentDoc* pDoc = GetDocument();

	if (pDoc->m_nInfoType == 1)
		DelStudentInfo(nItem);
	else if (pDoc->m_nInfoType == 2)
		DelCourseInfo(nItem);
	else if (pDoc->m_nInfoType == 3)
		DelScoreInfo(nItem);
	DispStatusRecord();
}

void CEx_StudentView::ChangeStudentInfo(int nItem)
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strStuNO = m_ListCtrl.GetItemText( nItem, 0 );
	strStuNO.TrimLeft();
	CStudentSet sSet;
	sSet.m_strFilter.Format("studentno = '%s'", strStuNO);
	sSet.Open();

	CStuInfoDlg dlg;
	dlg.m_strPhotoFilePath.Format("c://%s.bmp", strStuNO);
	dlg.m_strNO		= strStuNO;
	dlg.m_strName	= sSet.m_studentname;
	dlg.m_bSex		= sSet.m_xb;
	dlg.m_tBirth	= sSet.m_birthday;
	dlg.m_strSpecial= sSet.m_special;
	dlg.m_strOKText	= "修改";
	if (IDOK != dlg.DoModal())
	{
		if (sSet.IsOpen()) sSet.Close();
		return;
	}
	sSet.Edit();

	sSet.m_studentname	= dlg.m_strName;
//	sSet.m_studentno	= dlg.m_strNO;		// 禁止修改学号
	sSet.m_xb			= dlg.m_bSex;
	sSet.m_birthday		= dlg.m_tBirth;
	sSet.m_special		= dlg.m_strSpecial;

	sSet.Update();
	sSet.Requery();

	if (sSet.IsOpen()) sSet.Close();
	// 在这里复制照片文件
	if (dlg.m_bPhotoChange) {
		CString strFileTO;
		strFileTO.Format("c://%s.bmp", dlg.m_strNO);
		GetDocument()->DoCopyFile(strFileTO, dlg.m_strPhotoFilePath);
	}

	// 更新视图
	MessageBox("稍等几秒钟后，单击[确定]按钮！",
		"特别提示",MB_OK|MB_ICONINFORMATION);
	GetDocument()->UpdateAllViews( NULL, 2, (CObject *)new CString(dlg.m_strNO) );
}

void CEx_StudentView::ChangeCourseInfo(int nItem)
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strCourseNO = m_ListCtrl.GetItemText( nItem, 0 );
	strCourseNO.TrimLeft();
	CCourseSet sSet;
	sSet.m_strFilter.Format("courseno = '%s'", strCourseNO);
	sSet.Open();

	CCourseDlg dlg;
	dlg.m_strOKText = "修改";
	dlg.m_strNO		= sSet.m_courseno;
	dlg.m_strName	= sSet.m_coursename;
	dlg.m_strType	= sSet.m_coursetype;
	dlg.m_nOpen		= sSet.m_openterm;
	dlg.m_nHours	= (int)sSet.m_hours;
	dlg.m_fCredit	= sSet.m_credit;

	if (IDOK != dlg.DoModal())
	{
		if (sSet.IsOpen()) sSet.Close();
		return;
	}
	sSet.Edit();
	//sSet.m_courseno		= dlg.m_strNO;
	sSet.m_coursename		= dlg.m_strName;
	sSet.m_coursetype		= dlg.m_strType;
	sSet.m_openterm			= dlg.m_nOpen;
	sSet.m_hours			= BYTE(dlg.m_nHours);
	sSet.m_credit			= dlg.m_fCredit;

	sSet.Update();
	sSet.Requery();
	if (sSet.IsOpen()) sSet.Close();
	// 更新列表视图
	MessageBox("稍等几秒钟后，单击[确定]按钮！",
		"特别提示",MB_OK|MB_ICONINFORMATION);
	GetDocument()->UpdateAllViews( NULL, 2, (CObject *)new CString(dlg.m_strNO) );
}

void CEx_StudentView::ChangeScoreInfo(int nItem)
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strStudentNO = m_ListCtrl.GetItemText( nItem, 0 );
	CString strCourseNO = m_ListCtrl.GetItemText( nItem, 1 );

	CScoreSet sSet;
	sSet.m_strFilter.Format("studentno='%s' AND course='%s'", strStudentNO, strCourseNO);
	sSet.Open();

	CScoreDlg dlg;
	dlg.m_strOKText = "修改";
	dlg.m_strCourseNO	= sSet.m_course;
	dlg.m_strStudentNO	= sSet.m_studentno;
	dlg.m_fScore		= sSet.m_score;

	if (IDOK != dlg.DoModal())
	{
		if (sSet.IsOpen()) sSet.Close();
		return;
	}
	sSet.Edit();
	sSet.m_score		= dlg.m_fScore;

	sSet.Update();
	sSet.Requery();
	if (sSet.IsOpen()) sSet.Close();

	// 更新列表视图
	MessageBox("稍等几秒钟后，单击[确定]按钮！",
		"特别提示",MB_OK|MB_ICONINFORMATION);
	GetDocument()->UpdateAllViews( NULL, 2, (CObject *)new CString(strStudentNO) );
}

void CEx_StudentView::DelStudentInfo(int nItem)
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strStuNO = m_ListCtrl.GetItemText( nItem, 0 );
	strStuNO.TrimLeft();
	CStudentSet infoSet;
	infoSet.m_strFilter.Format("studentno = '%s'", strStuNO);
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
	MessageBox("稍等几秒钟后，单击[确定]按钮！",
		"特别提示",MB_OK|MB_ICONINFORMATION);
	GetDocument()->UpdateAllViews( NULL, 3, (CObject *)new CString(strStuNO) );
}

void CEx_StudentView::DelScoreInfo(int nItem)
{
	CListCtrl& m_ListCtrl = GetListCtrl();
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
	MessageBox("稍等几秒钟后，单击[确定]按钮！",
		"特别提示",MB_OK|MB_ICONINFORMATION);
	GetDocument()->UpdateAllViews( NULL, 3, (CObject *)new CString(strStudentNO) );
}

void CEx_StudentView::DelCourseInfo(int nItem)
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strCourseNO = m_ListCtrl.GetItemText( nItem, 0 );
	strCourseNO.TrimLeft();
	CCourseSet infoSet;
	infoSet.m_strFilter.Format("courseno = '%s'", strCourseNO);
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
	MessageBox("稍等几秒钟后，单击[确定]按钮！",
		"特别提示",MB_OK|MB_ICONINFORMATION);
	GetDocument()->UpdateAllViews( NULL, 3, (CObject *)new CString(strCourseNO) );
}
void CEx_StudentView::ReadListViewData()
{
	m_strContents.RemoveAll();
	CListCtrl& m_ListCtrl = GetListCtrl();
	int nCount = 0;
	CHeaderCtrl* pHeaderCtrl = m_ListCtrl.GetHeaderCtrl();
	if ( pHeaderCtrl!= NULL)
		nCount = pHeaderCtrl->GetItemCount();

	// 读取表头信息作为第一行
	LVCOLUMN	column;
	TCHAR		lpBuffer[256];
	int			nWidthCharNum[100];

	CString str, strTemp;
	for (int nCol = 0; nCol < nCount; nCol++)
	{
		column.mask			= LVCF_TEXT; 
		column.pszText		= lpBuffer;
		column.cchTextMax	= 256;
		m_ListCtrl.GetColumn( nCol, &column );
		nWidthCharNum[nCol] = (int)(m_ListCtrl.GetColumnWidth( nCol )/6.5);
		strTemp.Format("%s", lpBuffer);
		strTemp.TrimRight();
		int nDelta = nWidthCharNum[nCol] - strTemp.GetLength();
		if (nDelta>0)
			strTemp = AppendStringSpace( strTemp, nDelta);
		else
			strTemp = strTemp.Left(nWidthCharNum[nCol]);
		str = str + strTemp;
	}
	str.TrimRight();
	m_strContents.Add( str );
	// 读取各个列表项信息
	int nItemCount = m_ListCtrl.GetItemCount();
	for ( int nItem=0; nItem<nItemCount; nItem++)
	{
		str.Empty();
		strTemp.Empty();
		for (int i=0; i<nCount; i++ )
		{
			strTemp = m_ListCtrl.GetItemText(nItem, i);
			strTemp.TrimRight();
			int nDelta = nWidthCharNum[i] - strTemp.GetLength();
			if (nDelta>0)
				strTemp = AppendStringSpace( strTemp, nDelta);
			else
				strTemp = strTemp.Left(nWidthCharNum[i]);
			str = str + strTemp;
		}
		str.TrimRight();
		m_strContents.Add( str );
	}

}

void CEx_StudentView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	ReadListViewData();
	pDC->SetMapMode(MM_LOMETRIC);	// 单位0.1mm
	CListView::OnPrepareDC(pDC, pInfo);
	int nSize = m_strContents.GetSize();
	if ((pInfo)&&(nSize)){
		if (pInfo->m_nCurPage<= pInfo->GetToPage()) 
			pInfo-> m_bContinuePrinting = TRUE;
		else 
			pInfo-> m_bContinuePrinting = FALSE;
	} 
}

void CEx_StudentView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	CFont font;
	font.CreateFontIndirect(&m_pageInfo.lfText);
	CFont* oldFont = pDC->SelectObject(&font);		// 设置正文字体
	SetPageInfo(pDC, pInfo, &m_pageInfo, 250, 250, 250, 250, 35);	// 设置页边距和行距
	PrintHead(pDC, pInfo, m_pageInfo, "学生成绩管理系统，设计者：丁有和", 200, -1);	// 打印页眉
	CString str;
	str.Format("- %d -", pInfo->m_nCurPage);
	PrintFoot(pDC, pInfo, m_pageInfo, str, 200, 0);	// 打印页脚

	if (m_strContents.GetSize() < 1)	return;		// 没有文档内容则返回

	AdjustAllLine(pDC);	// 调整每行的文本

	int nIndex = pInfo->m_nCurPage - 1;
	int nStartLine = m_nLineArray.GetAt(nIndex);

	CRect rc = pInfo->m_rectDraw;
	int y = rc.top;
	int nHeight = m_pageInfo.sizeLine.cy;
	int tab = m_pageInfo.sizeChar.cx * 4;				// 为一个TAB设置4个字符
	while (y >= pInfo->m_rectDraw.bottom) 
	{
		str =  m_arrText.GetAt(nStartLine);
		rc.top = y;
		pDC->TabbedTextOut(rc.left, y, str, 1, &tab, rc.left);  

		nStartLine++;
		if (nStartLine >= m_arrText.GetSize()) 
		{
			pInfo->SetMaxPage(pInfo->m_nCurPage);
			pInfo->m_pPD->m_pd.nToPage = pInfo->m_nCurPage;
			break;
		}

		y -= nHeight;
	}

	if (nIndex >= (m_nLineArray.GetSize() - 1)) 
		m_nLineArray.Add(nStartLine);	// 保存下一页的起始行号
	pDC->SelectObject(oldFont);
	
	CListView::OnPrint(pDC, pInfo);
}

void CEx_StudentView::SetPageInfo(CDC *pDC, CPrintInfo *pInfo, PAGEINFO *pPage, int l, int t, int r, int b, int nLineSpace)
{
	// nLineSpace为行间距，l,t,r,b分别表示左上右下的页边距
	// 计算一个设备单位等于多少0.1mm
	double scaleX = 254.0/(double)GetDeviceCaps(pDC->m_hAttribDC, LOGPIXELSX);
	double scaleY = 254.0/(double)GetDeviceCaps(pDC->m_hAttribDC, LOGPIXELSY);

	int x = GetDeviceCaps(pDC->m_hAttribDC, PHYSICALOFFSETX);	
	int y = GetDeviceCaps(pDC->m_hAttribDC, PHYSICALOFFSETY);	
	int w = GetDeviceCaps(pDC->m_hAttribDC, PHYSICALWIDTH);	
	int h = GetDeviceCaps(pDC->m_hAttribDC, PHYSICALHEIGHT);	

	int nPageWidth = (int)((double)w*scaleX + 0.5);		// 纸宽，单位0.1mm 
	int nPageHeight = (int)((double)h*scaleY + 0.5);		// 纸高，单位0.1mm 

	int nPhyLeft = (int)((double)x*scaleX + 0.5);			// 物理左边距，单位0.1mm 
	int nPhyTop = (int)((double)y*scaleY + 0.5);			// 物理上边距，单位0.1mm 

	CRect rcTemp = pInfo->m_rectDraw;
	rcTemp.NormalizeRect();

	int nPhyRight = nPageWidth - rcTemp.Width() - nPhyLeft;	// 物理右边距，单位0.1mm
	int nPhyBottom = nPageHeight - rcTemp.Height() - nPhyTop;	// 物理下边距，单位0.1mm

	// 若边距小于物理边距，则调整它们
	if (l < nPhyLeft) l = nPhyLeft;
	if (t < nPhyTop) t = nPhyTop;
	if (r < nPhyRight) r = nPhyRight;
	if (b < nPhyBottom) b = nPhyBottom;

	pPage->nLMargin = l;
	pPage->nRMargin = r;
	pPage->nTMargin = t;
	pPage->nBMargin = b;
	pPage->nPhyLeft = nPhyLeft;
	pPage->nPhyRight = nPhyRight;
	pPage->nPhyTop = nPhyTop;
	pPage->nPhyBottom = nPhyBottom;

	pPage->sizePage = CSize(nPageWidth, nPageHeight);

	// 计算并调整pInfo->m_rectDraw的大小
	pInfo->m_rectDraw.left = l - nPhyLeft;
	pInfo->m_rectDraw.top  = - t + nPhyTop;
	pInfo->m_rectDraw.right -= r - nPhyRight;
	pInfo->m_rectDraw.bottom += b - nPhyBottom;

	// 计算字符的大小
	pPage->sizeChar = pDC->GetTextExtent("G");
	// 计算行的大小
	pPage->sizeLine = CSize(pInfo->m_rectDraw.Width(), pPage->sizeChar.cy + nLineSpace);
}

void CEx_StudentView::PrintHead(CDC *pDC, CPrintInfo *pInfo, PAGEINFO page, CString title, int margin, int mode)
{
	// mode表示页眉文本对齐模式，0为居中，>0表示右对齐，<0表示左对齐
	// title表示页眉内容， margin为页眉与顶边的距离
	CFont font;
	font.CreateFontIndirect(&page.lfHead);
	CFont* oldFont = pDC->SelectObject(&font);

	CSize strSize = pDC->GetTextExtent(title);
	CRect rc = pInfo->m_rectDraw;
	CPoint pt;

	margin = margin - page.nPhyTop;
	if (margin<0) margin = 0;

	// 根据mode计算绘制页眉文本的起点
	if (mode < 0) pt = CPoint(rc.left, -margin);
	if (mode == 0) pt = CPoint(rc.CenterPoint().x - strSize.cx/2, -margin);
	if (mode > 0) pt = CPoint(rc.right - strSize.cx, -margin);

	pDC->TextOut(pt.x, pt.y, title);	// 绘制页眉文本
	pt.y -= strSize.cy + 5;
	pDC->MoveTo(rc.left, pt.y);		// 画线
	pDC->LineTo(rc.right, pt.y);
	pt.y -= 10;
	int absY = pt.y>0 ? pt.y : -pt.y;
	
	if (absY > page.nTMargin) pInfo->m_rectDraw.top = pt.y; 

	pDC->SelectObject(oldFont);
	font.DeleteObject();
}

void CEx_StudentView::PrintFoot(CDC *pDC, CPrintInfo *pInfo, PAGEINFO page, CString title, int margin, int mode)
{
	// mode表示页脚文本对齐模式，0为居中，>0表示右对齐，<0表示左对齐
	// title表示页脚内容， margin为页脚与底边的距离
	CFont font;
	font.CreateFontIndirect(&page.lfFoot);
	CFont* oldFont = pDC->SelectObject(&font);

	CSize strSize = pDC->GetTextExtent(title);
	CRect rc = pInfo->m_rectDraw;
	CPoint pt;

	margin = page.nBMargin - margin - strSize.cy;

	// 根据mode计算绘制页眉文本的起点
	if (mode < 0) pt = CPoint(rc.left, rc.bottom - margin);
	if (mode == 0) pt = CPoint(rc.CenterPoint().x - strSize.cx/2,  rc.bottom - margin);
	if (mode > 0) pt = CPoint(rc.right - strSize.cx,  rc.bottom - margin);

	pDC->TextOut(pt.x, pt.y, title);	// 绘制页脚文本

	if (margin < 0) 
		pInfo->m_rectDraw.bottom -= margin;

	pDC->SelectObject(oldFont);
}

void CEx_StudentView::AdjustAllLine(CDC *pDC)
{
	int nLineNums =  m_strContents.GetSize();		// 文档总行数

	int tab = m_pageInfo.sizeChar.cx * 4;			// 为一个TAB设置4个字符

	// 将文档的每一行作换行处理，只处理一次，以提高预览速度
	// 处理的结果保存在arrText中
	CString str;
	m_arrText.RemoveAll();
	CSize strSize;
	for (int i=0; i<nLineNums; i++) 
	{
		str = m_strContents.GetAt(i);
		strSize = pDC->GetTabbedTextExtent(str, 1, &tab);
		CString strTemp = str;
		while ( strSize.cx > m_pageInfo.sizeLine.cx) {

			unsigned int pos = 0;
			for (pos = 0; pos<strlen(strTemp); pos++) {
				CSize size = pDC->GetTabbedTextExtent(strTemp, pos+1, 1, &tab);
				if (size.cx >= m_pageInfo.sizeLine.cx) break;
			}

			// 判断汉字双字符是否被分开
			int nCharHZ = 0;
			for (unsigned int chIndex = 0; chIndex <= pos; chIndex++)
				if (strTemp.GetAt(chIndex) < 0) nCharHZ++;
			if (nCharHZ % 2) pos = pos - 1;

			m_arrText.Add(strTemp.Left(pos+1));
			strTemp = strTemp.Mid(pos+1);
			strSize = pDC->GetTabbedTextExtent(strTemp, 1, &tab);
		}
		m_arrText.Add(strTemp);
	}
	m_nLineArray.RemoveAll();
	m_nLineArray.Add(0);	
}

CString CEx_StudentView::AppendStringSpace(CString str, int nNum)
{
	for (int i=0; i<nNum; i++)
		str.Insert( 500, ' ');
	return str;
}


void CEx_StudentView::OnSelSeek() 
{
	// TODO: Add your command handler code here
	CSeekDlg dlg;
	
	CEx_StudentDoc* pDoc = GetDocument();
	if (pDoc->m_nInfoType == 1)
		dlg.m_strTitle = "选择学号：";
	else if (pDoc->m_nInfoType == 2)
		dlg.m_strTitle = "选择课程号：";
	else if (pDoc->m_nInfoType == 3) {
		dlg.m_strTitle = "选择学号：";
		dlg.m_bTerm = TRUE;
	}

	// 获取列表项第一列内容
	CString strTemp;
	CListCtrl& m_ListCtrl = GetListCtrl();
	int nItemCount = m_ListCtrl.GetItemCount();
	dlg.m_strItemArray.RemoveAll();
	for ( int nItem=0; nItem<nItemCount; nItem++)
	{
		strTemp = m_ListCtrl.GetItemText(nItem, 0);
		dlg.m_strItemArray.Add( strTemp );
	}

	if (IDOK != dlg.DoModal()) return;

	CString str;
	if (pDoc->m_nInfoType == 1)
	{
		str.Format("studentno = '%s'", dlg.m_strSeek);
		DispStudentInfo( str, "studentno");
	}
	else if (pDoc->m_nInfoType == 2)
	{
		str.Format("courseno = '%s'", dlg.m_strSeek);
		DispCourseInfo( str, "");
	}
	else if (pDoc->m_nInfoType == 3)
	{
		str.Format("studentno = '%s'", dlg.m_strSeek);
		DispScoreAndCourseInfo( str);
	}
	DispStatusRecord();
}

void CEx_StudentView::OnSelStat() 
{
	// TODO: Add your command handler code here
	// 获取列表项第一列内容
	CListCtrl& m_ListCtrl = GetListCtrl();
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox("你还没有选中列表项！");
		return;
	}
	int nItem = m_ListCtrl.GetNextSelectedItem( pos );
	CStatDlg dlg;
	dlg.m_strNO = m_ListCtrl.GetItemText(nItem, 0);
	dlg.DoModal();
}

void CEx_StudentView::DispStatusRecord()
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	int nItemCount = m_ListCtrl.GetItemCount();
	CString str;
	CMainFrame* pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd; 	// 获得主窗口指针
	CStatusBar* pStatus=&pFrame->m_wndStatusBar; 		// 获得主窗口中的状态栏指针
	if (pStatus) {
		str.Format("当前记录数：%d",nItemCount);		// 格式化文本
		pStatus->SetPaneText(1,str);					// 更新第二个窗格的文本
	}	

}

void CEx_StudentView::OnUpdateSelStat(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CEx_StudentDoc* pDoc = GetDocument();
	BOOL bEnable = FALSE;
	if (pDoc->m_nInfoType == 3) bEnable = TRUE;
	pCmdUI->Enable( bEnable );	
}
