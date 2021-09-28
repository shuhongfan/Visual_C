#if !defined(AFX_SCORESET_H__567B4E45_6D01_432F_B9B5_80736CA4C830__INCLUDED_)
#define AFX_SCORESET_H__567B4E45_6D01_432F_B9B5_80736CA4C830__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScoreSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScoreSet recordset

class CScoreSet : public CRecordset
{
public:
	CScoreSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CScoreSet)

// Field/Param Data
	//{{AFX_FIELD(CScoreSet, CRecordset)
	CString	m_studentno;
	CString	m_course;
	float	m_score;
	float	m_credit;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoreSet)
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

#endif // !defined(AFX_SCORESET_H__567B4E45_6D01_432F_B9B5_80736CA4C830__INCLUDED_)
