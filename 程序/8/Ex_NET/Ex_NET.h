// Ex_NET.h : main header file for the EX_NET application
//

#if !defined(AFX_EX_NET_H__E7C43511_5C67_4441_8756_57A332A8CA72__INCLUDED_)
#define AFX_EX_NET_H__E7C43511_5C67_4441_8756_57A332A8CA72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_NETApp:
// See Ex_NET.cpp for the implementation of this class
//

class CEx_NETApp : public CWinApp
{
public:
	CEx_NETApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_NETApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_NETApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_NET_H__E7C43511_5C67_4441_8756_57A332A8CA72__INCLUDED_)
