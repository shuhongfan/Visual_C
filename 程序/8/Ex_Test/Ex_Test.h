// Ex_Test.h : main header file for the EX_TEST application
//

#if !defined(AFX_EX_TEST_H__2FDCDB1C_B5AB_467D_8532_6F036309543C__INCLUDED_)
#define AFX_EX_TEST_H__2FDCDB1C_B5AB_467D_8532_6F036309543C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_TestApp:
// See Ex_Test.cpp for the implementation of this class
//

class CEx_TestApp : public CWinApp
{
public:
	CEx_TestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_TestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TEST_H__2FDCDB1C_B5AB_467D_8532_6F036309543C__INCLUDED_)
