#if !defined(AFX_SEEKDLG_H__74919E05_9DEF_4E43_B277_CBA6F1C176F7__INCLUDED_)
#define AFX_SEEKDLG_H__74919E05_9DEF_4E43_B277_CBA6F1C176F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SeekDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSeekDlg dialog

class CSeekDlg : public CDialog
{
// Construction
public:
	BOOL m_bTerm;
	int m_nTerm;
	CStringArray m_strItemArray;
	int m_nInfoType;
	CSeekDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSeekDlg)
	enum { IDD = IDD_DIALOG_SEEK };
	CComboBox	m_comboSeek;
	CComboBox	m_comboTerm;
	CString	m_strTitle;
	CString	m_strSeek;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeekDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSeekDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEEKDLG_H__74919E05_9DEF_4E43_B277_CBA6F1C176F7__INCLUDED_)
