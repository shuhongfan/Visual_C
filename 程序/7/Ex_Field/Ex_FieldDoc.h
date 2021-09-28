// Ex_FieldDoc.h : interface of the CEx_FieldDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_FIELDDOC_H__026697C8_778E_4908_9B0F_169AF5137DB9__INCLUDED_)
#define AFX_EX_FIELDDOC_H__026697C8_778E_4908_9B0F_169AF5137DB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_FieldDoc : public CDocument
{
protected: // create from serialization only
	CEx_FieldDoc();
	DECLARE_DYNCREATE(CEx_FieldDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_FieldDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_FieldDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_FieldDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_FIELDDOC_H__026697C8_778E_4908_9B0F_169AF5137DB9__INCLUDED_)
