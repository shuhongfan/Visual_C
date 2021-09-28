#if !defined(AFX_STUDENTTREEVIEW_H__79BCFC1A_DA90_42CE_9926_05EFE9737551__INCLUDED_)
#define AFX_STUDENTTREEVIEW_H__79BCFC1A_DA90_42CE_9926_05EFE9737551__INCLUDED_

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
	CImageList m_ImageList;
// Operations
public:
	HTREEITEM FindTreeItem(CTreeCtrl &treeCtrl, HTREEITEM hParent, CString str);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentTreeView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
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

#endif // !defined(AFX_STUDENTTREEVIEW_H__79BCFC1A_DA90_42CE_9926_05EFE9737551__INCLUDED_)
