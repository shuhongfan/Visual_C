// Ex_MenuSDIDoc.h : interface of the CEx_MenuSDIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MENUSDIDOC_H__6DB2267A_253D_4CF7_A9DA_63DF5D611B07__INCLUDED_)
#define AFX_EX_MENUSDIDOC_H__6DB2267A_253D_4CF7_A9DA_63DF5D611B07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_MenuSDIDoc : public CDocument
{
protected: // create from serialization only
	CEx_MenuSDIDoc();
	DECLARE_DYNCREATE(CEx_MenuSDIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MenuSDIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_MenuSDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_MenuSDIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MENUSDIDOC_H__6DB2267A_253D_4CF7_A9DA_63DF5D611B07__INCLUDED_)
