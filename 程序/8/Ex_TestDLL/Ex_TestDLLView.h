// Ex_TestDLLView.h : interface of the CEx_TestDLLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_TESTDLLVIEW_H__D1B96125_594C_4655_8137_FC0BE3248104__INCLUDED_)
#define AFX_EX_TESTDLLVIEW_H__D1B96125_594C_4655_8137_FC0BE3248104__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_TestDLLView : public CView
{
protected: // create from serialization only
	CEx_TestDLLView();
	DECLARE_DYNCREATE(CEx_TestDLLView)

// Attributes
public:
	CEx_TestDLLDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TestDLLView)
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
	virtual ~CEx_TestDLLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_TestDLLView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_TestDLLView.cpp
inline CEx_TestDLLDoc* CEx_TestDLLView::GetDocument()
   { return (CEx_TestDLLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TESTDLLVIEW_H__D1B96125_594C_4655_8137_FC0BE3248104__INCLUDED_)
