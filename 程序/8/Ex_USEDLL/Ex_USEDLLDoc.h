// Ex_USEDLLDoc.h : interface of the CEx_USEDLLDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_USEDLLDOC_H__B9825777_BE28_44B6_B072_BFDA979F2E2C__INCLUDED_)
#define AFX_EX_USEDLLDOC_H__B9825777_BE28_44B6_B072_BFDA979F2E2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_USEDLLDoc : public CDocument
{
protected: // create from serialization only
	CEx_USEDLLDoc();
	DECLARE_DYNCREATE(CEx_USEDLLDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_USEDLLDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_USEDLLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_USEDLLDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_USEDLLDOC_H__B9825777_BE28_44B6_B072_BFDA979F2E2C__INCLUDED_)
