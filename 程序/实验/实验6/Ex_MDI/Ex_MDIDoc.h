// Ex_MDIDoc.h : interface of the CEx_MDIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_MDIDOC_H__66DE11CD_8C33_4940_A9CE_E9721581F87E__INCLUDED_)
#define AFX_EX_MDIDOC_H__66DE11CD_8C33_4940_A9CE_E9721581F87E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CourseInfo.h" 
class CEx_MDIDoc : public CDocument
{
protected: // create from serialization only
	CEx_MDIDoc();
	DECLARE_DYNCREATE(CEx_MDIDoc)

// Attributes
public:
	CObArray m_courseObArray;		// 对象集合类对象
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_MDIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	int GetCourseRecNum();
	CCourseInfo* GetCourseInfoAt(int nIndex);
	virtual ~CEx_MDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_MDIDoc)
	afx_msg void OnCourseinfoAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_MDIDOC_H__66DE11CD_8C33_4940_A9CE_E9721581F87E__INCLUDED_)
