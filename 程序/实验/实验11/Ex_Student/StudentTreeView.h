#if !defined(AFX_STUDENTTREEVIEW_H__AB1F9F67_EA00_4EC0_BAF6_01CC187AE0D0__INCLUDED_)
#define AFX_STUDENTTREEVIEW_H__AB1F9F67_EA00_4EC0_BAF6_01CC187AE0D0__INCLUDED_

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
	CString m_strClass;
	BOOL m_bEnableAnalyze;
	CImageList m_ImageList;
	HTREEITEM FindTreeItem(CTreeCtrl &treeCtrl, HTREEITEM hParent, CString str);
	void ResetTreeItem();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentTreeView)
	public:
	virtual void OnInitialUpdate();
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
	afx_msg void OnSelAnalyze();
	afx_msg void OnUpdateSelAnalyze(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTTREEVIEW_H__AB1F9F67_EA00_4EC0_BAF6_01CC187AE0D0__INCLUDED_)
