// StuInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ex_student.h"
#include "StuInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg dialog


CStuInfoDlg::CStuInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStuInfoDlg::IDD, pParent)
{
	m_bMale = FALSE;
	//{{AFX_DATA_INIT(CStuInfoDlg)
	m_strName = _T("");
	m_strNo = _T("");
	m_tBirth = 0;
	m_strSpecial = _T("");
	//}}AFX_DATA_INIT
}


void CStuInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStuInfoDlg)
	DDX_Control(pDX, IDC_COMBO_SPECIAL, m_comboSpecial);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NO, m_strNo);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_tBirth);
	DDX_CBString(pDX, IDC_COMBO_SPECIAL, m_strSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStuInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CStuInfoDlg)
	ON_BN_CLICKED(IDC_RADIO_MALE, OnRadioMale)
	ON_BN_CLICKED(IDC_RADIO_FEMALE, OnRadioFemale)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg message handlers

BOOL CStuInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 设置单选按钮初始选中状态
	if (!m_bMale)
		CheckRadioButton(IDC_RADIO_MALE, IDC_RADIO_FEMALE, IDC_RADIO_FEMALE);
	else
		CheckRadioButton(IDC_RADIO_MALE, IDC_RADIO_FEMALE, IDC_RADIO_MALE);

	// 这里对专业组合框进行初如化
	m_comboSpecial.AddString( "机械工程及其自动化" );
	m_comboSpecial.AddString( "电气工程及其自动化" );
	m_comboSpecial.AddString( "计算机科学" );
	m_strSpecial = "计算机科学";

	// 对出生年月初始化
	m_tBirth = CTime(1986, 1, 1, 0, 0, 0);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStuInfoDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	m_strName.TrimLeft();
	m_strNo.TrimLeft();
	if (m_strName.IsEmpty())
		MessageBox("必须要有姓名！");
	else if (m_strNo.IsEmpty())
		MessageBox("必须要有学号！");
	else 
		CDialog::OnOK();
}

void CStuInfoDlg::OnRadioMale() 
{
	// TODO: Add your control notification handler code here
	m_bMale = TRUE;
}

void CStuInfoDlg::OnRadioFemale() 
{
	// TODO: Add your control notification handler code here
	m_bMale = FALSE;	
}
