// Ex_XORDoc.h : interface of the CEx_XORDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_XORDOC_H__47F5817D_623F_4B92_B465_F46DD226BD9A__INCLUDED_)
#define AFX_EX_XORDOC_H__47F5817D_623F_4B92_B465_F46DD226BD9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_XORDoc : public CDocument
{
protected: // create from serialization only
	CEx_XORDoc();
	DECLARE_DYNCREATE(CEx_XORDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_XORDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_XORDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_XORDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_XORDOC_H__47F5817D_623F_4B92_B465_F46DD226BD9A__INCLUDED_)
