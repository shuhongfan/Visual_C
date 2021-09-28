// Ex_PrintDoc.h : interface of the CEx_PrintDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_PRINTDOC_H__5C5CD8D6_1425_4B52_808B_09DB5940AEC0__INCLUDED_)
#define AFX_EX_PRINTDOC_H__5C5CD8D6_1425_4B52_808B_09DB5940AEC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_PrintDoc : public CDocument
{
protected: // create from serialization only
	CEx_PrintDoc();
	DECLARE_DYNCREATE(CEx_PrintDoc)

// Attributes
public:
	BOOL			m_bNewDocument;
	CStringArray	m_strContents;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_PrintDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_PrintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_PrintDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_PRINTDOC_H__5C5CD8D6_1425_4B52_808B_09DB5940AEC0__INCLUDED_)
