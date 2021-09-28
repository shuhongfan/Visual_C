// Ex_ODBCSet.h : interface of the CEx_ODBCSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_ODBCSET_H__5F9854A2_83D6_4C95_97B5_A95CD73C63A7__INCLUDED_)
#define AFX_EX_ODBCSET_H__5F9854A2_83D6_4C95_97B5_A95CD73C63A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEx_ODBCSet : public CRecordset
{
public:
	CEx_ODBCSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CEx_ODBCSet)

// Field/Param Data
	//{{AFX_FIELD(CEx_ODBCSet, CRecordset)
	CString	m_studentno;
	CString	m_course;
	float	m_score;
	float	m_credit;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_ODBCSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_ODBCSET_H__5F9854A2_83D6_4C95_97B5_A95CD73C63A7__INCLUDED_)

