// Ex_Grid.h : main header file for the EX_GRID application
//

#if !defined(AFX_EX_GRID_H__E8E77C95_53DD_4EC0_9A5F_8A1BE4314C4E__INCLUDED_)
#define AFX_EX_GRID_H__E8E77C95_53DD_4EC0_9A5F_8A1BE4314C4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_GridApp:
// See Ex_Grid.cpp for the implementation of this class
//

class CEx_GridApp : public CWinApp
{
public:
	CEx_GridApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_GridApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_GridApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_GRID_H__E8E77C95_53DD_4EC0_9A5F_8A1BE4314C4E__INCLUDED_)
