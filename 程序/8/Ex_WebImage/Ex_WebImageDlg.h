// Ex_WebImageDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_EX_WEBIMAGEDLG_H__7AFF76F1_B1FE_4A3F_B309_F13B9CE62FB3__INCLUDED_)
#define AFX_EX_WEBIMAGEDLG_H__7AFF76F1_B1FE_4A3F_B309_F13B9CE62FB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_WebImageDlg dialog

class CEx_WebImageDlg : public CDialog
{
// Construction
public:
	CEx_WebImageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_WebImageDlg)
	enum { IDD = IDD_EX_WEBIMAGE_DIALOG };
	CWebBrowser2	m_WebBrowser;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_WebImageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_WebImageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnImageOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_WEBIMAGEDLG_H__7AFF76F1_B1FE_4A3F_B309_F13B9CE62FB3__INCLUDED_)
