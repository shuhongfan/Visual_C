// Ex_MenuSDIView.h : interface of the CEx_MenuSDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MENUSDIVIEW_H__662CD48D_4093_4F77_9063_9BF6A6362986__INCLUDED_)
#define AFX_EX_MENUSDIVIEW_H__662CD48D_4093_4F77_9063_9BF6A6362986__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_MenuSDIView : public CView
{
protected: // create from serialization only
	CEx_MenuSDIView();
	DECLARE_DYNCREATE(CEx_MenuSDIView)

// Attributes
public:
	CEx_MenuSDIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MenuSDIView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_MenuSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_MenuSDIView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_MenuSDIView.cpp
inline CEx_MenuSDIDoc* CEx_MenuSDIView::GetDocument()
   { return (CEx_MenuSDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MENUSDIVIEW_H__662CD48D_4093_4F77_9063_9BF6A6362986__INCLUDED_)
