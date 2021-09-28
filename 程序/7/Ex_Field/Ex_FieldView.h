// Ex_FieldView.h : interface of the CEx_FieldView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_FIELDVIEW_H__712B20CA_FF4E_4731_B69A_564CB3235DBD__INCLUDED_)
#define AFX_EX_FIELDVIEW_H__712B20CA_FF4E_4731_B69A_564CB3235DBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_FieldView : public CListView
{
protected: // create from serialization only
	CEx_FieldView();
	DECLARE_DYNCREATE(CEx_FieldView)

// Attributes
public:
	CEx_FieldDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_FieldView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_FieldView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_FieldView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_FieldView.cpp
inline CEx_FieldDoc* CEx_FieldView::GetDocument()
   { return (CEx_FieldDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_FIELDVIEW_H__712B20CA_FF4E_4731_B69A_564CB3235DBD__INCLUDED_)
