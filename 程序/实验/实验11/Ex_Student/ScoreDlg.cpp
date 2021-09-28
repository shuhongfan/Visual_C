// ScoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Student.h"
#include "ScoreDlg.h"

#include "CourseSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg dialog


CScoreDlg::CScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScoreDlg)
	m_fCredit = 0.0f;
	m_fScore = 0.0f;
	m_strCourseNO = _T("");
	m_strStudentNO = _T("");
	m_strNO = _T("");
	m_strHours = _T("");
	m_strName = _T("");
	m_strOpen = _T("");
	m_strSpecial = _T("");
	//}}AFX_DATA_INIT
}


void CScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScoreDlg)
	DDX_Control(pDX, IDC_COMBO_NO, m_comboNO);
	DDX_Text(pDX, IDC_CREDIT, m_fCredit);
	DDX_Text(pDX, IDC_SCORE, m_fScore);
	DDX_Text(pDX, IDC_COURSENO, m_strCourseNO);
	DDV_MaxChars(pDX, m_strCourseNO, 7);
	DDX_Text(pDX, IDC_STUNO, m_strStudentNO);
	DDX_CBString(pDX, IDC_COMBO_NO, m_strNO);
	DDV_MaxChars(pDX, m_strNO, 7);
	DDX_Text(pDX, IDC_STATIC_HOURS, m_strHours);
	DDX_Text(pDX, IDC_STATIC_NAME, m_strName);
	DDX_Text(pDX, IDC_STATIC_OPEN, m_strOpen);
	DDX_Text(pDX, IDC_STATIC_SPECIAL, m_strSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScoreDlg, CDialog)
	//{{AFX_MSG_MAP(CScoreDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_NO, OnSelchangeComboNo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg message handlers

void CScoreDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	m_strStudentNO.TrimLeft();
	m_strCourseNO.TrimLeft();
	if (m_strStudentNO.IsEmpty())
		MessageBox("学号不能为空！");
	else 
		if (m_strCourseNO.IsEmpty())
			MessageBox("课程号不能为空！");
		else
			CDialog::OnOK();
}

BOOL CScoreDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 将课程信息表的课程号添加到组合框中
	CCourseSet cSet;
	cSet.Open();
	while (!cSet.IsEOF())
	{
		m_comboNO.AddString(cSet.m_courseno);	
		cSet.MoveNext();
	}
	if (cSet.IsOpen()) cSet.Close();

	// 确定组合框的当前选择项
	m_strCourseNO.TrimLeft();
	if (!m_strCourseNO.IsEmpty())
	{
		m_strNO = m_strCourseNO;
		UpdateData( FALSE );
		OnSelchangeComboNo();
	} else
	{
		m_comboNO.SetCurSel(0);
		OnSelchangeComboNo();
	}
	if (!m_strOKText.IsEmpty())
	{
		GetDlgItem(IDOK)->SetWindowText( m_strOKText );
		GetDlgItem( IDC_STUNO )->EnableWindow(FALSE);
		GetDlgItem( IDC_COURSENO )->EnableWindow(FALSE);
		GetDlgItem( IDC_COMBO_NO )->EnableWindow(FALSE);
		GetDlgItem( IDC_CREDIT )->EnableWindow(FALSE);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CScoreDlg::OnSelchangeComboNo() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_comboNO.GetCurSel();
	if (nIndex == CB_ERR) return;
	CString str;
	m_comboNO.GetLBText( nIndex, str);
	// 根据课程号查找course表中的记录	
	CCourseSet cSet;
	cSet.m_strFilter.Format("courseno='%s'", str);
	cSet.Open();
	if (!cSet.IsEOF())		// 如果打开记录集有记录
	{
		m_strNO = m_strCourseNO = str;
		m_strName = cSet.m_coursename;
		m_strHours.Format("%d", cSet.m_hours);
		m_strOpen.Format("%d", cSet.m_openterm);
		m_fCredit = cSet.m_credit;
		m_strSpecial = cSet.m_special;
		UpdateData(FALSE);
	}
	if (cSet.IsOpen()) cSet.Close();
}
