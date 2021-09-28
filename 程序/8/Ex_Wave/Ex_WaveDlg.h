// Ex_WaveDlg.h : header file
//

#if !defined(AFX_EX_WAVEDLG_H__984AA1F7_5B02_40AF_B17C_4675B5C1F31F__INCLUDED_)
#define AFX_EX_WAVEDLG_H__984AA1F7_5B02_40AF_B17C_4675B5C1F31F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Wave.h"

/////////////////////////////////////////////////////////////////////////////
// CEx_WaveDlg dialog
class CEx_WaveDlg : public CDialog
{
// Construction
public:
	CEx_WaveDlg(CWnd* pParent = NULL);	// standard constructor
	CWave m_wave;
// Dialog Data
	//{{AFX_DATA(CEx_WaveDlg)
	enum { IDD = IDD_EX_WAVE_DIALOG };
	CButton	m_btnStop;
	CButton	m_btnPlay;
	CButton	m_btnFile;
	CString	m_strFileName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_WaveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_WaveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFile();
	afx_msg void OnPlay();
	afx_msg void OnStop();
	//}}AFX_MSG
	LRESULT OnMCINotify(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_WAVEDLG_H__984AA1F7_5B02_40AF_B17C_4675B5C1F31F__INCLUDED_)
