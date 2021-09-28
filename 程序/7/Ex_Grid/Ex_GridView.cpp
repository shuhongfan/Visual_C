// Ex_GridView.cpp : implementation of the CEx_GridView class
//

#include "stdafx.h"
#include "Ex_Grid.h"

#include "Ex_GridSet.h"
#include "Ex_GridDoc.h"
#include "Ex_GridView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_GridView

IMPLEMENT_DYNCREATE(CEx_GridView, CRecordView)

BEGIN_MESSAGE_MAP(CEx_GridView, CRecordView)
	//{{AFX_MSG_MAP(CEx_GridView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_GridView construction/destruction

CEx_GridView::CEx_GridView()
	: CRecordView(CEx_GridView::IDD)
{
	//{{AFX_DATA_INIT(CEx_GridView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CEx_GridView::~CEx_GridView()
{
}

void CEx_GridView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEx_GridView)
	DDX_Control(pDX, IDC_MSFLEXGRID1, m_MSFGrid);
	//}}AFX_DATA_MAP
}

BOOL CEx_GridView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CEx_GridView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ex_GridSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	while (!m_pSet->IsEOF())	m_pSet->MoveNext();
	m_pSet->MoveFirst();
	m_MSFGrid.SetCols(m_pSet->m_nFields+1 );		// 根据字段数设置单元格最大列数
	m_MSFGrid.SetRows(m_pSet->GetRecordCount()+1);	// 根据记录数设置单元格最大行数
	m_MSFGrid.SetColWidth(-1,1440);					
	// 将所有的单元格都设为相同的列宽。-1表示所有的列，列宽单位为一个点的
	// 1/20(一个点是1/72英寸)，也就是说，1440刚好为1英寸。
	// 定义单元格的表头
	m_MSFGrid.SetRow(0);	m_MSFGrid.SetCol(0);	// 定位到(0,0)单元格
	m_MSFGrid.SetText("记录号");		// 设置其显示内容
	m_MSFGrid.SetCellAlignment(4);		// 设置单元格对齐方式，4表示水平和垂直居中
	CODBCFieldInfo field;
	for (UINT i=0; i<m_pSet->m_nFields; i++)	{
		m_MSFGrid.SetRow(0);	m_MSFGrid.SetCol(i+1);	
		m_pSet->GetODBCFieldInfo(i,field);		// 获取指定字段信息
		m_MSFGrid.SetText(field.m_strName);	
		m_MSFGrid.SetCellAlignment(4);	
	}
	int iRow=1;
	while (!m_pSet->IsEOF())	{				// 将表的记录内容显示在单元格中
		CString str;
		str.Format("记录%d",iRow);
		m_MSFGrid.SetRow(iRow);	m_MSFGrid.SetCol(0);
		m_MSFGrid.SetText(str);
		m_MSFGrid.SetCellAlignment(4);	
		for (UINT i=0; i<m_pSet->m_nFields; i++) 
		{
			m_MSFGrid.SetRow(iRow);	  m_MSFGrid.SetCol(i+1);	
			m_pSet->GetFieldValue(i, str);		// 获取指定字段值，并自动转换成字符串
			m_MSFGrid.SetText(str);	
			m_MSFGrid.SetCellAlignment(4);	
		}
		iRow++;
		m_pSet->MoveNext();
	}
	m_MSFGrid.SetRow(1);		m_MSFGrid.SetCol(1);
	m_pSet->MoveFirst();

}

/////////////////////////////////////////////////////////////////////////////
// CEx_GridView printing

BOOL CEx_GridView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_GridView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_GridView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_GridView diagnostics

#ifdef _DEBUG
void CEx_GridView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CEx_GridView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CEx_GridDoc* CEx_GridView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_GridDoc)));
	return (CEx_GridDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_GridView database support
CRecordset* CEx_GridView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CEx_GridView message handlers
