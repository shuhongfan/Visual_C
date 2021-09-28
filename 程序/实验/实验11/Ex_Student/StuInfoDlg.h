
#if !defined(AFX_STUINFODLG_H__6E61404E_FA17_4D87_BD3C_0F6D6B9361CF__INCLUDED_)
#define AFX_STUINFODLG_H__6E61404E_FA17_4D87_BD3C_0F6D6B9361CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StuInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg dialog

class CStuInfoDlg : public CDialog
{
// Construction
public:
	void ResetComboBox();
	BOOL m_bPhotoChange;
	HBITMAP m_hBitmap;
	void DrawPhoto();
	CString m_strPhotoFilePath;
	CString m_strOKText;
	CStuInfoDlg(CWnd* pParent = NULL);   // standard constructor

	BOOL	m_bSex;
// Dialog Data
	//{{AFX_DATA(CStuInfoDlg)
	enum { IDD = IDD_STUINFO };
	CComboBox	m_comboSpecial;
	CTime	m_tBirth;
	CString	m_strName;
	CString	m_strNO;
	CString	m_strSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStuInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioMale();
	afx_msg void OnRadioFemale();
	virtual void OnOK();
	afx_msg void OnButtonPhoto();
	afx_msg void OnPaint();
	afx_msg void OnButtonSpecial1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUINFODLG_H__6E61404E_FA17_4D87_BD3C_0F6D6B9361CF__INCLUDED_)
