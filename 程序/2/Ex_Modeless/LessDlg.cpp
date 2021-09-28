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
	// 添加其他代码使用户输入对话框的数据有效
	DestroyWindow();		// 终止对话框显示
	delete this;			// 删除对话框，释放内存空间
	
	// CDialog::OnOK();		// 去除默认的处理
}

void CLessDlg::OnCancel() 
{
	// 添加其它释放代码
	DestroyWindow();		// 终止对话框显示
	delete this;			// 删除对话框，释放内存空间
	
	// CDialog::OnCancel();	// 去除默认的处理
}
