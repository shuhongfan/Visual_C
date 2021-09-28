// SpecialSet.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Student.h"
#include "SpecialSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpecialSet

IMPLEMENT_DYNAMIC(CSpecialSet, CRecordset)

CSpecialSet::CSpecialSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CSpecialSet)
	m_ID = 0;
	m_special = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CSpecialSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=学生信息管理系统");
}

CString CSpecialSet::GetDefaultSQL()
{
	return _T("[special]");
}

void CSpecialSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CSpecialSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[special]"), m_special);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CSpecialSet diagnostics

#ifdef _DEBUG
void CSpecialSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSpecialSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
