// Ex_PrintView.cpp : implementation of the CEx_PrintView class
//

#include "stdafx.h"
#include "Ex_Print.h"

#include "Ex_PrintDoc.h"
#include "Ex_PrintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_PrintView

IMPLEMENT_DYNCREATE(CEx_PrintView, CView)

BEGIN_MESSAGE_MAP(CEx_PrintView, CView)
	//{{AFX_MSG_MAP(CEx_PrintView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_PrintView construction/destruction

CEx_PrintView::CEx_PrintView()
{
	// TODO: add construction code here
	memset(&m_pageInfo, 0, sizeof(m_pageInfo));		// ���г�Ա��Ϊ0
	double fontScale = 254.0/72.0;	// һ�����൱�ڶ���0.1mm
	// ҳü����
	m_pageInfo.lfHead.lfHeight = - (int)(9 * fontScale + 0.5);		// 9����
	m_pageInfo.lfHead.lfWeight = FW_BOLD;
	m_pageInfo.lfHead.lfCharSet = GB2312_CHARSET;
	strcpy((LPSTR)&(m_pageInfo.lfHead.lfFaceName), "����");
	// ҳ������
	m_pageInfo.lfFoot.lfHeight = - (int)(9 * fontScale + 0.5);		// 9����
	m_pageInfo.lfFoot.lfWeight = FW_NORMAL;
	m_pageInfo.lfFoot.lfCharSet = GB2312_CHARSET;
	strcpy((LPSTR)&(m_pageInfo.lfFoot.lfFaceName), "����_GB2312");
	// ��������
	m_pageInfo.lfText.lfHeight = - (int)(11 * fontScale + 0.5);		// 11����
	m_pageInfo.lfText.lfWeight = FW_NORMAL;
	m_pageInfo.lfText.lfCharSet = GB2312_CHARSET;
	strcpy((LPSTR)&(m_pageInfo.lfText.lfFaceName), "����");

}

CEx_PrintView::~CEx_PrintView()
{
}

BOOL CEx_PrintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_PrintView drawing

void CEx_PrintView::OnDraw(CDC* pDC)
{
	CEx_PrintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEx_PrintView printing

BOOL CEx_PrintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	CEx_PrintDoc* pDoc = GetDocument();
	int nSize = pDoc->m_strContents.GetSize();
	if (nSize<1) pInfo->SetMaxPage(1);
		return DoPreparePrinting(pInfo);
}

void CEx_PrintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_PrintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_PrintView diagnostics

#ifdef _DEBUG
void CEx_PrintView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_PrintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_PrintDoc* CEx_PrintView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_PrintDoc)));
	return (CEx_PrintDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_PrintView message handlers
void CEx_PrintView::SetPageInfo(CDC *pDC, CPrintInfo *pInfo, PAGEINFO *pPage, 
								  int l, int t, int r, int b, int nLineSpace)
// nLineSpaceΪ�м�࣬l,t,r,b�ֱ��ʾ�������µ�ҳ�߾�
{
	// ����һ���豸��λ���ڶ���0.1mm
	double scaleX = 254.0/(double)GetDeviceCaps(pDC->m_hAttribDC, LOGPIXELSX);
	double scaleY = 254.0/(double)GetDeviceCaps(pDC->m_hAttribDC, LOGPIXELSY);
	int x = GetDeviceCaps(pDC->m_hAttribDC, PHYSICALOFFSETX);	
	int y = GetDeviceCaps(pDC->m_hAttribDC, PHYSICALOFFSETY);	
	int w = GetDeviceCaps(pDC->m_hAttribDC, PHYSICALWIDTH);	
	int h = GetDeviceCaps(pDC->m_hAttribDC, PHYSICALHEIGHT);	
	int nPageWidth = (int)((double)w*scaleX + 0.5);		// ֽ����λ0.1mm 
	int nPageHeight = (int)((double)h*scaleY + 0.5);		// ֽ�ߣ���λ0.1mm 
	int nPhyLeft = (int)((double)x*scaleX + 0.5);			// ������߾࣬��λ0.1mm 
	int nPhyTop = (int)((double)y*scaleY + 0.5);			// �����ϱ߾࣬��λ0.1mm 
	CRect rcTemp = pInfo->m_rectDraw;
	rcTemp.NormalizeRect();
	int nPhyRight = nPageWidth - rcTemp.Width() - nPhyLeft;	// �����ұ߾࣬��λ0.1mm
	int nPhyBottom = nPageHeight - rcTemp.Height() - nPhyTop;	// �����±߾࣬��λ0.1mm
	// ���߾�С������߾࣬���������
	if (l < nPhyLeft) l = nPhyLeft;
	if (t < nPhyTop) t = nPhyTop;
	if (r < nPhyRight) r = nPhyRight;
	if (b < nPhyBottom) b = nPhyBottom;
	pPage->nLMargin = l;
	pPage->nRMargin = r;
	pPage->nTMargin = t;
	pPage->nBMargin = b;
	pPage->nPhyLeft = nPhyLeft;
	pPage->nPhyRight = nPhyRight;
	pPage->nPhyTop = nPhyTop;
	pPage->nPhyBottom = nPhyBottom;
	pPage->sizePage = CSize(nPageWidth, nPageHeight);
	// ���㲢����pInfo->m_rectDraw�Ĵ�С
	pInfo->m_rectDraw.left = l - nPhyLeft;
	pInfo->m_rectDraw.top  = - t + nPhyTop;
	pInfo->m_rectDraw.right -= r - nPhyRight;
	pInfo->m_rectDraw.bottom += b - nPhyBottom;
	// �����ַ��Ĵ�С
	pPage->sizeChar = pDC->GetTextExtent("G");
	// �����еĴ�С
	pPage->sizeLine = CSize(pInfo->m_rectDraw.Width(), pPage->sizeChar.cy + nLineSpace);
}

void CEx_PrintView::PrintHead(CDC* pDC, CPrintInfo* pInfo, PAGEINFO page, 
CString title, int margin, int mode)
// mode��ʾҳü�ı�����ģʽ��0Ϊ���У�>0��ʾ�Ҷ��룬<0��ʾ�����
// title��ʾҳü���ݣ� marginΪҳü�붥�ߵľ���
{
	CFont font;
	font.CreateFontIndirect(&page.lfHead);
	CFont* oldFont = pDC->SelectObject(&font);
	CSize strSize = pDC->GetTextExtent(title);
	CRect rc = pInfo->m_rectDraw;
	CPoint pt;
	margin = margin - page.nPhyTop;
	if (margin<0) margin = 0;
	// ����mode�������ҳü�ı������
	if (mode < 0) pt = CPoint(rc.left, -margin);
	if (mode == 0) pt = CPoint(rc.CenterPoint().x - strSize.cx/2, -margin);
	if (mode > 0) pt = CPoint(rc.right - strSize.cx, -margin);
	pDC->TextOut(pt.x, pt.y, title);	// ����ҳü�ı�
	pt.y -= strSize.cy + 5;
	pDC->MoveTo(rc.left, pt.y);		// ����
	pDC->LineTo(rc.right, pt.y);
	pt.y -= 10;
	int absY = pt.y>0 ? pt.y : -pt.y;
	if (absY > page.nTMargin) pInfo->m_rectDraw.top = pt.y; 
	pDC->SelectObject(oldFont);
	font.DeleteObject();
}
void CEx_PrintView::PrintFoot(CDC* pDC, CPrintInfo* pInfo, PAGEINFO page, 
			CString title, int margin, int mode)
// mode��ʾҳ���ı�����ģʽ��0Ϊ���У�>0��ʾ�Ҷ��룬<0��ʾ�����
// title��ʾҳ�����ݣ� marginΪҳ����ױߵľ���
{
	CFont font;
	font.CreateFontIndirect(&page.lfFoot);
	CFont* oldFont = pDC->SelectObject(&font);
	CSize strSize = pDC->GetTextExtent(title);
	CRect rc = pInfo->m_rectDraw;
	CPoint pt;
	margin = page.nBMargin - margin - strSize.cy;
	// ����mode�������ҳü�ı������
	if (mode < 0) pt = CPoint(rc.left, rc.bottom - margin);
	if (mode == 0) pt = CPoint(rc.CenterPoint().x - strSize.cx/2,  rc.bottom - margin);
	if (mode > 0) pt = CPoint(rc.right - strSize.cx,  rc.bottom - margin);
	pDC->TextOut(pt.x, pt.y, title);	// ����ҳ���ı�
	if (margin < 0) 
		pInfo->m_rectDraw.bottom -= margin;
	pDC->SelectObject(oldFont);
}
void CEx_PrintView::AdjustAllLine(CDC *pDC)
{
	CEx_PrintDoc* pDoc = GetDocument();
	int nLineNums =  pDoc->m_strContents.GetSize();		// �ĵ�������
	int tab = m_pageInfo.sizeChar.cx * 4;				// Ϊһ��TAB����4���ַ�
	// ���ĵ���ÿһ�������д���ֻ����һ�Σ������Ԥ���ٶ�
	// ����Ľ��������arrText��
	CString str;
	if (pDoc->m_bNewDocument) {
		m_arrText.RemoveAll();
		CSize strSize;
		for (int i=0; i<nLineNums; i++) 	{
			str = pDoc->m_strContents.GetAt(i);
			strSize = pDC->GetTabbedTextExtent(str, 1, &tab);
			CString strTemp = str;
			while ( strSize.cx > m_pageInfo.sizeLine.cx) {
				unsigned int pos = 0;
				for (pos = 0; pos<strlen(strTemp); pos++) {
					CSize size = pDC->GetTabbedTextExtent(strTemp, pos+1, 1, &tab);
					if (size.cx >= m_pageInfo.sizeLine.cx) break;
				}
				// �жϺ���˫�ַ��Ƿ񱻷ֿ�
				int nCharHZ = 0;
				for (unsigned int chIndex = 0; chIndex <= pos; chIndex++)
					if (strTemp.GetAt(chIndex) < 0) nCharHZ++;
				if (nCharHZ % 2) pos = pos - 1;
				m_arrText.Add(strTemp.Left(pos+1));
				strTemp = strTemp.Mid(pos+1);
				strSize = pDC->GetTabbedTextExtent(strTemp, 1, &tab);
			}
			m_arrText.Add(strTemp);
		}
		pDoc->m_bNewDocument = FALSE;
		m_nLineArray.RemoveAll();
		m_nLineArray.Add(0);	
	}
}

void CEx_PrintView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	pDC->SetMapMode(MM_LOMETRIC);	// ��λ0.1mm
	CView::OnPrepareDC(pDC, pInfo);
	CEx_PrintDoc* pDoc = GetDocument();
	int nSize = pDoc->m_strContents.GetSize();
	if ((pInfo)&&(nSize)){
		if (pInfo->m_nCurPage<= pInfo->GetToPage()) 
			pInfo-> m_bContinuePrinting = TRUE;
		else 
			pInfo-> m_bContinuePrinting = FALSE;
	} 
}

void CEx_PrintView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	CFont font;
	font.CreateFontIndirect(&m_pageInfo.lfText);
	CFont* oldFont = pDC->SelectObject(&font);		// ������������
	SetPageInfo(pDC, pInfo, &m_pageInfo, 250, 250, 250, 250, 35);	// ����ҳ�߾���о�
	CEx_PrintDoc* pDoc = GetDocument();
	CString str = pDoc->GetTitle();				// ��ȡ�ĵ���
	PrintHead(pDC, pInfo, m_pageInfo, str, 200, -1);	// ��ӡҳü
	str.Format("- %d -", pInfo->m_nCurPage);
	PrintFoot(pDC, pInfo, m_pageInfo, str, 200, 0);	// ��ӡҳ��
	if (pDoc->m_strContents.GetSize() < 1)	return;	// û���ĵ������򷵻�
	AdjustAllLine(pDC);	// ����ÿ�е��ı�
	int nIndex = pInfo->m_nCurPage - 1;
	int nStartLine = m_nLineArray.GetAt(nIndex);
	CRect rc = pInfo->m_rectDraw;
	int y = rc.top;
	int nHeight = m_pageInfo.sizeLine.cy;
	int tab = m_pageInfo.sizeChar.cx * 4;			// Ϊһ��TAB����4���ַ�
	while (y >= pInfo->m_rectDraw.bottom) 
	{
		str =  m_arrText.GetAt(nStartLine);
		rc.top = y;
		pDC->TabbedTextOut(rc.left, y, str, 1, &tab, rc.left);  
		nStartLine++;
		if (nStartLine >= m_arrText.GetSize()) 
		{
			pInfo->SetMaxPage(pInfo->m_nCurPage);
			pInfo->m_pPD->m_pd.nToPage = pInfo->m_nCurPage;
			break;
		}
		y -= nHeight;
	}

	if (nIndex >= (m_nLineArray.GetSize() - 1)) 
		m_nLineArray.Add(nStartLine);	// ������һҳ����ʼ�к�
	pDC->SelectObject(oldFont);
	
	CView::OnPrint(pDC, pInfo);
}
