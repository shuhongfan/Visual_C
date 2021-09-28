// Ex_MDIView.h : interface of the CEx_MDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MDIVIEW_H__5E38BD21_3493_4ECC_AA4D_A04C5112D724__INCLUDED_)
#define AFX_EX_MDIVIEW_H__5E38BD21_3493_4ECC_AA4D_A04C5112D724__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_MDIView : public CView
{
protected: // create from serialization only
	CEx_MDIView();
	DECLARE_DYNCREATE(CEx_MDIView)

// Attributes
public:
	CEx_MDIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MDIView)
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
	virtual ~CEx_MDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_MDIView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_MDIView.cpp
inline CEx_MDIDoc* CEx_MDIView::GetDocument()
   { return (CEx_MDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MDIVIEW_H__5E38BD21_3493_4ECC_AA4D_A04C5112D724__INCLUDED_)
