// Ex_Array.h : main header file for the EX_ARRAY application
//

#if !defined(AFX_EX_ARRAY_H__B8E3D672_AAF2_4185_BCD7_2D5D1B395690__INCLUDED_)
#define AFX_EX_ARRAY_H__B8E3D672_AAF2_4185_BCD7_2D5D1B395690__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_ArrayApp:
// See Ex_Array.cpp for the implementation of this class
//

class CEx_ArrayApp : public CWinApp
{
public:
	CEx_ArrayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ArrayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_ArrayApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ARRAY_H__B8E3D672_AAF2_4185_BCD7_2D5D1B395690__INCLUDED_)
