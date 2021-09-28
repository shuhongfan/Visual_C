// Ex_List.h : main header file for the EX_LIST application
//

#if !defined(AFX_EX_LIST_H__8108ECFF_62FC_4E47_A206_F9DA75B7B464__INCLUDED_)
#define AFX_EX_LIST_H__8108ECFF_62FC_4E47_A206_F9DA75B7B464__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_ListApp:
// See Ex_List.cpp for the implementation of this class
//

class CEx_ListApp : public CWinApp
{
public:
	CEx_ListApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ListApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_ListApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_LIST_H__8108ECFF_62FC_4E47_A206_F9DA75B7B464__INCLUDED_)
