#if !defined(AFX_EX_OCXPPG_H__08EB0CCF_6D4A_4ABF_BDE0_969B5EF480E4__INCLUDED_)
#define AFX_EX_OCXPPG_H__08EB0CCF_6D4A_4ABF_BDE0_969B5EF480E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Ex_OCXPpg.h : Declaration of the CEx_OCXPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CEx_OCXPropPage : See Ex_OCXPpg.cpp.cpp for implementation.

class CEx_OCXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CEx_OCXPropPage)
	DECLARE_OLECREATE_EX(CEx_OCXPropPage)

// Constructor
public:
	CEx_OCXPropPage();

// Dialog Data
	//{{AFX_DATA(CEx_OCXPropPage)
	enum { IDD = IDD_PROPPAGE_EX_OCX };
	CSpinButtonCtrl	m_Spin;
	BOOL	m_bCircle;
	short	m_nHatch;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CEx_OCXPropPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_OCXPPG_H__08EB0CCF_6D4A_4ABF_BDE0_969B5EF480E4__INCLUDED)
