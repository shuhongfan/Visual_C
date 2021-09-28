#if !defined(AFX_ARRAYVIEW_H__FCA1B03F_0441_426F_A716_650CE7769525__INCLUDED_)
#define AFX_ARRAYVIEW_H__FCA1B03F_0441_426F_A716_650CE7769525__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ArrayView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CArrayView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CArrayView : public CFormView
{
protected:
	CArrayView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CArrayView)

// Form Data
public:
	//{{AFX_DATA(CArrayView)
	enum { IDD = IDD_ARRAYVIEW_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArrayView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CArrayView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CArrayView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ARRAYVIEW_H__FCA1B03F_0441_426F_A716_650CE7769525__INCLUDED_)
