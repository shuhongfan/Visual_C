// LessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Modeless.h"
#include "LessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLessDlg dialog


CLessDlg::CLessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLessDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLessDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLessDlg, CDialog)
	//{{AFX_MSG_MAP(CLessDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLessDlg message handlers

void CLessDlg::OnOK() 
{
	// �����������ʹ�û�����Ի����������Ч
	DestroyWindow();		// ��ֹ�Ի�����ʾ
	delete this;			// ɾ���Ի����ͷ��ڴ�ռ�
	
	// CDialog::OnOK();		// ȥ��Ĭ�ϵĴ���
}

void CLessDlg::OnCancel() 
{
	// ��������ͷŴ���
	DestroyWindow();		// ��ֹ�Ի�����ʾ
	delete this;			// ɾ���Ի����ͷ��ڴ�ռ�
	
	// CDialog::OnCancel();	// ȥ��Ĭ�ϵĴ���
}
