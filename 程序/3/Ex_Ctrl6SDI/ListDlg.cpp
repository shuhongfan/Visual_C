// ListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Ctrl6SDI.h"
#include "ListDlg.h"
#include "StuInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListDlg dialog


CListDlg::CListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CListDlg, CDialog)
	//{{AFX_MSG_MAP(CListDlg)
	ON_BN_CLICKED(IDC_RADIO_LARGE, OnRadioLarge)
	ON_BN_CLICKED(IDC_RADIO_SMALL, OnRadioSmall)
	ON_BN_CLICKED(IDC_RADIO_LIST, OnRadioList)
	ON_BN_CLICKED(IDC_RADIO_REPORT, OnRadioReport)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListDlg message handlers

void CListDlg::SetCtrlStyle(HWND hWnd, DWORD dwNewStyle)
{
	DWORD	dwOldStyle;
	dwOldStyle = GetWindowLong(hWnd, GWL_STYLE);		// ��ȡ��ǰ���
	if ((dwOldStyle&LVS_TYPEMASK) != dwNewStyle) 
	{
		dwOldStyle &= ~LVS_TYPEMASK;
		dwNewStyle |= dwOldStyle;
		SetWindowLong(hWnd, GWL_STYLE, dwNewStyle);		// �����·��
	}
}

BOOL CListDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// ���õ�ѡ��ť���ʼѡ��״̬
	CheckRadioButton(IDC_RADIO_LARGE, IDC_RADIO_REPORT, IDC_RADIO_REPORT);
	// ���б�ؼ�����Ϊ��������ʾ��ʽ
	SetCtrlStyle( m_ListCtrl.m_hWnd, LVS_REPORT );
	// �����б�ؼ��ı���ͷ
	CString strHeader[5]={"ѧ��", "����",  "�Ա�", "��������", "רҵ"};
	int nWidth[5] = {80, 100, 60, 100, 200};
	for (int nCol=0; nCol<5; nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nWidth[nCol]);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CListDlg::OnRadioLarge() 
{
	// TODO: Add your control notification handler code here
	SetCtrlStyle( m_ListCtrl.m_hWnd, LVS_ICON );
	
}

void CListDlg::OnRadioSmall() 
{
	// TODO: Add your control notification handler code here
	SetCtrlStyle( m_ListCtrl.m_hWnd, LVS_SMALLICON );
	
}

void CListDlg::OnRadioList() 
{
	// TODO: Add your control notification handler code here
	SetCtrlStyle( m_ListCtrl.m_hWnd, LVS_LIST );
	
}

void CListDlg::OnRadioReport() 
{
	// TODO: Add your control notification handler code here
	SetCtrlStyle( m_ListCtrl.m_hWnd, LVS_REPORT );
	
}

void CListDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	CStuInfoDlg dlg;
	if (IDOK != dlg.DoModal()) return;

	// ����ѧ�����ж�ѧ��������Ϣ�ǲ����Ѿ���ӹ�
	LVFINDINFO info;
	info.flags = LVFI_PARTIAL|LVFI_STRING;
	info.psz = dlg.m_strNo;
	if (m_ListCtrl.FindItem( &info ) != -1) // ���ҵ�
	{
		CString str;
		str.Format("ѧ��Ϊ%s��ѧ��������Ϣ����ӹ���", dlg.m_strNo);
		MessageBox(str);
		return;
	}
	// ���ѧ��������Ϣ
	int nIndex = m_ListCtrl.InsertItem(m_ListCtrl.GetItemCount(), dlg.m_strNo);
	m_ListCtrl.SetItemText( nIndex, 1, dlg.m_strName );
	if (dlg.m_bMale)
		m_ListCtrl.SetItemText( nIndex, 2, "��" );
	else
		m_ListCtrl.SetItemText( nIndex, 2, "Ů" );
	m_ListCtrl.SetItemText( nIndex, 3, dlg.m_tBirth.Format("%Y-%m-%d"));
	m_ListCtrl.SetItemText( nIndex, 4, dlg.m_strSpecial);
}
