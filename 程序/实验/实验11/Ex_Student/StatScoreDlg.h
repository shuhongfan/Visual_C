#if !defined(AFX_STATSCOREDLG_H__5516B72B_6F79_4520_B2E8_2254EADA16FE__INCLUDED_)
#define AFX_STATSCOREDLG_H__5516B72B_6F79_4520_B2E8_2254EADA16FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StatScoreDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStatScoreDlg dialog

class CStatScoreDlg : public CDialog
{
// Construction
public:
	void ResetScoreData();
	CString m_strClass;
	int m_nNum;
	int m_nScore[100];
	void DrawScore();
	CStatScoreDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStatScoreDlg)
	enum { IDD = IDD_STAT_SCORE };
	CComboBox	m_comboCourseNO;
	CString	m_strCourseNO;
	CString	m_strCourseName;
	CString	m_strCredit;
	CString	m_strOpen;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatScoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStatScoreDlg)
	afx_msg void OnButtonDisp();
	afx_msg void OnSelchangeComboCourseno();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATSCOREDLG_H__5516B72B_6F79_4520_B2E8_2254EADA16FE__INCLUDED_)
