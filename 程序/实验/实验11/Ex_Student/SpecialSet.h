#if !defined(AFX_SPECIALSET_H__3F7FD207_E89A_4D07_9969_5D1F1A060184__INCLUDED_)
#define AFX_SPECIALSET_H__3F7FD207_E89A_4D07_9969_5D1F1A060184__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpecialSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpecialSet recordset

class CSpecialSet : public CRecordset
{
public:
	CSpecialSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSpecialSet)

// Field/Param Data
	//{{AFX_FIELD(CSpecialSet, CRecordset)
	long	m_ID;
	CString	m_special;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpecialSet)
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

#endif // !defined(AFX_SPECIALSET_H__3F7FD207_E89A_4D07_9969_5D1F1A060184__INCLUDED_)
