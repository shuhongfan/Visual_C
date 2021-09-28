// Ex_GridSet.h : interface of the CEx_GridSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_GRIDSET_H__662DBF20_609E_4184_8086_77220BCDB1FC__INCLUDED_)
#define AFX_EX_GRIDSET_H__662DBF20_609E_4184_8086_77220BCDB1FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEx_GridSet : public CRecordset
{
public:
	CEx_GridSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CEx_GridSet)

// Field/Param Data
	//{{AFX_FIELD(CEx_GridSet, CRecordset)
	CString	m_studentno;
	CString	m_course;
	float	m_score;
	float	m_credit;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_GridSet)
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

#endif // !defined(AFX_EX_GRIDSET_H__662DBF20_609E_4184_8086_77220BCDB1FC__INCLUDED_)

