#if !defined(AFX_STUDENTTREEVIEW_H__DC297B40_8978_4218_B16A_15A9514338EC__INCLUDED_)
#define AFX_STUDENTTREEVIEW_H__DC297B40_8978_4218_B16A_15A9514338EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentTreeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentTreeView view

class CStudentTreeView : public CTreeView
{
protected:
	CStudentTreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CStudentTreeView)

// Attributes
public:

// Operations
public:
	void ResetTreeItem();
	HTREEITEM FindTreeItem(CTreeCtrl &treeCtrl, HTREEITEM hParent, CString str);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentTreeView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CStudentTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CStudentTreeView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTTREEVIEW_H__DC297B40_8978_4218_B16A_15A9514338EC__INCLUDED_)
