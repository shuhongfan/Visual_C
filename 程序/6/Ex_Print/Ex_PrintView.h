// Ex_PrintView.h : interface of the CEx_PrintView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_PRINTVIEW_H__80E049DD_DE1D_4411_8A08_6F3143A2E385__INCLUDED_)
#define AFX_EX_PRINTVIEW_H__80E049DD_DE1D_4411_8A08_6F3143A2E385__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct {
	CSize sizePage;			// ҳ��/ֽ��С
	CSize sizeLine;			// ÿ�еĴ�С
	CSize sizeChar;			// ÿ���ַ���ƽ����С
	int nLMargin;			// ��߾�
	int nRMargin;			// �ұ߾�
	int nTMargin;			// �ϱ߾�
	int nBMargin;			// �±߾�
	int nPhyLeft;			// ������߾�
	int nPhyRight;			// �����ұ߾�
	int nPhyTop;			// �����ϱ߾�
	int nPhyBottom;			// �����±߾�
	LOGFONT lfHead;		// ҳü����
	LOGFONT lfFoot;		// ҳ������
	LOGFONT lfText;		// ��������
} PAGEINFO;		// ҳ����Ϣ�ṹ

class CEx_PrintView : public CView
{
protected: // create from serialization only
	CEx_PrintView();
	DECLARE_DYNCREATE(CEx_PrintView)

// Attributes
public:
	CEx_PrintDoc* GetDocument();
	PAGEINFO 	m_pageInfo;
	CStringArray 	m_arrText;		// �������ĵ�����
	CUIntArray  	m_nLineArray;	// ��¼ÿҳ�Ŀ�ʼ�к�
	void SetPageInfo(CDC *pDC, CPrintInfo *pInfo, PAGEINFO *pPage, 
								  int l, int t, int r, int b, int nLineSpace);
	void PrintHead(CDC* pDC, CPrintInfo* pInfo, PAGEINFO page, 
			CString title, int margin, int mode);
	void PrintFoot(CDC* pDC, CPrintInfo* pInfo, PAGEINFO page, 
			CString title, int margin, int mode);
	void AdjustAllLine(CDC *pDC);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_PrintView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx_PrintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_PrintView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_PrintView.cpp
inline CEx_PrintDoc* CEx_PrintView::GetDocument()
   { return (CEx_PrintDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_PRINTVIEW_H__80E049DD_DE1D_4411_8A08_6F3143A2E385__INCLUDED_)
