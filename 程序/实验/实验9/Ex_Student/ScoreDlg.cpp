// ScoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Student.h"
#include "ScoreDlg.h"

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
	//}}AFX_DATA_INIT
}


void CScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScoreDlg)
	DDX_Text(pDX, IDC_EDIT_COURSENO, m_strCourseNo);
	DDX_Text(pDX, IDC_EDIT_CREDIT, m_fCredit);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_fScore);
	DDX_Text(pDX, IDC_EDIT_STUNO, m_strStuNo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScoreDlg, CDialog)
	//{{AFX_MSG_MAP(CScoreDlg)
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
	
	// TODO: Add extra initialization here
	if (!m_strOKText.IsEmpty())
		GetDlgItem( IDOK )->SetWindowText( m_strOKText );
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
