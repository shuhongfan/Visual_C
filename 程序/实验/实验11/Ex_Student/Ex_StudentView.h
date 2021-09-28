// Ex_StudentView.h : interface of the CEx_StudentView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX_STUDENTVIEW_H__BD954D26_7C8B_4F15_A875_5674AA6ABAEE__INCLUDED_)
#define AFX_EX_STUDENTVIEW_H__BD954D26_7C8B_4F15_A875_5674AA6ABAEE__INCLUDED_

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

class CEx_StudentDoc;
class CEx_StudentView : public CListView
{
protected: // create from serialization only
	CEx_StudentView();
	DECLARE_DYNCREATE(CEx_StudentView)

// Attributes
public:
	CEx_StudentDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx_StudentView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DispStatusRecord();
	CString AppendStringSpace(CString str, int nNum);
	void AdjustAllLine(CDC *pDC);
	void PrintFoot(CDC* pDC, CPrintInfo* pInfo, PAGEINFO page, CString title, int margin, int mode);
	void PrintHead(CDC* pDC, CPrintInfo* pInfo, PAGEINFO page, CString title, int margin, int mode);
	void SetPageInfo(CDC *pDC, CPrintInfo *pInfo, PAGEINFO *pPage, int l, int t, int r, int b, int nLineSpace);
	void ReadListViewData();
	CStringArray	m_strContents;
	PAGEINFO 		m_pageInfo;
	CStringArray 	m_arrText;		// �������ĵ�����
	CUIntArray  	m_nLineArray;	// ��¼ÿҳ�Ŀ�ʼ�к�

	void DelCourseInfo(int nItem);
	void DelScoreInfo(int nItem);
	void DelStudentInfo(int nItem);
	void ChangeScoreInfo(int nItem);
	void ChangeCourseInfo(int nItem);
	void ChangeStudentInfo(int nItem);
	void DispScoreAndCourseInfo2(CString strSpecFilter, CString strFilter2="");
	void DispScoreAndCourseInfo(CString strFilter, CString strFilter2 = "");
	void DispCourseInfo(CString strFilter, CString strSort);
	void DispStudentInfo(CString strFilter, CString strSort);
	void DeleteAllColumn();
	virtual ~CEx_StudentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx_StudentView)
	afx_msg void OnOpChange();
	afx_msg void OnOpDel();
	afx_msg void OnSelSeek();
	afx_msg void OnSelStat();
	afx_msg void OnUpdateSelStat(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ex_StudentView.cpp
inline CEx_StudentDoc* CEx_StudentView::GetDocument()
   { return (CEx_StudentDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX_STUDENTVIEW_H__BD954D26_7C8B_4F15_A875_5674AA6ABAEE__INCLUDED_)
