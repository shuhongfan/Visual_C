// Ex_Research.h : main header file for the EX_RESEARCH application
//

#if !defined(AFX_EX_RESEARCH_H__4FE83CA0_3AB0_4646_85B4_33CC18E09B61__INCLUDED_)
#define AFX_EX_RESEARCH_H__4FE83CA0_3AB0_4646_85B4_33CC18E09B61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_ResearchApp:
// See Ex_Research.cpp for the implementation of this class
//

class CEx_ResearchApp : public CWinApp
{
public:
	CEx_ResearchApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ResearchApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEx_ResearchApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_RESEARCH_H__4FE83CA0_3AB0_4646_85B4_33CC18E09B61__INCLUDED_)
