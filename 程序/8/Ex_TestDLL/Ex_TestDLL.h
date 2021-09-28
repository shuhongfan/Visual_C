// Ex_TestDLL.h : main header file for the EX_TESTDLL application
//

#if !defined(AFX_EX_TESTDLL_H__DEEE18CD_DF2F_48D2_96A0_7257B86115D3__INCLUDED_)
#define AFX_EX_TESTDLL_H__DEEE18CD_DF2F_48D2_96A0_7257B86115D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_TestDLLApp:
// See Ex_TestDLL.cpp for the implementation of this class
//

class CEx_TestDLLApp : public CWinApp
{
public:
	CEx_TestDLLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TestDLLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_TestDLLApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TESTDLL_H__DEEE18CD_DF2F_48D2_96A0_7257B86115D3__INCLUDED_)
