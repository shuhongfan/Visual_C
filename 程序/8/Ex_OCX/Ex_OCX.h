#if !defined(AFX_EX_OCX_H__C09A70BB_0BBC_4F4B_9C96_4B2CC025E177__INCLUDED_)
#define AFX_EX_OCX_H__C09A70BB_0BBC_4F4B_9C96_4B2CC025E177__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Ex_OCX.h : main header file for EX_OCX.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_OCXApp : See Ex_OCX.cpp for implementation.

class CEx_OCXApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_OCX_H__C09A70BB_0BBC_4F4B_9C96_4B2CC025E177__INCLUDED)
