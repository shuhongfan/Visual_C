// Ex_MDI.h : main header file for the EX_MDI application
//

#if !defined(AFX_EX_MDI_H__E0F52048_2553_4B6F_9D5B_C3F5F736D8B1__INCLUDED_)
#define AFX_EX_MDI_H__E0F52048_2553_4B6F_9D5B_C3F5F736D8B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_MDIApp:
// See Ex_MDI.cpp for the implementation of this class
//

class CEx_MDIApp : public CWinApp
{
public:
	CEx_MDIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MDIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_MDIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MDI_H__E0F52048_2553_4B6F_9D5B_C3F5F736D8B1__INCLUDED_)
