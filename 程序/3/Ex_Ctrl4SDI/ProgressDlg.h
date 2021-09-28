#if !defined(AFX_PROGRESSDLG_H__D46DFE1A_5A83_41FD_8CF0_F0E57D9DF153__INCLUDED_)
#define AFX_PROGRESSDLG_H__D46DFE1A_5A83_41FD_8CF0_F0E57D9DF153__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProgressDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg dialog

class CProgressDlg : public CDialog
{
// Construction
public:
	void UpdatePercentText();
	CProgressDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProgressDlg)
	enum { IDD = IDD_PROGRESS };
	CProgressCtrl	m_Progress;
	CString	m_strPercent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgressDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProgressDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonBack();
	afx_msg void OnButtonGoon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRESSDLG_H__D46DFE1A_5A83_41FD_8CF0_F0E57D9DF153__INCLUDED_)
