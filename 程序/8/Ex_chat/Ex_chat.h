// Ex_Chat.h : main header file for the EX_Chat application
//

#if !defined(AFX_EX_Chat_H__BA731155_6F4D_4705_8A92_E4E379DB7134__INCLUDED_)
#define AFX_EX_Chat_H__BA731155_6F4D_4705_8A92_E4E379DB7134__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_ChatApp:
// See Ex_Chat.cpp for the implementation of this class
//

class CEx_ChatApp : public CWinApp
{
public:
	CEx_ChatApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ChatApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_ChatApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CHAT_H__BA731155_6F4D_4705_8A92_E4E379DB7134__INCLUDED_)
