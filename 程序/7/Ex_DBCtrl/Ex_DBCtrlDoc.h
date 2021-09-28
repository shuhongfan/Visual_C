// Ex_DBCtrlDoc.h : interface of the CEx_DBCtrlDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_DBCTRLDOC_H__453B121E_34EB_4998_AE24_25FE057F831B__INCLUDED_)
#define AFX_EX_DBCTRLDOC_H__453B121E_34EB_4998_AE24_25FE057F831B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_DBCtrlDoc : public CDocument
{
protected: // create from serialization only
	CEx_DBCtrlDoc();
	DECLARE_DYNCREATE(CEx_DBCtrlDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_DBCtrlDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_DBCtrlDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_DBCtrlDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_DBCTRLDOC_H__453B121E_34EB_4998_AE24_25FE057F831B__INCLUDED_)
