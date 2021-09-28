#if !defined(AFX_STUDENTSET_H__DB0A7383_F7CA_4488_B194_517938E49D05__INCLUDED_)
#define AFX_STUDENTSET_H__DB0A7383_F7CA_4488_B194_517938E49D05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentSet recordset

class CStudentSet : public CRecordset
{
public:
	CStudentSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStudentSet)

// Field/Param Data
	//{{AFX_FIELD(CStudentSet, CRecordset)
	CString	m_studentname;
	CString	m_studentno;
	BOOL	m_xb;
	CTime	m_birthday;
	CString	m_special;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentSet)
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

#endif // !defined(AFX_STUDENTSET_H__DB0A7383_F7CA_4488_B194_517938E49D05__INCLUDED_)
