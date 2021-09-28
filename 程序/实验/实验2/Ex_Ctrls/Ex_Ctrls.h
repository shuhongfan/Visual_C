// Ex_Ctrls.h : main header file for the EX_CTRLS application
//

#if !defined(AFX_EX_CTRLS_H__13AF680A_ED55_4E34_B581_1C4070AC1628__INCLUDED_)
#define AFX_EX_CTRLS_H__13AF680A_ED55_4E34_B581_1C4070AC1628__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_CtrlsApp:
// See Ex_Ctrls.cpp for the implementation of this class
//

class CEx_CtrlsApp : public CWinApp
{
public:
	CEx_CtrlsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_CtrlsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_CtrlsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTRLS_H__13AF680A_ED55_4E34_B581_1C4070AC1628__INCLUDED_)
