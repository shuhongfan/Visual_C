// Ex_ChatDlg.h : header file
//

#if !defined(AFX_EX_ChatDLG_H__FA4293AF_5708_4A79_AF0E_477FCF9BACF5__INCLUDED_)
#define AFX_EX_ChatDLG_H__FA4293AF_5708_4A79_AF0E_477FCF9BACF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEx_ChatDlg dialog
#include "ChatSocket.h"
class CEx_ChatDlg : public CDialog
{
public:
	void OnAccept();
	void OnReceive();
	void OnConnect();
	void DoClose();
// Construction
public:
	CChatSocket m_asServer;
	CChatSocket m_asClient;
	BOOL m_bServer;
	CEx_ChatDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEx_ChatDlg)
	enum { IDD = IDD_EX_CHAT_DIALOG };
	CListBox	m_listMsg;
	CComboBox	m_comboType;
	CString	m_strMsg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ChatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEx_ChatDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeComboType();
	afx_msg void OnClose();
	afx_msg void OnButtonRun();
	afx_msg void OnButtonSend();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CHATDLG_H__FA4293AF_5708_4A79_AF0E_477FCF9BACF5__INCLUDED_)
