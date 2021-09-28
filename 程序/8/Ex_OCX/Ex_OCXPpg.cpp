// Ex_OCXPpg.cpp : Implementation of the CEx_OCXPropPage property page class.

#include "stdafx.h"
#include "Ex_OCX.h"
#include "Ex_OCXPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CEx_OCXPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CEx_OCXPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CEx_OCXPropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CEx_OCXPropPage, "EXOCX.ExOCXPropPage.1",
	0x342c9ab5, 0x99ab, 0x4a20, 0xa3, 0x6c, 0xe1, 0x79, 0xfc, 0xb4, 0xbd, 0x78)


/////////////////////////////////////////////////////////////////////////////
// CEx_OCXPropPage::CEx_OCXPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CEx_OCXPropPage

BOOL CEx_OCXPropPage::CEx_OCXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_EX_OCX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CEx_OCXPropPage::CEx_OCXPropPage - Constructor

CEx_OCXPropPage::CEx_OCXPropPage() :
	COlePropertyPage(IDD, IDS_EX_OCX_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CEx_OCXPropPage)
	m_bCircle = FALSE;
	m_nHatch = 0;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CEx_OCXPropPage::DoDataExchange - Moves data between page and properties

void CEx_OCXPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CEx_OCXPropPage)
	DDX_Control(pDX, IDC_SPIN1, m_Spin);
	DDP_Check(pDX, IDC_CHECK1, m_bCircle, _T("bCircle") );
	DDX_Check(pDX, IDC_CHECK1, m_bCircle);
	DDP_Text(pDX, IDC_EDIT1, m_nHatch, _T("nHatch") );
	DDX_Text(pDX, IDC_EDIT1, m_nHatch);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CEx_OCXPropPage message handlers

BOOL CEx_OCXPropPage::OnInitDialog() 
{
	COlePropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Spin.SetRange(0, 5);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

