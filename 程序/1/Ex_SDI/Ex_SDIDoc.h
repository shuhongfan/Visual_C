// Ex_SDIDoc.h : interface of the CEx_SDIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_SDIDOC_H__86CBA11F_199F_4382_83E1_7CD51045C683__INCLUDED_)
#define AFX_EX_SDIDOC_H__86CBA11F_199F_4382_83E1_7CD51045C683__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_SDIDoc : public CDocument
{
protected: // create from serialization only
	CEx_SDIDoc();
	DECLARE_DYNCREATE(CEx_SDIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_SDIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_SDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_SDIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_SDIDOC_H__86CBA11F_199F_4382_83E1_7CD51045C683__INCLUDED_)
