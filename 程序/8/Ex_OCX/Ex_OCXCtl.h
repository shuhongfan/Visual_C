#if !defined(AFX_EX_OCXCTL_H__2A36E5F1_A21A_48C7_AA77_DDF5B60B30AD__INCLUDED_)
#define AFX_EX_OCXCTL_H__2A36E5F1_A21A_48C7_AA77_DDF5B60B30AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Ex_OCXCtl.h : Declaration of the CEx_OCXCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CEx_OCXCtrl : See Ex_OCXCtl.cpp for implementation.

class CEx_OCXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CEx_OCXCtrl)

// Constructor
public:
	CEx_OCXCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_OCXCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CEx_OCXCtrl();

	DECLARE_OLECREATE_EX(CEx_OCXCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CEx_OCXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CEx_OCXCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CEx_OCXCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CEx_OCXCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CEx_OCXCtrl)
	BOOL m_bCircle;
	afx_msg void OnM_bCircleChanged();
	afx_msg short GetNHatch();
	afx_msg void SetNHatch(short nNewValue);
	afx_msg short CalCircleSize(short rcWidth, short rcHeight);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CEx_OCXCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	short m_nHatch;
	enum {
	//{{AFX_DISP_ID(CEx_OCXCtrl)
	dispidBCircle = 1L,
	dispidNHatch = 2L,
	dispidCalCircleSize = 3L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_OCXCTL_H__2A36E5F1_A21A_48C7_AA77_DDF5B60B30AD__INCLUDED)
