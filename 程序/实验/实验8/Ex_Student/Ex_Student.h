// Ex_Student.h : main header file for the EX_STUDENT application
//

#if !defined(AFX_EX_STUDENT_H__9129045D_D534_4AF2_A5DF_F15CC2BF3CB4__INCLUDED_)
#define AFX_EX_STUDENT_H__9129045D_D534_4AF2_A5DF_F15CC2BF3CB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentApp:
// See Ex_Student.cpp for the implementation of this class
//

class CEx_StudentApp : public CWinApp
{
public:
	CEx_StudentApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_StudentApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_StudentApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_STUDENT_H__9129045D_D534_4AF2_A5DF_F15CC2BF3CB4__INCLUDED_)
