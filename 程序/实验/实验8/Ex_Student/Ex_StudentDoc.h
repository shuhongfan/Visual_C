// Ex_StudentDoc.h : interface of the CEx_StudentDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_STUDENTDOC_H__0A23066B_19DA_4800_8108_3D075D08A22C__INCLUDED_)
#define AFX_EX_STUDENTDOC_H__0A23066B_19DA_4800_8108_3D075D08A22C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_StudentDoc : public CDocument
{
protected: // create from serialization only
	CEx_StudentDoc();
	DECLARE_DYNCREATE(CEx_StudentDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_StudentDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_StudentDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_StudentDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_STUDENTDOC_H__0A23066B_19DA_4800_8108_3D075D08A22C__INCLUDED_)
