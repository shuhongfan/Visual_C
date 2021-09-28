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

CEx_StudentView::~CEx_StudentView()
{
}

BOOL CEx_StudentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= LVS_REPORT;		// ������
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
	CString strHeader[]={"ѧ��","����", "�Ա�", "��������", "��ѧרҵ"};
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
	// �����︴����Ƭ�ļ�
	CString strFileTO;
	strFileTO.Format("c://%s.bmp", dlg.m_strNo);
	if (!dlg.m_strPhotoFilePath.IsEmpty())
		DoCopyFile(strFileTO, dlg.m_strPhotoFilePath);
	// ����б���
	CListCtrl& m_ListCtrl = GetListCtrl();
	int nItem = m_ListCtrl.GetItemCount();
	CString strSex("Ů");
	if (dlg.m_bMale) strSex = "��";
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
		AfxMessageBox("Դ�ļ��޷��򿪣�����ʧ�ܣ�");
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
	// ��ȡ��ͷ��Ϣ��Ϊ��һ��
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
	// ��ȡ�����б�����Ϣ
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
	// ͨ��500�Ǵ���һ���ַ������ȵģ��������ַ������ȣ���
	// Insert���ַ���ĩβ���
	return str;
}

void CEx_StudentView::SetPageInfo(CDC *pDC, CPrintInfo *pInfo, PAGEINFO *pPage, int l, int t, int r, int b, int nLineSpace)
{
	// nLineSpaceΪ�м�࣬l,t,r,b�ֱ��ʾ�������µ�ҳ�߾�
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

void CEx_StudentView::PrintHead(CDC *pDC, CPrintInfo *pInfo, PAGEINFO page, CString title, int margin, int mode)
{
	// mode��ʾҳü�ı�����ģʽ��0Ϊ���У�>0��ʾ�Ҷ��룬<0��ʾ�����
	// title��ʾҳü���ݣ� marginΪҳü�붥�ߵľ���
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

void CEx_StudentView::PrintFoot(CDC *pDC, CPrintInfo *pInfo, PAGEINFO page, CString title, int margin, int mode)
{
	// mode��ʾҳ���ı�����ģʽ��0Ϊ���У�>0��ʾ�Ҷ��룬<0��ʾ�����
	// title��ʾҳ�����ݣ� marginΪҳ����ױߵľ���
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

void CEx_StudentView::AdjustAllLine(CDC *pDC)
{
	int nLineNums =  m_strContents.GetSize();		// �ĵ�������

	int tab = m_pageInfo.sizeChar.cx * 4;			// Ϊһ��TAB����4���ַ�

	// ���ĵ���ÿһ�������д���ֻ����һ�Σ������Ԥ���ٶ�
	// ����Ľ��������arrText��
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
	m_nLineArray.RemoveAll();
	m_nLineArray.Add(0);	
}

void CEx_StudentView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	ReadListViewData();
	pDC->SetMapMode(MM_LOMETRIC);	// ��λ0.1mm
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
	CFont* oldFont = pDC->SelectObject(&font);		// ������������
	SetPageInfo(pDC, pInfo, &m_pageInfo, 250, 250, 250, 250, 35);	// ����ҳ�߾���о�
	PrintHead(pDC, pInfo, m_pageInfo, "ѧ����Ϣ����ϵͳ������ߣ����к�", 200, -1);	// ��ӡҳü
	CString str;
	str.Format("- %d -", pInfo->m_nCurPage);
	PrintFoot(pDC, pInfo, m_pageInfo, str, 200, 0);	// ��ӡҳ��

	if (m_strContents.GetSize() < 1)	return;		// û���ĵ������򷵻�

	AdjustAllLine(pDC);	// ����ÿ�е��ı�

	int nIndex = pInfo->m_nCurPage - 1;
	int nStartLine = m_nLineArray.GetAt(nIndex);

	CRect rc = pInfo->m_rectDraw;
	int y = rc.top;
	int nHeight = m_pageInfo.sizeLine.cy;
	int tab = m_pageInfo.sizeChar.cx * 4;				// Ϊһ��TAB����4���ַ�
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
	CListView::OnPrint(pDC, pInfo);
}
