// Ex_DBCtrlView.h : interface of the CEx_DBCtrlView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_DBCTRLVIEW_H__CB015C19_AA34_4743_B5BA_E3D9D5D799D4__INCLUDED_)
#define AFX_EX_DBCTRLVIEW_H__CB015C19_AA34_4743_B5BA_E3D9D5D799D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_DBCtrlView : public CFormView
{
protected: // create from serialization only
	CEx_DBCtrlView();
	DECLARE_DYNCREATE(CEx_DBCtrlView)

public:
	//{{AFX_DATA(CEx_DBCtrlView)
	enum{ IDD = IDD_EX_DBCTRL_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CEx_DBCtrlDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DBCtrlView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_DBCtrlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_DBCtrlView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_DBCtrlView.cpp
inline CEx_DBCtrlDoc* CEx_DBCtrlView::GetDocument()
   { return (CEx_DBCtrlDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DBCTRLVIEW_H__CB015C19_AA34_4743_B5BA_E3D9D5D799D4__INCLUDED_)
