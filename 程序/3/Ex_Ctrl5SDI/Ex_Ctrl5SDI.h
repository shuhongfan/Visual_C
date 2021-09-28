// Ex_Ctrl5SDI.h : main header file for the EX_CTRL5SDI application
//

#if !defined(AFX_EX_CTRL5SDI_H__ED984A42_513C_4A6F_B2D6_7D5A2B05E600__INCLUDED_)
#define AFX_EX_CTRL5SDI_H__ED984A42_513C_4A6F_B2D6_7D5A2B05E600__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl5SDIApp:
// See Ex_Ctrl5SDI.cpp for the implementation of this class
//

class CEx_Ctrl5SDIApp : public CWinApp
{
public:
	CEx_Ctrl5SDIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Ctrl5SDIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_Ctrl5SDIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTRL5SDI_H__ED984A42_513C_4A6F_B2D6_7D5A2B05E600__INCLUDED_)
