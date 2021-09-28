// Ex_StudentView.cpp : implementation of the CEx_StudentView class
//

#include "stdafx.h"
#include "Ex_Student.h"

#include "Ex_StudentDoc.h"
#include "Ex_StudentView.h"

#include "StuInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView

IMPLEMENT_DYNCREATE(CEx_StudentView, CListView)

BEGIN_MESSAGE_MAP(CEx_StudentView, CListView)
	//{{AFX_MSG_MAP(CEx_StudentView)
	ON_COMMAND(ID_STUINFO_ADD, OnStuinfoAdd)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView construction/destruction

CEx_StudentView::CEx_StudentView()
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

CEx_StudentView::~CEx_StudentView()
{
}

BOOL CEx_StudentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= LVS_REPORT;		// 报表风格
	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView drawing

void CEx_StudentView::OnDraw(CDC* pDC)
{
	CEx_StudentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CEx_StudentView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strHeader[]={"学号","姓名", "性别", "出生年月", "所学专业"};
	int nLong[] = {80, 80, 60, 100, 180};
	for (int nCol=0; nCol<sizeof(strHeader)/sizeof(CString); nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nLong[nCol]);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView printing

BOOL CEx_StudentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	ReadListViewData();
	int nSize =m_strContents.GetSize();
	if (nSize<1) pInfo->SetMaxPage(1);
	return DoPreparePrinting(pInfo);
}

void CEx_StudentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_StudentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView diagnostics

#ifdef _DEBUG
void CEx_StudentView::AssertValid() const
{
	CListView::AssertValid();
}

void CEx_StudentView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CEx_StudentDoc* CEx_StudentView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_StudentDoc)));
	return (CEx_StudentDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentView message handlers

void CEx_StudentView::OnStuinfoAdd() 
{
	CStuInfoDlg dlg;
	if (dlg.DoModal() != IDOK) return;
	// 在这里复制照片文件
	CString strFileTO;
	strFileTO.Format("c://%s.bmp", dlg.m_strNo);
	if (!dlg.m_strPhotoFilePath.IsEmpty())
		DoCopyFile(strFileTO, dlg.m_strPhotoFilePath);
	// 添加列表项
	CListCtrl& m_ListCtrl = GetListCtrl();
	int nItem = m_ListCtrl.GetItemCount();
	CString strSex("女");
	if (dlg.m_bMale) strSex = "男";
	m_ListCtrl.InsertItem( nItem, dlg.m_strNo );
	m_ListCtrl.SetItemText( nItem, 1, dlg.m_strName );
	m_ListCtrl.SetItemText( nItem, 2, strSex );
	m_ListCtrl.SetItemText( nItem, 3, dlg.m_tBirth.Format("%Y-%m-%d") );
	m_ListCtrl.SetItemText( nItem, 4, dlg.m_strSpecial);	
}

void CEx_StudentView::DoCopyFile(CString strFileTo, CString strFileFrom)
{
	CFile fileFrom, fileTo;

	if (!fileFrom.Open( strFileFrom, CFile::modeRead))
	{
		AfxMessageBox("源文件无法打开，复制失败！");
		return;
	}
	fileTo.Open( strFileTo, CFile::modeCreate | CFile::modeWrite );
	
	BYTE buffer[4096];
    DWORD dwRead;
    do{
         dwRead = fileFrom.Read(buffer, 4096);
         fileTo.Write(buffer, dwRead);
    } while (dwRead > 0);

	fileFrom.Close();
	fileTo.Close();
}

void CEx_StudentView::ReadListViewData()
{
	m_strContents.RemoveAll();
	CListCtrl& m_ListCtrl = GetListCtrl();
	int nCount = 0;
	CHeaderCtrl* pHeaderCtrl = m_ListCtrl.GetHeaderCtrl();
	if ( pHeaderCtrl!= NULL)	nCount = pHeaderCtrl->GetItemCount();
	// 读取表头信息作为第一行
	LVCOLUMN	column;
	TCHAR		lpBuffer[256];
	int			nWidthCharNum[100];
	CString str, strTemp;
	for (int nCol = 0; nCol < nCount; nCol++)	{
		column.mask		= LVCF_TEXT; 
		column.pszText		= lpBuffer;
		column.cchTextMax	= 256;
		m_ListCtrl.GetColumn( nCol, &column );
		nWidthCharNum[nCol] = (int)(m_ListCtrl.GetColumnWidth( nCol )/6.5);
		strTemp.Format("%s", lpBuffer);
		strTemp.TrimRight();
		int nDelta = nWidthCharNum[nCol] - strTemp.GetLength();
		if (nDelta>0)	strTemp = AppendStringSpace( strTemp, nDelta);
		else	strTemp = strTemp.Left(nWidthCharNum[nCol]);
		str = str + strTemp;
	}
	str.TrimRight();
	m_strContents.Add( str );
	// 读取各个列表项信息
	int nItemCount = m_ListCtrl.GetItemCount();
	for ( int nItem=0; nItem<nItemCount; nItem++)	{
		str.Empty();
		strTemp.Empty();
		for (int i=0; i<nCount; i++ )	{
			strTemp = m_ListCtrl.GetItemText(nItem, i);
			strTemp.TrimRight();
			int nDelta = nWidthCharNum[i] - strTemp.GetLength();
			if (nDelta>0)	strTemp = AppendStringSpace( strTemp, nDelta);
			else	strTemp = strTemp.Left(nWidthCharNum[i]);
			str = str + strTemp;
		}
		str.TrimRight();
		m_strContents.Add( str );
	}

}

CString CEx_StudentView::AppendStringSpace(CString str, int nNum)
{
	for (int i=0; i<nNum; i++)
		str.Insert( 500, ' ');		
	// 通常500是大于一个字符串长度的，当大于字符串长度，则
	// Insert在字符串末尾添加
	return str;
}

void CEx_StudentView::SetPageInfo(CDC *pDC, CPrintInfo *pInfo, PAGEINFO *pPage, int l, int t, int r, int b, int nLineSpace)
{
	// nLineSpace为行间距，l,t,r,b分别表示左上右下的页边距
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

void CEx_StudentView::PrintHead(CDC *pDC, CPrintInfo *pInfo, PAGEINFO page, CString title, int margin, int mode)
{
	// mode表示页眉文本对齐模式，0为居中，>0表示右对齐，<0表示左对齐
	// title表示页眉内容， margin为页眉与顶边的距离
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

void CEx_StudentView::PrintFoot(CDC *pDC, CPrintInfo *pInfo, PAGEINFO page, CString title, int margin, int mode)
{
	// mode表示页脚文本对齐模式，0为居中，>0表示右对齐，<0表示左对齐
	// title表示页脚内容， margin为页脚与底边的距离
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

void CEx_StudentView::AdjustAllLine(CDC *pDC)
{
	int nLineNums =  m_strContents.GetSize();		// 文档总行数

	int tab = m_pageInfo.sizeChar.cx * 4;			// 为一个TAB设置4个字符

	// 将文档的每一行作换行处理，只处理一次，以提高预览速度
	// 处理的结果保存在arrText中
	CString str;
	m_arrText.RemoveAll();
	CSize strSize;
	for (int i=0; i<nLineNums; i++) 
	{
		str = m_strContents.GetAt(i);
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
	m_nLineArray.RemoveAll();
	m_nLineArray.Add(0);	
}

void CEx_StudentView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	ReadListViewData();
	pDC->SetMapMode(MM_LOMETRIC);	// 单位0.1mm
	CListView::OnPrepareDC(pDC, pInfo);
	int nSize = m_strContents.GetSize();
	if ((pInfo)&&(nSize)){
		if (pInfo->m_nCurPage<= pInfo->GetToPage()) 
			pInfo-> m_bContinuePrinting = TRUE;
		else 
			pInfo-> m_bContinuePrinting = FALSE;
	} 
}

void CEx_StudentView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	CFont font;
	font.CreateFontIndirect(&m_pageInfo.lfText);
	CFont* oldFont = pDC->SelectObject(&font);		// 设置正文字体
	SetPageInfo(pDC, pInfo, &m_pageInfo, 250, 250, 250, 250, 35);	// 设置页边距和行距
	PrintHead(pDC, pInfo, m_pageInfo, "学生信息管理系统，设计者：丁有和", 200, -1);	// 打印页眉
	CString str;
	str.Format("- %d -", pInfo->m_nCurPage);
	PrintFoot(pDC, pInfo, m_pageInfo, str, 200, 0);	// 打印页脚

	if (m_strContents.GetSize() < 1)	return;		// 没有文档内容则返回

	AdjustAllLine(pDC);	// 调整每行的文本

	int nIndex = pInfo->m_nCurPage - 1;
	int nStartLine = m_nLineArray.GetAt(nIndex);

	CRect rc = pInfo->m_rectDraw;
	int y = rc.top;
	int nHeight = m_pageInfo.sizeLine.cy;
	int tab = m_pageInfo.sizeChar.cx * 4;				// 为一个TAB设置4个字符
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
	CListView::OnPrint(pDC, pInfo);
}
