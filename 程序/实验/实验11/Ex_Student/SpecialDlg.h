#if !defined(AFX_SPECIALDLG_H__25000289_6A04_4C21_8C4F_820E0197513C__INCLUDED_)
#define AFX_SPECIALDLG_H__25000289_6A04_4C21_8C4F_820E0197513C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpecialDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpecialDlg dialog

class CSpecialDlg : public CDialog
{
// Construction
public:
	void ResetListItem();
	BOOL m_bUpdate;
	CSpecialDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSpecialDlg)
	enum { IDD = IDD_DIALOG_SPECIAL };
	CListBox	m_List;
	CString	m_strSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpecialDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSpecialDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeList1();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonChange();
	afx_msg void OnButtonDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPECIALDLG_H__25000289_6A04_4C21_8C4F_820E0197513C__INCLUDED_)
