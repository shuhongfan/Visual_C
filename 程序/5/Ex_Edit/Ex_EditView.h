// Ex_EditView.h : interface of the CEx_EditView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_EDITVIEW_H__6FCC76A2_504C_4789_942F_957E8BFA26AE__INCLUDED_)
#define AFX_EX_EDITVIEW_H__6FCC76A2_504C_4789_942F_957E8BFA26AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_EditView : public CEditView
{
protected: // create from serialization only
	CEx_EditView();
	DECLARE_DYNCREATE(CEx_EditView)

// Attributes
public:
	CEx_EditDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_EditView)
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
	virtual ~CEx_EditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_EditView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_EditView.cpp
inline CEx_EditDoc* CEx_EditView::GetDocument()
   { return (CEx_EditDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_EDITVIEW_H__6FCC76A2_504C_4789_942F_957E8BFA26AE__INCLUDED_)
