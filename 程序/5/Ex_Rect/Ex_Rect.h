// Ex_Rect.h : main header file for the EX_RECT application
//

#if !defined(AFX_EX_RECT_H__8833A260_2172_4AAE_A4C8_29B6E4BECE2E__INCLUDED_)
#define AFX_EX_RECT_H__8833A260_2172_4AAE_A4C8_29B6E4BECE2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_RectApp:
// See Ex_Rect.cpp for the implementation of this class
//

class CEx_RectApp : public CWinApp
{
public:
	CEx_RectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_RectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_RectApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_RECT_H__8833A260_2172_4AAE_A4C8_29B6E4BECE2E__INCLUDED_)
