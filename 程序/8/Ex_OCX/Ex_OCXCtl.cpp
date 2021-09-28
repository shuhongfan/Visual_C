// Ex_OCXCtl.cpp : Implementation of the CEx_OCXCtrl ActiveX Control class.

#include "stdafx.h"
#include "Ex_OCX.h"
#include "Ex_OCXCtl.h"
#include "Ex_OCXPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CEx_OCXCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CEx_OCXCtrl, COleControl)
	//{{AFX_MSG_MAP(CEx_OCXCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CEx_OCXCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CEx_OCXCtrl)
	DISP_PROPERTY_NOTIFY(CEx_OCXCtrl, "bCircle", m_bCircle, OnM_bCircleChanged, VT_BOOL)
	DISP_PROPERTY_EX(CEx_OCXCtrl, "nHatch", GetNHatch, SetNHatch, VT_I2)
	DISP_FUNCTION(CEx_OCXCtrl, "CalCircleSize", CalCircleSize, VT_I2, VTS_I2 VTS_I2)
	DISP_STOCKPROP_FORECOLOR()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CEx_OCXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CEx_OCXCtrl, COleControl)
	//{{AFX_EVENT_MAP(CEx_OCXCtrl)
	EVENT_STOCK_CLICK()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CEx_OCXCtrl, 2)
	PROPPAGEID(CEx_OCXPropPage::guid)
	PROPPAGEID(CLSID_CColorPropPage)
END_PROPPAGEIDS(CEx_OCXCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CEx_OCXCtrl, "EXOCX.ExOCXCtrl.1",
	0xb062eb11, 0x4def, 0x4672, 0x93, 0xc, 0x2f, 0xba, 0x10, 0, 0x43, 0x99)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CEx_OCXCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DEx_OCX =
		{ 0xf03e24a6, 0x48ff, 0x420b, { 0xb7, 0x2b, 0x76, 0x74, 0x84, 0xd4, 0xa2, 0x3d } };
const IID BASED_CODE IID_DEx_OCXEvents =
		{ 0xfef49acc, 0x9484, 0x402d, { 0x99, 0xa2, 0x9a, 0x4a, 0xc0, 0xff, 0x9d, 0x12 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwEx_OCXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CEx_OCXCtrl, IDS_EX_OCX, _dwEx_OCXOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CEx_OCXCtrl::CEx_OCXCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CEx_OCXCtrl

BOOL CEx_OCXCtrl::CEx_OCXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_EX_OCX,
			IDB_EX_OCX,
			afxRegApartmentThreading,
			_dwEx_OCXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CEx_OCXCtrl::CEx_OCXCtrl - Constructor

CEx_OCXCtrl::CEx_OCXCtrl()
{
	InitializeIIDs(&IID_DEx_OCX, &IID_DEx_OCXEvents);

	// TODO: Initialize your control's instance data here.
	m_nHatch = 0;
}


/////////////////////////////////////////////////////////////////////////////
// CEx_OCXCtrl::~CEx_OCXCtrl - Destructor

CEx_OCXCtrl::~CEx_OCXCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CEx_OCXCtrl::OnDraw - Drawing function

void CEx_OCXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	CBrush brush( m_nHatch, TranslateColor(GetForeColor()));
	CBrush *oldBrush = pdc->SelectObject( &brush );
	if (m_bCircle)
	{
		CRect rcCircle(rcBounds);
		int r = CalCircleSize( rcCircle.Width(), rcCircle.Height() );
		rcCircle.SetRect(rcCircle.CenterPoint().x - r, rcCircle.CenterPoint().y - r,
			rcCircle.CenterPoint().x + r, rcCircle.CenterPoint().y + r);
		pdc->Ellipse(rcCircle);
	} else
		pdc->Ellipse(rcBounds);
	pdc->SelectObject( oldBrush );
}


/////////////////////////////////////////////////////////////////////////////
// CEx_OCXCtrl::DoPropExchange - Persistence support

void CEx_OCXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}


/////////////////////////////////////////////////////////////////////////////
// CEx_OCXCtrl::OnResetState - Reset control to default state

void CEx_OCXCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CEx_OCXCtrl::AboutBox - Display an "About" box to the user

void CEx_OCXCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_EX_OCX);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CEx_OCXCtrl message handlers

void CEx_OCXCtrl::OnM_bCircleChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl();
	SetModifiedFlag();
}

short CEx_OCXCtrl::GetNHatch() 
{
	// TODO: Add your property handler here
	return m_nHatch;
}

void CEx_OCXCtrl::SetNHatch(short nNewValue) 
{
	// TODO: Add your property handler here
	m_nHatch = nNewValue;
	InvalidateControl();
	SetModifiedFlag();
}

short CEx_OCXCtrl::CalCircleSize(short rcWidth, short rcHeight) 
{
	if (rcWidth>rcHeight) return rcHeight/2;
	else return rcWidth/2;
}
