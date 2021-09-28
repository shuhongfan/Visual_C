// Ex_Dlg.h : main header file for the EX_DLG application
//

#if !defined(AFX_EX_DLG_H__02D03D65_110E_4107_BEF1_9B9DF9D82F00__INCLUDED_)
#define AFX_EX_DLG_H__02D03D65_110E_4107_BEF1_9B9DF9D82F00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_DlgApp:
// See Ex_Dlg.cpp for the implementation of this class
//

class CEx_DlgApp : public CWinApp
{
public:
	CEx_DlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_DlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DLG_H__02D03D65_110E_4107_BEF1_9B9DF9D82F00__INCLUDED_)
