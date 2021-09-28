// Ex_StudentDoc.h : interface of the CEx_StudentDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_STUDENTDOC_H__53CFDACC_E782_4D54_9DAF_F140F6775785__INCLUDED_)
#define AFX_EX_STUDENTDOC_H__53CFDACC_E782_4D54_9DAF_F140F6775785__INCLUDED_

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
	CString m_strCourseNO;
	int m_nInfoType;
	int m_nViewPos;
	void DoCopyFile(CString strFileTo, CString strFileFrom);
	void AddCourseInfo();
	void AddScoreInfo();
	void AddStudentInfo();
	virtual ~CEx_StudentDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_StudentDoc)
	afx_msg void OnOpAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_STUDENTDOC_H__53CFDACC_E782_4D54_9DAF_F140F6775785__INCLUDED_)
