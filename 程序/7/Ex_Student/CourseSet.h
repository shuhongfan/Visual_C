#if !defined(AFX_COURSESET_H__4A537A3E_6581_4B7C_B9CF_82AE6C4C318E__INCLUDED_)
#define AFX_COURSESET_H__4A537A3E_6581_4B7C_B9CF_82AE6C4C318E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CourseSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCourseSet recordset

class CCourseSet : public CRecordset
{
public:
	CCourseSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCourseSet)

// Field/Param Data
	//{{AFX_FIELD(CCourseSet, CRecordset)
	CString	m_courseno;
	CString	m_special;
	CString	m_coursename;
	CString	m_coursetype;
	BYTE	m_openterm;
	BYTE	m_hours;
	float	m_credit;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSESET_H__4A537A3E_6581_4B7C_B9CF_82AE6C4C318E__INCLUDED_)
