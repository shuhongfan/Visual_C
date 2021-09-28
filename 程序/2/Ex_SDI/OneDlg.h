#if !defined(AFX_ONEDLG_H__31644A0D_4C90_44AC_A7FB_75E5CABADA62__INCLUDED_)
#define AFX_ONEDLG_H__31644A0D_4C90_44AC_A7FB_75E5CABADA62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OneDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COneDlg dialog

class COneDlg : public CDialog
{
// Construction
public:
	COneDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COneDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COneDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COneDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONEDLG_H__31644A0D_4C90_44AC_A7FB_75E5CABADA62__INCLUDED_)
