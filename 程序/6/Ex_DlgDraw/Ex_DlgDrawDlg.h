// Ex_DlgDrawDlg.h : header file
//

#if !defined(AFX_EX_DLGDRAWDLG_H__C7D6733E_08E2_4A1D_97D9_841DCD747CE8__INCLUDED_)
#define AFX_EX_DLGDRAWDLG_H__C7D6733E_08E2_4A1D_97D9_841DCD747CE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_DlgDrawDlg dialog

class CEx_DlgDrawDlg : public CDialog
{
// Construction
public:
	void DoDrawCtrl(void);
	CEx_DlgDrawDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_DlgDrawDlg)
	enum { IDD = IDD_EX_DLGDRAW_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DlgDrawDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_DlgDrawDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DLGDRAWDLG_H__C7D6733E_08E2_4A1D_97D9_841DCD747CE8__INCLUDED_)
