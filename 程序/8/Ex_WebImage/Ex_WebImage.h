// Ex_WebImage.h : main header file for the EX_WEBIMAGE application
//

#if !defined(AFX_EX_WEBIMAGE_H__EAD3F06E_027E_4C7F_9FA2_8C53E479DF57__INCLUDED_)
#define AFX_EX_WEBIMAGE_H__EAD3F06E_027E_4C7F_9FA2_8C53E479DF57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_WebImageApp:
// See Ex_WebImage.cpp for the implementation of this class
//

class CEx_WebImageApp : public CWinApp
{
public:
	CEx_WebImageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_WebImageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_WebImageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_WEBIMAGE_H__EAD3F06E_027E_4C7F_9FA2_8C53E479DF57__INCLUDED_)
