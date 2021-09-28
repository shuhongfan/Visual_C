#if !defined(AFX_SEEKDLG_H__9FD11EA3_2C0D_470D_9A92_16DEDB496812__INCLUDED_)
#define AFX_SEEKDLG_H__9FD11EA3_2C0D_470D_9A92_16DEDB496812__INCLUDED_

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
	BOOL 	m_bTerm;		// �Ƿ����ѧ�ڲ�ѯ����
	int 		m_nTerm;		// ѧ����
	CStringArray m_strItemArray;	// ���ⲿ�ṩ��IDC_COMBO1���ݴ�Ŵ˱�����
	CSeekDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSeekDlg)
	enum { IDD = IDD_DIALOG_SEEK };
	CComboBox	m_comboTerm;
	CComboBox	m_comboSeek;
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

#endif // !defined(AFX_SEEKDLG_H__9FD11EA3_2C0D_470D_9A92_16DEDB496812__INCLUDED_)
