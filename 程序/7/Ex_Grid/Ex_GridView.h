// Ex_GridView.h : interface of the CEx_GridView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_EX_GRIDVIEW_H__3671ECC6_C472_496A_A1DE_7E57313B5433__INCLUDED_)
#define AFX_EX_GRIDVIEW_H__3671ECC6_C472_496A_A1DE_7E57313B5433__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEx_GridSet;

class CEx_GridView : public CRecordView
{
protected: // create from serialization only
	CEx_GridView();
	DECLARE_DYNCREATE(CEx_GridView)

public:
	//{{AFX_DATA(CEx_GridView)
	enum { IDD = IDD_EX_GRID_FORM };
	CEx_GridSet* m_pSet;
	CMSFlexGrid	m_MSFGrid;
	//}}AFX_DATA

// Attributes
public:
	CEx_GridDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_GridView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_GridView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_GridView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_GridView.cpp
inline CEx_GridDoc* CEx_GridView::GetDocument()
   { return (CEx_GridDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_GRIDVIEW_H__3671ECC6_C472_496A_A1DE_7E57313B5433__INCLUDED_)
