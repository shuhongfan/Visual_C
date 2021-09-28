// Ex_CtrlsDlg.h : header file
//

#if !defined(AFX_EX_CTRLSDLG_H__78DDEF1D_4C50_42A5_B3CE_644E43D5F98E__INCLUDED_)
#define AFX_EX_CTRLSDLG_H__78DDEF1D_4C50_42A5_B3CE_644E43D5F98E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_CtrlsDlg dialog

class CEx_CtrlsDlg : public CDialog
{
// Construction
public:
	CEx_CtrlsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_CtrlsDlg)
	enum { IDD = IDD_EX_CTRLS_DIALOG };
	CListBox	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_CtrlsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_CtrlsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonCourse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTRLSDLG_H__78DDEF1D_4C50_42A5_B3CE_644E43D5F98E__INCLUDED_)
