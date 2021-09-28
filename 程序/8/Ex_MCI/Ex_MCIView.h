// Ex_MCIView.h : interface of the CEx_MCIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MCIVIEW_H__EDADE124_5337_459A_99F8_C3B01DB3B344__INCLUDED_)
#define AFX_EX_MCIVIEW_H__EDADE124_5337_459A_99F8_C3B01DB3B344__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_MCIView : public CView
{
protected: // create from serialization only
	CEx_MCIView();
	DECLARE_DYNCREATE(CEx_MCIView)

// Attributes
public:
	HWND m_hMyMCIWnd;
	CEx_MCIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MCIView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_MCIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_MCIView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	afx_msg LONG OnNotifySize(UINT wParam, LONG lParam);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_MCIView.cpp
inline CEx_MCIDoc* CEx_MCIView::GetDocument()
   { return (CEx_MCIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MCIVIEW_H__EDADE124_5337_459A_99F8_C3B01DB3B344__INCLUDED_)
