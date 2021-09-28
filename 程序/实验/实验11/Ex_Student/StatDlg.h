#if !defined(AFX_STATDLG_H__4A3ADDFC_DDA0_48B7_9BDD_B38AC4E1EDA9__INCLUDED_)
#define AFX_STATDLG_H__4A3ADDFC_DDA0_48B7_9BDD_B38AC4E1EDA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StatDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStatDlg dialog

class CStatDlg : public CDialog
{
// Construction
public:
	CStatDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStatDlg)
	enum { IDD = IDD_DIALOG_STAT };
	CComboBox	m_comboTerm;
	CString	m_strNum;
	CString	m_strNO;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStatDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATDLG_H__4A3ADDFC_DDA0_48B7_9BDD_B38AC4E1EDA9__INCLUDED_)
