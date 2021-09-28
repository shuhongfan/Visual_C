// Ex_Text.h : main header file for the EX_TEXT application
//

#if !defined(AFX_EX_TEXT_H__30A1DC08_B360_473C_8B9A_4220B2B61107__INCLUDED_)
#define AFX_EX_TEXT_H__30A1DC08_B360_473C_8B9A_4220B2B61107__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_TextApp:
// See Ex_Text.cpp for the implementation of this class
//

class CEx_TextApp : public CWinApp
{
public:
	CEx_TextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_TextApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TEXT_H__30A1DC08_B360_473C_8B9A_4220B2B61107__INCLUDED_)
