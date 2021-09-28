// Ex_Ctrl6SDI.h : main header file for the EX_CTRL6SDI application
//

#if !defined(AFX_EX_CTRL6SDI_H__A0575A14_9EC7_4605_97B8_4930F339E708__INCLUDED_)
#define AFX_EX_CTRL6SDI_H__A0575A14_9EC7_4605_97B8_4930F339E708__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_Ctrl6SDIApp:
// See Ex_Ctrl6SDI.cpp for the implementation of this class
//

class CEx_Ctrl6SDIApp : public CWinApp
{
public:
	CEx_Ctrl6SDIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Ctrl6SDIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_Ctrl6SDIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTRL6SDI_H__A0575A14_9EC7_4605_97B8_4930F339E708__INCLUDED_)
