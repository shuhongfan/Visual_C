// Ex_TestDlg.h : header file
//
//{{AFX_INCLUDES()
#include "ex_ocx.h"
//}}AFX_INCLUDES

#if !defined(AFX_EX_TESTDLG_H__EA92CDF3_1B44_4387_BFF5_E2986CC20819__INCLUDED_)
#define AFX_EX_TESTDLG_H__EA92CDF3_1B44_4387_BFF5_E2986CC20819__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_TestDlg dialog

class CEx_TestDlg : public CDialog
{
// Construction
public:
	CEx_TestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_TestDlg)
	enum { IDD = IDD_EX_TEST_DIALOG };
	CEx_OCX	m_OCX;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_TestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickExocxctrl1();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TESTDLG_H__EA92CDF3_1B44_4387_BFF5_E2986CC20819__INCLUDED_)
