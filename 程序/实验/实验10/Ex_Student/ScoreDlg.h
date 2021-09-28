#if !defined(AFX_SCOREDLG_H__8F03F9B0_0483_4369_8289_FC34CC30D0E9__INCLUDED_)
#define AFX_SCOREDLG_H__8F03F9B0_0483_4369_8289_FC34CC30D0E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScoreDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg dialog

class CScoreDlg : public CDialog
{
// Construction
public:
	CString m_strOKText;
	CScoreDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScoreDlg)
	enum { IDD = IDD_SCORE };
	CComboBox	m_comboName;
	CString	m_strCourseNo;
	float	m_fCredit;
	float	m_fScore;
	CString	m_strStuNo;
	CString	m_strTerm;
	CString	m_strSpecial;
	CString	m_strHours;
	CString	m_strType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScoreDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboName();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOREDLG_H__8F03F9B0_0483_4369_8289_FC34CC30D0E9__INCLUDED_)
