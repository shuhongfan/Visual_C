// Ex_TestDLLDoc.h : interface of the CEx_TestDLLDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_TESTDLLDOC_H__0E533EA6_D3ED_4759_B4D7_CBEC7BAEDF4C__INCLUDED_)
#define AFX_EX_TESTDLLDOC_H__0E533EA6_D3ED_4759_B4D7_CBEC7BAEDF4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_TestDLLDoc : public CDocument
{
protected: // create from serialization only
	CEx_TestDLLDoc();
	DECLARE_DYNCREATE(CEx_TestDLLDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_TestDLLDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_TestDLLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_TestDLLDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_TESTDLLDOC_H__0E533EA6_D3ED_4759_B4D7_CBEC7BAEDF4C__INCLUDED_)
