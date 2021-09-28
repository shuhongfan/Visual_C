// Ex_ODBCView.h : interface of the CEx_ODBCView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_EX_ODBCVIEW_H__B984595B_1EB9_4C8C_9867_8A5E5927AC61__INCLUDED_)
#define AFX_EX_ODBCVIEW_H__B984595B_1EB9_4C8C_9867_8A5E5927AC61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEx_ODBCSet;

class CEx_ODBCView : public CRecordView
{
protected: // create from serialization only
	CEx_ODBCView();
	DECLARE_DYNCREATE(CEx_ODBCView)

public:
	//{{AFX_DATA(CEx_ODBCView)
	enum { IDD = IDD_EX_ODBC_FORM };
	CEx_ODBCSet* m_pSet;
	CMSFlexGrid	m_MSFGrid;
	//}}AFX_DATA

// Attributes
public:
	CEx_ODBCDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ODBCView)
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
	virtual ~CEx_ODBCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ODBCView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_ODBCView.cpp
inline CEx_ODBCDoc* CEx_ODBCView::GetDocument()
   { return (CEx_ODBCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ODBCVIEW_H__B984595B_1EB9_4C8C_9867_8A5E5927AC61__INCLUDED_)
