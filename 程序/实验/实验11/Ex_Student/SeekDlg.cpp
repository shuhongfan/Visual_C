// SeekDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ex_student.h"
#include "SeekDlg.h"

#include "StudentSet.h"
#include "CourseSet.h"
#include "ScoreSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSeekDlg dialog


CSeekDlg::CSeekDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSeekDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSeekDlg)
	m_strTitle = _T("");
	m_strSeek = _T("");
	//}}AFX_DATA_INIT
	m_bTerm = FALSE;
}


void CSeekDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSeekDlg)
	DDX_Control(pDX, IDC_COMBO2, m_comboTerm);
	DDX_Control(pDX, IDC_COMBO1, m_comboSeek);
	DDX_Text(pDX, IDC_STATIC_SEEK, m_strTitle);
	DDX_CBString(pDX, IDC_COMBO1, m_strSeek);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSeekDlg, CDialog)
	//{{AFX_MSG_MAP(CSeekDlg)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSeekDlg message handlers

BOOL CSeekDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if (!m_strTitle.IsEmpty())
		UpdateData( FALSE );

	m_comboSeek.ResetContent();
	for (int i=0; i<m_strItemArray.GetSize(); i++)
	{
		int	nIndex = m_comboSeek.FindString( 0, m_strItemArray[i] );
		if (nIndex == CB_ERR)
			m_comboSeek.AddString(  m_strItemArray[i] );		
	}
	m_comboSeek.SetCurSel(0);
	m_comboTerm.ResetContent();
	CString strTerm;
	for (i=0; i<=8; i++)
	{
		if (i==0) strTerm = "所有学期";
		else
			strTerm.Format("第%d学期", i);
		int nIndex = m_comboTerm.AddString(strTerm);
		m_comboTerm.SetItemData( nIndex, i );
	}
	m_comboTerm.SetCurSel(0);
	OnSelchangeCombo2();
	GetDlgItem(IDC_STATIC_TERM)->EnableWindow( m_bTerm );
	GetDlgItem(IDC_COMBO2)->EnableWindow( m_bTerm );
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSeekDlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_comboTerm.GetCurSel();
	if (nIndex == CB_ERR) return;
	m_nTerm = m_comboTerm.GetItemData( nIndex );	
}
