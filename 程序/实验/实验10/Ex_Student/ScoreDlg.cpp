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
	m_strOKText.Empty();
	//{{AFX_DATA_INIT(CScoreDlg)
	m_strCourseNo = _T("");
	m_fCredit = 0.0f;
	m_fScore = 0.0f;
	m_strStuNo = _T("");
	m_strTerm = _T("");
	m_strSpecial = _T("");
	m_strHours = _T("");
	m_strType = _T("");
	//}}AFX_DATA_INIT
}


void CScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScoreDlg)
	DDX_Control(pDX, IDC_COMBO_NAME, m_comboName);
	DDX_Text(pDX, IDC_EDIT_COURSENO, m_strCourseNo);
	DDX_Text(pDX, IDC_EDIT_CREDIT, m_fCredit);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_fScore);
	DDX_Text(pDX, IDC_EDIT_STUNO, m_strStuNo);
	DDX_Text(pDX, IDC_STATIC_TERM, m_strTerm);
	DDX_Text(pDX, IDC_STATIC_SPECIAL, m_strSpecial);
	DDX_Text(pDX, IDC_STATIC_HOURS, m_strHours);
	DDX_Text(pDX, IDC_STATIC_TYPE, m_strType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScoreDlg, CDialog)
	//{{AFX_MSG_MAP(CScoreDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_NAME, OnSelchangeComboName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg message handlers

void CScoreDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	m_strStuNo.TrimLeft();
	if (m_strStuNo.IsEmpty())	{
		MessageBox("学号不能为空！");		return;
	}
	m_strCourseNo.TrimLeft();
	if (m_strCourseNo.IsEmpty())	{
		MessageBox("课程号不能为空！");		return;
	}
	
	CDialog::OnOK();
}

BOOL CScoreDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	if (!m_strOKText.IsEmpty()) {
		GetDlgItem( IDOK )->SetWindowText( m_strOKText );
		GetDlgItem( IDC_COMBO_NAME )->EnableWindow( FALSE );
		GetDlgItem( IDC_EDIT_COURSENO )->EnableWindow( FALSE );
		GetDlgItem( IDC_EDIT_CREDIT )->EnableWindow( FALSE );
	} else {
		// 将课程信息表的课程名称添加到组合框中
		CCourseSet cSet;
		cSet.Open();
		while (!cSet.IsEOF())
		{
			int nIndex = m_comboName.AddString(cSet.m_coursename);	
			DWORD dCourseNo = atol(cSet.m_courseno);
			m_comboName.SetItemData( nIndex, dCourseNo );
			cSet.MoveNext();
		}
		if (cSet.IsOpen()) cSet.Close();
		m_comboName.SetCurSel(0);
		OnSelchangeComboName();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CScoreDlg::OnSelchangeComboName() 
{
	int nIndex = m_comboName.GetCurSel();
	if (nIndex == CB_ERR) return;
	CString str;
	m_comboName.GetLBText( nIndex, str);
	DWORD dCourseNo = m_comboName.GetItemData( nIndex );

	CCourseSet cSet;
	cSet.m_strFilter.Format("courseno='%u'", dCourseNo);
	cSet.Open();
	if (!cSet.IsEOF()){
		m_strType		= cSet.m_coursetype;
		m_strSpecial	= cSet.m_special;
		m_strHours.Format("%d", cSet.m_hours);
		m_strTerm.Format("%d", cSet.m_openterm);
		m_strCourseNo	= cSet.m_courseno;
		m_fCredit		= cSet.m_credit;
	}
	cSet.Close();
	UpdateData(FALSE);	
}
