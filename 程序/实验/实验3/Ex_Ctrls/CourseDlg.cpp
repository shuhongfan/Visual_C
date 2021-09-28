// CourseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Ctrls.h"
#include "CourseDlg.h"

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
	m_strSpecial = _T("");
	m_strType = _T("");
	m_nHours = 0;
	m_strName = _T("");
	m_strNO = _T("");
	m_fCredit = 0.0f;
	m_nOpen = 0;
	//}}AFX_DATA_INIT
}


void CCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCourseDlg)
	DDX_Control(pDX, IDC_COMBO_SPECIAL, m_comboSpecial);
	DDX_Control(pDX, IDC_SPIN1, m_spinOpen);
	DDX_CBString(pDX, IDC_COMBO_SPECIAL, m_strSpecial);
	DDX_CBString(pDX, IDC_COMBO_TYPE, m_strType);
	DDX_Text(pDX, IDC_EDIT_COURSEHOURS, m_nHours);
	DDX_Text(pDX, IDC_EDIT_COURSENAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_COURSENO, m_strNO);
	DDX_Text(pDX, IDC_EDIT_CREDIT, m_fCredit);
	DDX_Text(pDX, IDC_EDIT_OPEN, m_nOpen);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCourseDlg, CDialog)
	//{{AFX_MSG_MAP(CCourseDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg message handlers

BOOL CCourseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_spinOpen.SetRange( 1, 8 );
	m_nHours = 60;
	m_fCredit = 2.0;
	m_nOpen = 1;
	m_strType = "ר��";
	// �����רҵ��Ͽ���г��绯
	m_comboSpecial.AddString( "��е���̼����Զ���" );
	m_comboSpecial.AddString( "�������̼����Զ���" );
	m_strSpecial = "��е���̼����Զ���";
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCourseDlg::OnOK() 
{
	UpdateData();
	m_strNO.TrimLeft();
	if (m_strNO.IsEmpty())
	{
		MessageBox("�γ̺Ų���Ϊ�գ�");
		return;
	}
	m_strName.TrimLeft();
	if (m_strName.IsEmpty())
	{
		MessageBox("�γ����Ʋ���Ϊ�գ�");
		return;
	}
	CDialog::OnOK();
}
