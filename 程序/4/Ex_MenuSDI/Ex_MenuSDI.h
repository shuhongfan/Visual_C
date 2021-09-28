// Ex_MenuSDI.h : main header file for the EX_MENUSDI application
//

#if !defined(AFX_EX_MENUSDI_H__6103D422_CBF4_4F15_AA3B_FBFCB1658D5C__INCLUDED_)
#define AFX_EX_MENUSDI_H__6103D422_CBF4_4F15_AA3B_FBFCB1658D5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_MenuSDIApp:
// See Ex_MenuSDI.cpp for the implementation of this class
//

class CEx_MenuSDIApp : public CWinApp
{
public:
	CEx_MenuSDIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MenuSDIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_MenuSDIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MENUSDI_H__6103D422_CBF4_4F15_AA3B_FBFCB1658D5C__INCLUDED_)
