#if !defined(AFX_EX_OCX_H__06B3144F_F91E_4A82_AD9F_959B71BD531C__INCLUDED_)
#define AFX_EX_OCX_H__06B3144F_F91E_4A82_AD9F_959B71BD531C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CEx_OCX wrapper class

class CEx_OCX : public CWnd
{
protected:
	DECLARE_DYNCREATE(CEx_OCX)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xb062eb11, 0x4def, 0x4672, { 0x93, 0xc, 0x2f, 0xba, 0x10, 0x0, 0x43, 0x99 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:
	OLE_COLOR GetForeColor();
	void SetForeColor(OLE_COLOR);
	BOOL GetBCircle();
	void SetBCircle(BOOL);
	short GetNHatch();
	void SetNHatch(short);

// Operations
public:
	short CalCircleSize(short rcWidth, short rcHeight);
	void AboutBox();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_OCX_H__06B3144F_F91E_4A82_AD9F_959B71BD531C__INCLUDED_)
