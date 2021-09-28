// Ex_ADOView.h : interface of the CEx_ADOView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_ADOVIEW_H__CF89FB0B_6222_40A1_BD3D_110F083378D8__INCLUDED_)
#define AFX_EX_ADOVIEW_H__CF89FB0B_6222_40A1_BD3D_110F083378D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_ADOView : public CListView
{
protected: // create from serialization only
	CEx_ADOView();
	DECLARE_DYNCREATE(CEx_ADOView)

// Attributes
public:
	CEx_ADODoc* GetDocument();

// Operations
public:
	_ConnectionPtr	m_pConnection;
    _RecordsetPtr	m_pRecordset;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ADOView)
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
	void ResetListItem();
	virtual ~CEx_ADOView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ADOView)
	afx_msg void OnDestroy();
	afx_msg void OnOpAdd();
	afx_msg void OnOpCha();
	afx_msg void OnOpDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_ADOView.cpp
inline CEx_ADODoc* CEx_ADOView::GetDocument()
   { return (CEx_ADODoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ADOVIEW_H__CF89FB0B_6222_40A1_BD3D_110F083378D8__INCLUDED_)
