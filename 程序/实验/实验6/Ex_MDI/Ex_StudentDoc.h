#if !defined(AFX_EX_STUDENTDOC_H__8F840F2D_5319_4453_94B5_2942C77A9655__INCLUDED_)
#define AFX_EX_STUDENTDOC_H__8F840F2D_5319_4453_94B5_2942C77A9655__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Ex_StudentDoc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc document
#include "StudentInfo.h" 
class CEx_StudentDoc : public CDocument
{
protected:
	CEx_StudentDoc();           // protected constructor used by dynamic creation
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
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
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

	// Generated message map functions
protected:
	//{{AFX_MSG(CEx_StudentDoc)
	afx_msg void OnStuinfoAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_STUDENTDOC_H__8F840F2D_5319_4453_94B5_2942C77A9655__INCLUDED_)
