#if !defined(AFX_OTHERVIEW_H__6ADAA66A_A6D0_4FD3_B0A7_CE0A6727D97C__INCLUDED_)
#define AFX_OTHERVIEW_H__6ADAA66A_A6D0_4FD3_B0A7_CE0A6727D97C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OtherView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COtherView view

class COtherView : public CView
{
protected:
	COtherView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(COtherView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COtherView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~COtherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(COtherView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OTHERVIEW_H__6ADAA66A_A6D0_4FD3_B0A7_CE0A6727D97C__INCLUDED_)
