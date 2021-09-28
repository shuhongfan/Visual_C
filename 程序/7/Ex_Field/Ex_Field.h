// Ex_Field.h : main header file for the EX_FIELD application
//

#if !defined(AFX_EX_FIELD_H__F3B2B9E3_0646_4EDB_9AF2_F63C69B650B5__INCLUDED_)
#define AFX_EX_FIELD_H__F3B2B9E3_0646_4EDB_9AF2_F63C69B650B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_FieldApp:
// See Ex_Field.cpp for the implementation of this class
//

class CEx_FieldApp : public CWinApp
{
public:
	CEx_FieldApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_FieldApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_FieldApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_FIELD_H__F3B2B9E3_0646_4EDB_9AF2_F63C69B650B5__INCLUDED_)
