// StatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ex_student.h"
#include "StatDlg.h"

#include "ScoreSet.h"
#include "CourseSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatDlg dialog


CStatDlg::CStatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStatDlg)
	m_strNum = _T("");
	m_strNO = _T("");
	//}}AFX_DATA_INIT
}


void CStatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStatDlg)
	DDX_Control(pDX, IDC_COMBO1, m_comboTerm);
	DDX_Text(pDX, IDC_STATIC_NUM, m_strNum);
	DDX_Text(pDX, IDC_STATIC_NO, m_strNO);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStatDlg, CDialog)
	//{{AFX_MSG_MAP(CStatDlg)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatDlg message handlers

BOOL CStatDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	UpdateData( FALSE );
	CString strTerm;
	for (int i=0; i<=8; i++)
	{
		if (i==0) strTerm = "所有学期";
		else
			strTerm.Format("第%d学期", i);
		int nIndex = m_comboTerm.AddString(strTerm);
		m_comboTerm.SetItemData( nIndex, i );
	}
	m_comboTerm.SetCurSel(0);
	OnSelchangeCombo1();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStatDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_comboTerm.GetCurSel();
	if (nIndex == CB_ERR) return;
	int nTerm = (unsigned char)m_comboTerm.GetItemData( nIndex );	

	// 根据学号和学期统计学分总数
	float fTotalCredit = 0;
	CScoreSet sSet;
	sSet.m_strFilter.Format("studentno='%s'", m_strNO );
	sSet.Open();
	while (!sSet.IsEOF())
	{
		if (nTerm == 0)
			fTotalCredit += sSet.m_credit;
		else
		{
			CCourseSet cSet;
			cSet.m_strFilter.Format("courseno='%s'", sSet.m_course );
			cSet.Open();
			if (!cSet.IsEOF()){
				if ( cSet.m_openterm == nTerm )
					fTotalCredit += sSet.m_credit;
			}
			cSet.Close();
		}
		sSet.MoveNext();
	}
	sSet.Close();
	m_strNum.Format("%5.1f", fTotalCredit);
	UpdateData( FALSE );
}
