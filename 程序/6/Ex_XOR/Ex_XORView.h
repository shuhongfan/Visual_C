// Ex_XORView.h : interface of the CEx_XORView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_XORVIEW_H__7195AF12_29E4_425C_B12D_03CB8E5E0BA4__INCLUDED_)
#define AFX_EX_XORVIEW_H__7195AF12_29E4_425C_B12D_03CB8E5E0BA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_XORView : public CView
{
public:
	BOOL		m_bCursorFirst;				// 光标第一次显示标志
	CPoint		m_ptCurPos;				// 当前点的坐标
protected: // create from serialization only
	CEx_XORView();
	DECLARE_DYNCREATE(CEx_XORView)

// Attributes
public:
	CEx_XORDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_XORView)
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
	void DrawCursor(CDC *pDC, CPoint pt);
	virtual ~CEx_XORView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_XORView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_XORView.cpp
inline CEx_XORDoc* CEx_XORView::GetDocument()
   { return (CEx_XORDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_XORVIEW_H__7195AF12_29E4_425C_B12D_03CB8E5E0BA4__INCLUDED_)
