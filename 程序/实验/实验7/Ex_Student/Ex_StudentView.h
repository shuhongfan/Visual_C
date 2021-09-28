// Ex_StudentView.h : interface of the CEx_StudentView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_STUDENTVIEW_H__B91C18C7_4666_44EB_A7C3_02F66C862100__INCLUDED_)
#define AFX_EX_STUDENTVIEW_H__B91C18C7_4666_44EB_A7C3_02F66C862100__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEx_StudentDoc;
class CEx_StudentView : public CListView
{
protected: // create from serialization only
	CEx_StudentView();
	DECLARE_DYNCREATE(CEx_StudentView)

// Attributes
public:
	CEx_StudentDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_StudentView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DispStudentInfo( CString strSpecial, CString strClass);
	virtual ~CEx_StudentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_StudentView)
	afx_msg void OnStuinfoAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_StudentView.cpp
inline CEx_StudentDoc* CEx_StudentView::GetDocument()
   { return (CEx_StudentDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_STUDENTVIEW_H__B91C18C7_4666_44EB_A7C3_02F66C862100__INCLUDED_)
