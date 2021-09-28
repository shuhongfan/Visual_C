// Ex_GridDoc.h : interface of the CEx_GridDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_GRIDDOC_H__F0806CD1_1E53_41FD_A087_0A40D513E6CD__INCLUDED_)
#define AFX_EX_GRIDDOC_H__F0806CD1_1E53_41FD_A087_0A40D513E6CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Ex_GridSet.h"


class CEx_GridDoc : public CDocument
{
protected: // create from serialization only
	CEx_GridDoc();
	DECLARE_DYNCREATE(CEx_GridDoc)

// Attributes
public:
	CEx_GridSet m_ex_GridSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_GridDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_GridDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_GridDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_GRIDDOC_H__F0806CD1_1E53_41FD_A087_0A40D513E6CD__INCLUDED_)
