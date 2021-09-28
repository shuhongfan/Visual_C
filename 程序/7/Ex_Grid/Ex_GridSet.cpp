// Ex_GridSet.cpp : implementation of the CEx_GridSet class
//

#include "stdafx.h"
#include "Ex_Grid.h"
#include "Ex_GridSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_GridSet implementation

IMPLEMENT_DYNAMIC(CEx_GridSet, CRecordset)

CEx_GridSet::CEx_GridSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CEx_GridSet)
	m_studentno = _T("");
	m_course = _T("");
	m_score = 0.0f;
	m_credit = 0.0f;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CEx_GridSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Database Example For VC++");
}

CString CEx_GridSet::GetDefaultSQL()
{
	return _T("[score]");
}

void CEx_GridSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CEx_GridSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[studentno]"), m_studentno);
	RFX_Text(pFX, _T("[course]"), m_course);
	RFX_Single(pFX, _T("[score]"), m_score);
	RFX_Single(pFX, _T("[credit]"), m_credit);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CEx_GridSet diagnostics

#ifdef _DEBUG
void CEx_GridSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEx_GridSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
