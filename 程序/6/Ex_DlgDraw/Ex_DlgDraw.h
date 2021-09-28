// Ex_DlgDraw.h : main header file for the EX_DLGDRAW application
//

#if !defined(AFX_EX_DLGDRAW_H__6F4B90E8_3AC2_48CD_8B75_008E9134A2D1__INCLUDED_)
#define AFX_EX_DLGDRAW_H__6F4B90E8_3AC2_48CD_8B75_008E9134A2D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_DlgDrawApp:
// See Ex_DlgDraw.cpp for the implementation of this class
//

class CEx_DlgDrawApp : public CWinApp
{
public:
	CEx_DlgDrawApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DlgDrawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_DlgDrawApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DLGDRAW_H__6F4B90E8_3AC2_48CD_8B75_008E9134A2D1__INCLUDED_)
