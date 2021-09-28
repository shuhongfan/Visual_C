// Ex_Ctrl3SDIView.h : interface of the CEx_Ctrl3SDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_CTRL3SDIVIEW_H__8ACE4BD4_99BC_4945_AF19_D766FC3C1D6E__INCLUDED_)
#define AFX_EX_CTRL3SDIVIEW_H__8ACE4BD4_99BC_4945_AF19_D766FC3C1D6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_Ctrl3SDIView : public CView
{
protected: // create from serialization only
	CEx_Ctrl3SDIView();
	DECLARE_DYNCREATE(CEx_Ctrl3SDIView)

// Attributes
public:
	CEx_Ctrl3SDIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_Ctrl3SDIView)
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
	virtual ~CEx_Ctrl3SDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_Ctrl3SDIView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_Ctrl3SDIView.cpp
inline CEx_Ctrl3SDIDoc* CEx_Ctrl3SDIView::GetDocument()
   { return (CEx_Ctrl3SDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_CTRL3SDIVIEW_H__8ACE4BD4_99BC_4945_AF19_D766FC3C1D6E__INCLUDED_)
