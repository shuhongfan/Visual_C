// Ex_ADO.h : main header file for the EX_ADO application
//

#if !defined(AFX_EX_ADO_H__FB3E7208_08BB_4CEB_9598_54A5951C5275__INCLUDED_)
#define AFX_EX_ADO_H__FB3E7208_08BB_4CEB_9598_54A5951C5275__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOApp:
// See Ex_ADO.cpp for the implementation of this class
//

class CEx_ADOApp : public CWinApp
{
public:
	CEx_ADOApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ADOApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_ADOApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ADO_H__FB3E7208_08BB_4CEB_9598_54A5951C5275__INCLUDED_)
