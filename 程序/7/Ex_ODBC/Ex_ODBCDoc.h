// Ex_ODBCDoc.h : interface of the CEx_ODBCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_ODBCDOC_H__831CBDED_6106_4297_BD01_2229DB4E7D47__INCLUDED_)
#define AFX_EX_ODBCDOC_H__831CBDED_6106_4297_BD01_2229DB4E7D47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Ex_ODBCSet.h"


class CEx_ODBCDoc : public CDocument
{
protected: // create from serialization only
	CEx_ODBCDoc();
	DECLARE_DYNCREATE(CEx_ODBCDoc)

// Attributes
public:
	CEx_ODBCSet m_ex_ODBCSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ODBCDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_ODBCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_ODBCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ODBCDOC_H__831CBDED_6106_4297_BD01_2229DB4E7D47__INCLUDED_)
