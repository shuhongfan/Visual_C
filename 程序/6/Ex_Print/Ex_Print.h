// Ex_Print.h : main header file for the EX_PRINT application
//

#if !defined(AFX_EX_PRINT_H__B1A044E6_D916_4A3A_BF52_1E6AB0076BC3__INCLUDED_)
#define AFX_EX_PRINT_H__B1A044E6_D916_4A3A_BF52_1E6AB0076BC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_PrintApp:
// See Ex_Print.cpp for the implementation of this class
//

class CEx_PrintApp : public CWinApp
{
public:
	CEx_PrintApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_PrintApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_PrintApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_PRINT_H__B1A044E6_D916_4A3A_BF52_1E6AB0076BC3__INCLUDED_)
