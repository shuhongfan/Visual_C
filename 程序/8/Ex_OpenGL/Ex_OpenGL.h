// Ex_OpenGL.h : main header file for the EX_OPENGL application
//

#if !defined(AFX_EX_OPENGL_H__3603D2D3_B93D_4908_8FDD_BBE9340A6E64__INCLUDED_)
#define AFX_EX_OPENGL_H__3603D2D3_B93D_4908_8FDD_BBE9340A6E64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEx_OpenGLApp:
// See Ex_OpenGL.cpp for the implementation of this class
//

class CEx_OpenGLApp : public CWinApp
{
public:
	CEx_OpenGLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_OpenGLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEx_OpenGLApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_OPENGL_H__3603D2D3_B93D_4908_8FDD_BBE9340A6E64__INCLUDED_)
