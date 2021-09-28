#if !defined(AFX_TREEDLG_H__D7053354_4F59_4FEC_B6F7_FE0A22B0B436__INCLUDED_)
#define AFX_TREEDLG_H__D7053354_4F59_4FEC_B6F7_FE0A22B0B436__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TreeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTreeDlg dialog

class CTreeDlg : public CDialog
{
// Construction
public:
	CImageList m_ImageList;
	CTreeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTreeDlg)
	enum { IDD = IDD_TREE };
	CTreeCtrl	m_TreeCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTreeDlg)
	afx_msg void OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnRclickTree1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREEDLG_H__D7053354_4F59_4FEC_B6F7_FE0A22B0B436__INCLUDED_)
