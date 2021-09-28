#if !defined(AFX_LISTDLG_H__3B9A3863_7FBE_4EFD_950B_08043AEFB8FD__INCLUDED_)
#define AFX_LISTDLG_H__3B9A3863_7FBE_4EFD_950B_08043AEFB8FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CListDlg dialog

class CListDlg : public CDialog
{
// Construction
public:
	void SetCtrlStyle(HWND hWnd, DWORD dwNewStyle);
	CListDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CListDlg)
	enum { IDD = IDD_LIST };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CListDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioLarge();
	afx_msg void OnRadioSmall();
	afx_msg void OnRadioList();
	afx_msg void OnRadioReport();
	afx_msg void OnButtonAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTDLG_H__3B9A3863_7FBE_4EFD_950B_08043AEFB8FD__INCLUDED_)
