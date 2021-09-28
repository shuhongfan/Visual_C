// Ex_MCIDoc.h : interface of the CEx_MCIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MCIDOC_H__05E70729_B1EF_40B0_AE6A_465632E47A6C__INCLUDED_)
#define AFX_EX_MCIDOC_H__05E70729_B1EF_40B0_AE6A_465632E47A6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_MCIDoc : public CDocument
{
protected: // create from serialization only
	CEx_MCIDoc();
	DECLARE_DYNCREATE(CEx_MCIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MCIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_MCIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_MCIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MCIDOC_H__05E70729_B1EF_40B0_AE6A_465632E47A6C__INCLUDED_)
