// Ex_ODBCSet.cpp : implementation of the CEx_ODBCSet class
//

#include "stdafx.h"
#include "Ex_ODBC.h"
#include "Ex_ODBCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ODBCSet implementation

IMPLEMENT_DYNAMIC(CEx_ODBCSet, CRecordset)

CEx_ODBCSet::CEx_ODBCSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CEx_ODBCSet)
	m_studentno = _T("");
	m_course = _T("");
	m_score = 0.0f;
	m_credit = 0.0f;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CEx_ODBCSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Database Example For VC++");
}

CString CEx_ODBCSet::GetDefaultSQL()
{
	return _T("[score]");
}

void CEx_ODBCSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CEx_ODBCSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[studentno]"), m_studentno);
	RFX_Text(pFX, _T("[course]"), m_course);
	RFX_Single(pFX, _T("[score]"), m_score);
	RFX_Single(pFX, _T("[credit]"), m_credit);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ODBCSet diagnostics

#ifdef _DEBUG
void CEx_ODBCSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEx_ODBCSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
