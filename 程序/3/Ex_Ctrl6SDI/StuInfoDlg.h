#if !defined(AFX_STUINFODLG_H__59520369_CC1C_41A9_A562_C3993DE77D9B__INCLUDED_)
#define AFX_STUINFODLG_H__59520369_CC1C_41A9_A562_C3993DE77D9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StuInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg dialog

class CStuInfoDlg : public CDialog
{
// Construction
public:
	BOOL m_bMale;
	CStuInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStuInfoDlg)
	enum { IDD = IDD_STUINFO };
	CComboBox	m_comboSpecial;
	CString	m_strName;
	CString	m_strNo;
	CTime	m_tBirth;
	CString	m_strSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStuInfoDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnRadioMale();
	afx_msg void OnRadioFemale();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUINFODLG_H__59520369_CC1C_41A9_A562_C3993DE77D9B__INCLUDED_)
