// Ex_DLL.h : main header file for the EX_DLL DLL
//

#if !defined(AFX_EX_DLL_H__BAB73BF8_372E_4644_8A03_34A127488852__INCLUDED_)
#define AFX_EX_DLL_H__BAB73BF8_372E_4644_8A03_34A127488852__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_DLLApp
// See Ex_DLL.cpp for the implementation of this class
//

class CEx_DLLApp : public CWinApp
{
public:
	CEx_DLLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DLLApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CEx_DLLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DLL_H__BAB73BF8_372E_4644_8A03_34A127488852__INCLUDED_)
