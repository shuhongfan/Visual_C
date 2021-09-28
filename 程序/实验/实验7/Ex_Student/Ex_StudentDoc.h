// Ex_StudentDoc.h : interface of the CEx_StudentDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_STUDENTDOC_H__CA5F6F6F_EACB_4311_B62C_E60E840391C0__INCLUDED_)
#define AFX_EX_STUDENTDOC_H__CA5F6F6F_EACB_4311_B62C_E60E840391C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StudentInfo.h" 
class CEx_StudentDoc : public CDocument
{
protected: // create from serialization only
	CEx_StudentDoc();
	DECLARE_DYNCREATE(CEx_StudentDoc)

// Attributes
public:
	CObArray m_stuObArray;		// 对象集合类对象

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
	int GetAllRecNum();
	CStudentInfo* GetStudentInfoAt(int nIndex);
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

#endif // !defined(AFX_EX_STUDENTDOC_H__CA5F6F6F_EACB_4311_B62C_E60E840391C0__INCLUDED_)
