// Ex_FormDoc.h : interface of the CEx_FormDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_FORMDOC_H__27FCF3A8_E3D0_4423_92A7_5ED19CD8B981__INCLUDED_)
#define AFX_EX_FORMDOC_H__27FCF3A8_E3D0_4423_92A7_5ED19CD8B981__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEx_FormDoc : public CDocument
{
protected: // create from serialization only
	CEx_FormDoc();
	DECLARE_DYNCREATE(CEx_FormDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_FormDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString m_strContent;
	virtual ~CEx_FormDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_FormDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_FORMDOC_H__27FCF3A8_E3D0_4423_92A7_5ED19CD8B981__INCLUDED_)
