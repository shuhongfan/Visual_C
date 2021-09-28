#if !defined(AFX_ChatSOCKET_H__C80AE67A_8FCE_4362_B8DE_FC6542A772C1__INCLUDED_)
#define AFX_ChatSOCKET_H__C80AE67A_8FCE_4362_B8DE_FC6542A772C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChatSocket.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChatSocket command target
class CEx_ChatDlg;
class CChatSocket : public CAsyncSocket
{
// Attributes
public:
	CEx_ChatDlg* m_pDlg;
// Operations
public:
	CChatSocket();
	virtual ~CChatSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CChatSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ChatSOCKET_H__C80AE67A_8FCE_4362_B8DE_FC6542A772C1__INCLUDED_)
