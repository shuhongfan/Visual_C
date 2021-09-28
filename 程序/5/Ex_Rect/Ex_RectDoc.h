// Ex_RectDoc.h : interface of the CEx_RectDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_RECTDOC_H__FF137178_9FA8_477C_BB3C_76BC58FB7D12__INCLUDED_)
#define AFX_EX_RECTDOC_H__FF137178_9FA8_477C_BB3C_76BC58FB7D12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_RectDoc : public CDocument
{
protected: // create from serialization only
	CEx_RectDoc();
	DECLARE_DYNCREATE(CEx_RectDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_RectDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CPoint m_ptRect;
	virtual ~CEx_RectDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_RectDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_RECTDOC_H__FF137178_9FA8_477C_BB3C_76BC58FB7D12__INCLUDED_)
