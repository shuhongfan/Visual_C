// Ex_OpenGLView.h : interface of the CEx_OpenGLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_OPENGLVIEW_H__B7F83E8C_24EC_46B9_B3FD_339FEFC9EA6A__INCLUDED_)
#define AFX_EX_OPENGLVIEW_H__B7F83E8C_24EC_46B9_B3FD_339FEFC9EA6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "gl\gl.h"
#include "gl\glu.h"
#include "gl\glaux.h"
#pragma comment (lib,"Opengl32.lib")
#pragma comment (lib,"Glu32.lib")
#pragma comment (lib,"Glaux.lib")


class CEx_OpenGLView : public CView
{
protected: // create from serialization only
	CEx_OpenGLView();
	DECLARE_DYNCREATE(CEx_OpenGLView)

// Attributes
public:
	HGLRC m_hGLRC;					// 用作渲染环境RC的句柄
	CEx_OpenGLDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_OpenGLView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawScene();
	virtual ~CEx_OpenGLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_OpenGLView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_OpenGLView.cpp
inline CEx_OpenGLDoc* CEx_OpenGLView::GetDocument()
   { return (CEx_OpenGLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_OPENGLVIEW_H__B7F83E8C_24EC_46B9_B3FD_339FEFC9EA6A__INCLUDED_)
