// Ex_SDI.h : main header file for the EX_SDI application
//

#if !defined(AFX_EX_SDI_H__1A9813A3_6165_4D51_B911_2DD3BB46AB7B__INCLUDED_)
#define AFX_EX_SDI_H__1A9813A3_6165_4D51_B911_2DD3BB46AB7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_SDIApp:
// See Ex_SDI.cpp for the implementation of this class
//

class CEx_SDIApp : public CWinApp
{
public:
	CEx_SDIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SDIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_SDIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SDI_H__1A9813A3_6165_4D51_B911_2DD3BB46AB7B__INCLUDED_)
