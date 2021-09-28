#if !defined(AFX_EX_STUDENTVIEW_H__AECFECD2_A7FC_4733_82AF_5FB0BE895C03__INCLUDED_)
#define AFX_EX_STUDENTVIEW_H__AECFECD2_A7FC_4733_82AF_5FB0BE895C03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Ex_StudentView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView view

class CEx_StudentView : public CView
{
protected:
	CEx_StudentView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CEx_StudentView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_StudentView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CEx_StudentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CEx_StudentView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_STUDENTVIEW_H__AECFECD2_A7FC_4733_82AF_5FB0BE895C03__INCLUDED_)
