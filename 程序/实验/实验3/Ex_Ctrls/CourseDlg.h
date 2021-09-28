#if !defined(AFX_COURSEDLG_H__95480BEA_65D4_40CA_B671_1004E7EEC9A8__INCLUDED_)
#define AFX_COURSEDLG_H__95480BEA_65D4_40CA_B671_1004E7EEC9A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CourseDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg dialog

class CCourseDlg : public CDialog
{
// Construction
public:
	CCourseDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCourseDlg)
	enum { IDD = IDD_COURSE };
	CComboBox	m_comboSpecial;
	CSpinButtonCtrl	m_spinOpen;
	CString	m_strSpecial;
	CString	m_strType;
	int		m_nHours;
	CString	m_strName;
	CString	m_strNO;
	float	m_fCredit;
	BYTE	m_nOpen;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCourseDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSEDLG_H__95480BEA_65D4_40CA_B671_1004E7EEC9A8__INCLUDED_)
