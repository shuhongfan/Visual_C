// SpecialDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ex_student.h"
#include "SpecialDlg.h"

#include "SpecialSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpecialDlg dialog


CSpecialDlg::CSpecialDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpecialDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpecialDlg)
	m_strSpecial = _T("");
	//}}AFX_DATA_INIT
}


void CSpecialDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpecialDlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_EDIT_SPECIAL, m_strSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpecialDlg, CDialog)
	//{{AFX_MSG_MAP(CSpecialDlg)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, OnButtonChange)
	ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpecialDlg message handlers

BOOL CSpecialDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bUpdate = FALSE;
	ResetListItem();	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSpecialDlg::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_List.GetCurSel();
	if (nIndex == LB_ERR) return;
	m_List.GetText( nIndex, m_strSpecial );
	UpdateData( FALSE );
	GetDlgItem(IDC_BUTTON_CHANGE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_DEL)->EnableWindow(TRUE);
}

void CSpecialDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_strSpecial.TrimLeft();
	m_strSpecial.TrimRight();
	if (m_strSpecial.IsEmpty()) {
		MessageBox( "Ҫ��ӵ�רҵ���Ʋ���Ϊ�գ�" );
		return;
	}
	// �ж���û����ӹ���רҵ
	CSpecialSet sSet;
	sSet.m_strFilter.Format("special='%s'", m_strSpecial);
	sSet.Open();
	BOOL bAdd = FALSE;
	if (sSet.IsEOF())
	{
		sSet.AddNew();
		sSet.m_special = m_strSpecial;
		sSet.Update();
		m_bUpdate = bAdd = TRUE;
	} else
		MessageBox( "��רҵ�Ѿ���ӹ���" );
	sSet.Close();

	MessageBox( "����[ȷ��]��ť�����б��" );

	if (bAdd) ResetListItem();	
}

void CSpecialDlg::OnButtonChange() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_strSpecial.TrimLeft();
	m_strSpecial.TrimRight();
	if (m_strSpecial.IsEmpty()) {
		MessageBox( "���޸ĵ�רҵ���Ʋ���Ϊ�գ�" );
		return;
	}
	// �ж���û�и�רҵ
	CSpecialSet sSet;
	sSet.m_strFilter.Format("special='%s'", m_strSpecial);
	sSet.Open();
	if (!sSet.IsEOF())
		MessageBox( "��ͼ�޸ĵ�רҵ�������ظ���" );
	sSet.Close();
	
	CString strSpecial;
	int nIndex = m_List.GetCurSel();
	if (nIndex == LB_ERR) return;
	m_List.GetText( nIndex, strSpecial );

	CSpecialSet cSet;
	cSet.m_strFilter.Format("special='%s'", strSpecial);
	cSet.Open();
	if (!cSet.IsEOF()) {
		cSet.Edit();
		cSet.m_special = m_strSpecial;
		cSet.Update();
		m_bUpdate = TRUE;
	}
	cSet.Close();
	MessageBox( "����[ȷ��]��ť�����б��" );
	ResetListItem();	
}

void CSpecialDlg::OnButtonDel() 
{
	// TODO: Add your control notification handler code here
	if (IDOK != MessageBox("��ȷ��Ҫɾ����ǰѡ�еļ�¼��","ɾ��ѯ��", MB_OKCANCEL|MB_ICONQUESTION) ) 
		return;
	int nIndex = m_List.GetCurSel();
	if (nIndex == LB_ERR) return;
	CString strSpecial;
	m_List.GetText( nIndex, strSpecial );
	strSpecial.TrimLeft();
	strSpecial.TrimRight();

	CSpecialSet sSet;
	sSet.m_strFilter.Format("special='%s'", strSpecial);
	sSet.Open();
	if (!sSet.IsEOF())
	{
		sSet.Delete();
		sSet.MoveFirst();
	}
	sSet.Close();

	MessageBox( "����[ȷ��]��ť�����б��" );
	m_bUpdate = TRUE;

	ResetListItem();
}

void CSpecialDlg::ResetListItem()
{
	while(m_List.GetCount() != 0)	
		m_List.DeleteString(0);		// ɾ���б���������б���
	CSpecialSet sSet;
	sSet.Open();
	while (!sSet.IsEOF())
	{
		int nIndex = m_List.AddString( sSet.m_special );
		sSet.MoveNext();
	}
	sSet.Close();
	m_strSpecial.Empty();
	UpdateData(FALSE);
	GetDlgItem(IDC_BUTTON_CHANGE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_DEL)->EnableWindow(FALSE);
}


