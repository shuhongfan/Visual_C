#if !defined(AFX_SCOREDLG_H__2188367A_94C6_4AF3_9025_7EFC417A503F__INCLUDED_)
#define AFX_SCOREDLG_H__2188367A_94C6_4AF3_9025_7EFC417A503F__INCLUDED_

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
	enum { IDD = IDD_SCORE_TABLE };
	CComboBox	m_comboNO;
	float	m_fCredit;
	float	m_fScore;
	CString	m_strCourseNO;
	CString	m_strStudentNO;
	CString	m_strNO;
	CString	m_strHours;
	CString	m_strName;
	CString	m_strOpen;
	CString	m_strSpecial;
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
	afx_msg void OnSelchangeComboNo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOREDLG_H__2188367A_94C6_4AF3_9025_7EFC417A503F__INCLUDED_)
