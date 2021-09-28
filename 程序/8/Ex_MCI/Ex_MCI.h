// Ex_MCI.h : main header file for the EX_MCI application
//

#if !defined(AFX_EX_MCI_H__CDA6FBD3_40D4_4C52_8D96_EBF9A4812ADA__INCLUDED_)
#define AFX_EX_MCI_H__CDA6FBD3_40D4_4C52_8D96_EBF9A4812ADA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_MCIApp:
// See Ex_MCI.cpp for the implementation of this class
//

class CEx_MCIApp : public CWinApp
{
public:
	CEx_MCIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MCIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_MCIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MCI_H__CDA6FBD3_40D4_4C52_8D96_EBF9A4812ADA__INCLUDED_)
