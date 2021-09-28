// Ex_StudentView.h : interface of the CEx_StudentView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_STUDENTVIEW_H__DAA59432_178C_4757_95C0_3FFFFC68F5D0__INCLUDED_)
#define AFX_EX_STUDENTVIEW_H__DAA59432_178C_4757_95C0_3FFFFC68F5D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


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
	//}}AFX_VIRTUAL

// Implementation
public:
	CString m_strFilter;
	int GetListCtrlCurSel();
	void DeleteAllColumn();
	void DispScoreInfo(CString strFilter);
	virtual ~CEx_StudentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_StudentView)
	afx_msg void OnScoreAdd();
	afx_msg void OnScoreChange();
	afx_msg void OnScoreDel();
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

#endif // !defined(AFX_EX_STUDENTVIEW_H__DAA59432_178C_4757_95C0_3FFFFC68F5D0__INCLUDED_)
