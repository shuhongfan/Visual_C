// CourseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Student.h"
#include "CourseDlg.h"

#include "CourseSet.h"
#include "SpecialDlg.h"
#include "SpecialSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg dialog


CCourseDlg::CCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCourseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCourseDlg)
	m_strType = _T("");
	m_nHours = 0;
	m_strName = _T("");
	m_strNO = _T("");
	m_fCredit = 0.0f;
	m_strSpecial = _T("");
	m_nOpen = 0;
	//}}AFX_DATA_INIT
}


void CCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCourseDlg)
	DDX_Control(pDX, IDC_SPIN1, m_spinOpen);
	DDX_Control(pDX, IDC_COMBO_SPECIAL1, m_comboSpecial);
	DDX_CBString(pDX, IDC_COMBO_TYPE, m_strType);
	DDX_Text(pDX, IDC_EDIT_COURSEHOURS, m_nHours);
	DDX_Text(pDX, IDC_EDIT_COURSENAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_COURSENO, m_strNO);
	DDX_Text(pDX, IDC_EDIT_CREDIT, m_fCredit);
	DDX_CBString(pDX, IDC_COMBO_SPECIAL1, m_strSpecial);
	DDX_Text(pDX, IDC_EDIT_OPEN, m_nOpen);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCourseDlg, CDialog)
	//{{AFX_MSG_MAP(CCourseDlg)
	ON_BN_CLICKED(IDC_BUTTON_SPECIAL, OnButtonSpecial)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg message handlers

BOOL CCourseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_spinOpen.SetRange( 1, 8 );

	if (m_strOKText.IsEmpty())
	{
		m_nHours = 60;
		m_fCredit = 2.0;
		m_nOpen = 1;
		m_strType = "专修";
	} else
	{
		GetDlgItem(IDOK)->SetWindowText(m_strOKText);
		GetDlgItem(IDC_EDIT_COURSENO)->EnableWindow( FALSE );
	}
	UpdateData(FALSE);
	// TODO: Add extra initialization here
	// 更新专业
	ResetComboBox();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCourseDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	m_strNO.TrimLeft();
	if (m_strNO.IsEmpty())
	{
		MessageBox("课程号不能为空！");
		return;
	}
	m_strName.TrimLeft();
	if (m_strName.IsEmpty())
	{
		MessageBox("课程名称不能为空！");
		return;
	}
	CDialog::OnOK();
}

void CCourseDlg::OnButtonSpecial() 
{
	// TODO: Add your control notification handler code here
	CSpecialDlg dlg;
	dlg.DoModal();
	if (dlg.m_bUpdate) ResetComboBox();	
}

void CCourseDlg::ResetComboBox()
{
	m_comboSpecial.ResetContent();
	CSpecialSet cSet;
	cSet.m_strSort = "special";
	cSet.Open();
	while (!cSet.IsEOF())
	{
		m_comboSpecial.AddString( cSet.m_special );		
		cSet.MoveNext();
	}
	cSet.Close();
	if (m_strSpecial.IsEmpty())
		m_comboSpecial.SetCurSel(0);

}
