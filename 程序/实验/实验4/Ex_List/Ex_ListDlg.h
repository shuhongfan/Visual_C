// Ex_ListDlg.h : header file
//

#if !defined(AFX_EX_LISTDLG_H__5E45CB48_5346_478F_BF8B_E7F431478625__INCLUDED_)
#define AFX_EX_LISTDLG_H__5E45CB48_5346_478F_BF8B_E7F431478625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_ListDlg dialog

class CEx_ListDlg : public CDialog
{
// Construction
public:
	CEx_ListDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_ListDlg)
	enum { IDD = IDD_EX_LIST_DIALOG };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_ListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonScore();
	afx_msg void OnButtonChange();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_LISTDLG_H__5E45CB48_5346_478F_BF8B_E7F431478625__INCLUDED_)
