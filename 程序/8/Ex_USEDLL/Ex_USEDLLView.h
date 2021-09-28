// Ex_USEDLLView.h : interface of the CEx_USEDLLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_USEDLLVIEW_H__B2C21ED3_DCB0_4783_B7FF_AEDA5FB1F97B__INCLUDED_)
#define AFX_EX_USEDLLVIEW_H__B2C21ED3_DCB0_4783_B7FF_AEDA5FB1F97B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_USEDLLView : public CView
{
protected: // create from serialization only
	CEx_USEDLLView();
	DECLARE_DYNCREATE(CEx_USEDLLView)

// Attributes
public:
	CEx_USEDLLDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_USEDLLView)
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
	virtual ~CEx_USEDLLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_USEDLLView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_USEDLLView.cpp
inline CEx_USEDLLDoc* CEx_USEDLLView::GetDocument()
   { return (CEx_USEDLLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_USEDLLVIEW_H__B2C21ED3_DCB0_4783_B7FF_AEDA5FB1F97B__INCLUDED_)
