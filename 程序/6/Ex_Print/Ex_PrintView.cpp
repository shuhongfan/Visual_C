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
	memset(&m_pageInfo, 0, sizeof(m_pageInfo));		// 所有成员置为0
	double fontScale = 254.0/72.0;	// 一个点相当于多少0.1mm
	// 页眉字体
	m_pageInfo.lfHead.lfHeight = - (int)(9 * fontScale + 0.5);		// 9号字
	m_pageInfo.lfHead.lfWeight = FW_BOLD;
	m_pageInfo.lfHead.lfCharSet = GB2312_CHARSET;
	strcpy((LPSTR)&(m_pageInfo.lfHead.lfFaceName), "黑体");
	// 页脚字体
	m_pageInfo.lfFoot.lfHeight = - (int)(9 * fontScale + 0.5);		// 9号字
	m_pageInfo.lfFoot.lfWeight = FW_NORMAL;
	m_pageInfo.lfFoot.lfCharSet = GB2312_CHARSET;
	strcpy((LPSTR)&(m_pageInfo.lfFoot.lfFaceName), "楷体_GB2312");
	// 正文字体
	m_pageInfo.lfText.lfHeight = - (int)(11 * fontScale + 0.5);		// 11号字
	m_pageInfo.lfText.lfWeight = FW_NORMAL;
	m_pageInfo.lfText.lfCharSet = GB2312_CHARSET;
	strcpy((LPSTR)&(m_pageInfo.lfText.lfFaceName), "宋体");

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
// nLineSpace为行间距，l,t,r,b分别表示左上右下的页边距
{
	// 计算一个设备单位等于多少0.1mm
	double scaleX = 254.0/(double)GetDeviceCaps(pDC->m_hAttribDC, LOGPIXELSX);
	double scaleY = 254.0/(double)GetDeviceCaps(pDC->m_hAttribDC, LOGPIXELSY);
	int x = GetDeviceCaps(pDC->m_hAttribDC, PHYSICALOFFSETX);	
	int y = GetDeviceCaps(pDC->m_hAttribDC, PHYSICALOFFSETY);	
	int w = GetDeviceCaps(pDC->m_hAttribDC, PHYSICALWIDTH);	
	int h = GetDeviceCaps(pDC->m_hAttribDC, PHYSICALHEIGHT);	
	int nPageWidth = (int)((double)w*scaleX + 0.5);		// 纸宽，单位0.1mm 
	int nPageHeight = (int)((double)h*scaleY + 0.5);		// 纸高，单位0.1mm 
	int nPhyLeft = (int)((double)x*scaleX + 0.5);			// 物理左边距，单位0.1mm 
	int nPhyTop = (int)((double)y*scaleY + 0.5);			// 物理上边距，单位0.1mm 
	CRect rcTemp = pInfo->m_rectDraw;
	rcTemp.NormalizeRect();
	int nPhyRight = nPageWidth - rcTemp.Width() - nPhyLeft;	// 物理右边距，单位0.1mm
	int nPhyBottom = nPageHeight - rcTemp.Height() - nPhyTop;	// 物理下边距，单位0.1mm
	// 若边距小于物理边距，则调整它们
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
	// 计算并调整pInfo->m_rectDraw的大小
	pInfo->m_rectDraw.left = l - nPhyLeft;
	pInfo->m_rectDraw.top  = - t + nPhyTop;
	pInfo->m_rectDraw.right -= r - nPhyRight;
	pInfo->m_rectDraw.bottom += b - nPhyBottom;
	// 计算字符的大小
	pPage->sizeChar = pDC->GetTextExtent("G");
	// 计算行的大小
	pPage->sizeLine = CSize(pInfo->m_rectDraw.Width(), pPage->sizeChar.cy + nLineSpace);
}

void CEx_PrintView::PrintHead(CDC* pDC, CPrintInfo* pInfo, PAGEINFO page, 
CString title, int margin, int mode)
// mode表示页眉文本对齐模式，0为居中，>0表示右对齐，<0表示左对齐
// title表示页眉内容， margin为页眉与顶边的距离
{
	CFont font;
	font.CreateFontIndirect(&page.lfHead);
	CFont* oldFont = pDC->SelectObject(&font);
	CSize strSize = pDC->GetTextExtent(title);
	CRect rc = pInfo->m_rectDraw;
	CPoint pt;
	margin = margin - page.nPhyTop;
	if (margin<0) margin = 0;
	// 根据mode计算绘制页眉文本的起点
	if (mode < 0) pt = CPoint(rc.left, -margin);
	if (mode == 0) pt = CPoint(rc.CenterPoint().x - strSize.cx/2, -margin);
	if (mode > 0) pt = CPoint(rc.right - strSize.cx, -margin);
	pDC->TextOut(pt.x, pt.y, title);	// 绘制页眉文本
	pt.y -= strSize.cy + 5;
	pDC->MoveTo(rc.left, pt.y);		// 画线
	pDC->LineTo(rc.right, pt.y);
	pt.y -= 10;
	int absY = pt.y>0 ? pt.y : -pt.y;
	if (absY > page.nTMargin) pInfo->m_rectDraw.top = pt.y; 
	pDC->SelectObject(oldFont);
	font.DeleteObject();
}
void CEx_PrintView::PrintFoot(CDC* pDC, CPrintInfo* pInfo, PAGEINFO page, 
			CString title, int margin, int mode)
// mode表示页脚文本对齐模式，0为居中，>0表示右对齐，<0表示左对齐
// title表示页脚内容， margin为页脚与底边的距离
{
	CFont font;
	font.CreateFontIndirect(&page.lfFoot);
	CFont* oldFont = pDC->SelectObject(&font);
	CSize strSize = pDC->GetTextExtent(title);
	CRect rc = pInfo->m_rectDraw;
	CPoint pt;
	margin = page.nBMargin - margin - strSize.cy;
	// 根据mode计算绘制页眉文本的起点
	if (mode < 0) pt = CPoint(rc.left, rc.bottom - margin);
	if (mode == 0) pt = CPoint(rc.CenterPoint().x - strSize.cx/2,  rc.bottom - margin);
	if (mode > 0) pt = CPoint(rc.right - strSize.cx,  rc.bottom - margin);
	pDC->TextOut(pt.x, pt.y, title);	// 绘制页脚文本
	if (margin < 0) 
		pInfo->m_rectDraw.bottom -= margin;
	pDC->SelectObject(oldFont);
}
void CEx_PrintView::AdjustAllLine(CDC *pDC)
{
	CEx_PrintDoc* pDoc = GetDocument();
	int nLineNums =  pDoc->m_strContents.GetSize();		// 文档总行数
	int tab = m_pageInfo.sizeChar.cx * 4;				// 为一个TAB设置4个字符
	// 将文档的每一行作换行处理，只处理一次，以提高预览速度
	// 处理的结果保存在arrText中
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
				// 判断汉字双字符是否被分开
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
	pDC->SetMapMode(MM_LOMETRIC);	// 单位0.1mm
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
	CFont* oldFont = pDC->SelectObject(&font);		// 设置正文字体
	SetPageInfo(pDC, pInfo, &m_pageInfo, 250, 250, 250, 250, 35);	// 设置页边距和行距
	CEx_PrintDoc* pDoc = GetDocument();
	CString str = pDoc->GetTitle();				// 获取文档名
	PrintHead(pDC, pInfo, m_pageInfo, str, 200, -1);	// 打印页眉
	str.Format("- %d -", pInfo->m_nCurPage);
	PrintFoot(pDC, pInfo, m_pageInfo, str, 200, 0);	// 打印页脚
	if (pDoc->m_strContents.GetSize() < 1)	return;	// 没有文档内容则返回
	AdjustAllLine(pDC);	// 调整每行的文本
	int nIndex = pInfo->m_nCurPage - 1;
	int nStartLine = m_nLineArray.GetAt(nIndex);
	CRect rc = pInfo->m_rectDraw;
	int y = rc.top;
	int nHeight = m_pageInfo.sizeLine.cy;
	int tab = m_pageInfo.sizeChar.cx * 4;			// 为一个TAB设置4个字符
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
		m_nLineArray.Add(nStartLine);	// 保存下一页的起始行号
	pDC->SelectObject(oldFont);
	
	CView::OnPrint(pDC, pInfo);
}
