// Ex_OpenGLDoc.h : interface of the CEx_OpenGLDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_OPENGLDOC_H__5C04B2AA_0DF4_46F8_A951_CC1D9BE047C1__INCLUDED_)
#define AFX_EX_OPENGLDOC_H__5C04B2AA_0DF4_46F8_A951_CC1D9BE047C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_OpenGLDoc : public CDocument
{
protected: // create from serialization only
	CEx_OpenGLDoc();
	DECLARE_DYNCREATE(CEx_OpenGLDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_OpenGLDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_OpenGLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_OpenGLDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_OPENGLDOC_H__5C04B2AA_0DF4_46F8_A951_CC1D9BE047C1__INCLUDED_)
