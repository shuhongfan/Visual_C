// Ex_DrawTextView.cpp : implementation of the CEx_DrawTextView class
//

#include "stdafx.h"
#include "Ex_DrawText.h"

#include "Ex_DrawTextDoc.h"
#include "Ex_DrawTextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawTextView

IMPLEMENT_DYNCREATE(CEx_DrawTextView, CView)

BEGIN_MESSAGE_MAP(CEx_DrawTextView, CView)
	//{{AFX_MSG_MAP(CEx_DrawTextView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawTextView construction/destruction

CEx_DrawTextView::CEx_DrawTextView()
{
	// TODO: add construction code here

}

CEx_DrawTextView::~CEx_DrawTextView()
{
}

BOOL CEx_DrawTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawTextView drawing

void CEx_DrawTextView::OnDraw(CDC* pDC)
{
	CEx_DrawTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	// ʹ��DrawText
	CRect rc(10, 10, 200, 140);
	pDC->Rectangle( rc );
	pDC->DrawText( "�����ı�����", rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rc.OffsetRect( 200, 0 );	// ����������ƫ��200
	pDC->Rectangle( rc );
	int nTab = 40;		// ��һ��Tabλ��ֵָ��Ϊ10���߼���λ
	pDC->TabbedTextOut( rc.left, rc.top, "����\tTab\t�ı�\tʾ��", 
		1, &nTab, rc.left);	// ʹ���Զ����ֹͣλ(Tab)
	nTab = 80;
	pDC->TabbedTextOut( rc.left, rc.top+20, "����\tTab\t�ı�\tʾ��", 
		1, &nTab, rc.left);	// ʹ���Զ����ֹͣλ(Tab)
	pDC->TabbedTextOut( rc.left, rc.top+40, "����\tTab\t�ı�\tʾ��", 
		0, NULL, 0);	// ʹ��Ĭ�ϵ�ֹͣλ
}

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawTextView printing

BOOL CEx_DrawTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_DrawTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_DrawTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawTextView diagnostics

#ifdef _DEBUG
void CEx_DrawTextView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_DrawTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_DrawTextDoc* CEx_DrawTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_DrawTextDoc)));
	return (CEx_DrawTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_DrawTextView message handlers
