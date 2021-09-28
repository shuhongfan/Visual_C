#if !defined(AFX_BKCOLORDLG_H__4A022402_7998_4FEC_8F78_008121D8ED64__INCLUDED_)
#define AFX_BKCOLORDLG_H__4A022402_7998_4FEC_8F78_008121D8ED64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BkColorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBkColorDlg dialog

class CBkColorDlg : public CDialog
{
// Construction
public:
	CBrush m_Brush;
	int m_nRedValue;
	CBkColorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBkColorDlg)
	enum { IDD = IDD_COLOR };
	CScrollBar	m_scrollRed;
	CSliderCtrl	m_sliderGreen;
	CSliderCtrl	m_sliderBlue;
	int		m_nBlue;
	int		m_nGreen;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBkColorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBkColorDlg)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BKCOLORDLG_H__4A022402_7998_4FEC_8F78_008121D8ED64__INCLUDED_)
