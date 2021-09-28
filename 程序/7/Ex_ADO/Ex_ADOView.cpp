// Ex_ADOView.cpp : implementation of the CEx_ADOView class
//

#include "stdafx.h"
#include "Ex_ADO.h"

#include "Ex_ADODoc.h"
#include "Ex_ADOView.h"
#include "StuInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOView

IMPLEMENT_DYNCREATE(CEx_ADOView, CListView)

BEGIN_MESSAGE_MAP(CEx_ADOView, CListView)
	//{{AFX_MSG_MAP(CEx_ADOView)
	ON_WM_DESTROY()
	ON_COMMAND(ID_OP_ADD, OnOpAdd)
	ON_COMMAND(ID_OP_CHA, OnOpCha)
	ON_COMMAND(ID_OP_DEL, OnOpDel)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOView construction/destruction

CEx_ADOView::CEx_ADOView()
{
	// TODO: add construction code here

}

CEx_ADOView::~CEx_ADOView()
{
}

BOOL CEx_ADOView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= LVS_REPORT;		// 报表风格
	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOView drawing

void CEx_ADOView::OnDraw(CDC* pDC)
{
	CEx_ADODoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CEx_ADOView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
	CListCtrl& m_ListCtrl = GetListCtrl();
	CString strHeader[]={"学号","姓名", "性别","出生年月","专业"};
	int nLong[] = {80, 80, 60, 100, 180};
	for (int nCol=0; nCol<sizeof(strHeader)/sizeof(CString); nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_CENTER,nLong[nCol]);


	::CoInitialize(NULL); // COM环境初始化
	m_pConnection.CreateInstance(__uuidof(Connection)); //初始化Connection指针
	m_pRecordset.CreateInstance(__uuidof(Recordset));	//初始化Recordset指针
	// 连接数据源为“Database Example For VC++”
	m_pConnection->Open("DSN=Database Example For VC++","","",0); 
	ResetListItem();
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOView printing

BOOL CEx_ADOView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx_ADOView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx_ADOView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOView diagnostics

#ifdef _DEBUG
void CEx_ADOView::AssertValid() const
{
	CListView::AssertValid();
}

void CEx_ADOView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CEx_ADODoc* CEx_ADOView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_ADODoc)));
	return (CEx_ADODoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_ADOView message handlers

void CEx_ADOView::ResetListItem()
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	m_ListCtrl.DeleteAllItems();

	int nItem = 0;

	CString strSql = "SELECT * FROM student ORDER BY studentno DESC";
	BSTR bstrSQL = strSql.AllocSysString();		// 将CString转换成BSTR
	m_pRecordset->Open( bstrSQL,(IDispatch*)m_pConnection, adOpenDynamic, adLockOptimistic, adCmdText); 
	// 打开表student
	while(!m_pRecordset->adoEOF)	// 遍历所有记录
	{ 
		_variant_t value;			// VARIANT数据类型
		value = m_pRecordset->GetCollect("studentno");	// 得到字段studentno的值
		m_ListCtrl.InsertItem( nItem, (char*)_bstr_t(value));
		value = m_pRecordset->GetCollect("studentname");	// 得到字段studentname的值
		m_ListCtrl.SetItemText( nItem, 1, (char*)_bstr_t(value));
		value = m_pRecordset->GetCollect("xb");	// 得到字段xb的值
		_variant_t bValue(true);
		if ( value == bValue )
			m_ListCtrl.SetItemText( nItem, 2, "男");
		else
			m_ListCtrl.SetItemText( nItem, 2, "女");
		value = m_pRecordset->GetCollect("birthday");	// 得到字段birthday的值
		m_ListCtrl.SetItemText( nItem, 3, (char*)_bstr_t(value));
		value = m_pRecordset->GetCollect("special");	// 得到字段special的值
		m_ListCtrl.SetItemText( nItem, 4, (char*)_bstr_t(value));
		m_pRecordset->MoveNext();//转到下一条纪录
	}
	m_pRecordset->Close();
}

void CEx_ADOView::OnDestroy() 
{
	CListView::OnDestroy();
	// TODO: Add your message handler code here
	if (m_pConnection)
		m_pConnection->Close();// 关闭连接	
}

void CEx_ADOView::OnOpAdd() 
{
	// TODO: Add your command handler code here
	CStuInfoDlg dlg;
	if (IDOK != dlg.DoModal()) return;
	CString strSql = "SELECT * FROM student";
	BSTR bstrSQL = strSql.AllocSysString();		// 将CString转换成BSTR
	m_pRecordset->Open( bstrSQL,(IDispatch*)m_pConnection, adOpenDynamic, adLockOptimistic, adCmdText); 
	m_pRecordset->AddNew();
	m_pRecordset->PutCollect("studentno",_variant_t(dlg.m_strNo));
	m_pRecordset->PutCollect("studentname",_variant_t(dlg.m_strName));
	if (dlg.m_bMale)
		m_pRecordset->PutCollect("xb",_variant_t(true));
	else
		m_pRecordset->PutCollect("xb",_variant_t(false));
	COleDateTime birth( dlg.m_tBirth.GetYear(), dlg.m_tBirth.GetMonth(), 
		dlg.m_tBirth.GetDay(), 0, 0, 0);
	m_pRecordset->PutCollect("birthday",_variant_t(birth));
	m_pRecordset->PutCollect("special",_variant_t(dlg.m_strSpecial));
	m_pRecordset->Update();	// 使添加有效
	m_pRecordset->Close();
	ResetListItem();
}

void CEx_ADOView::OnOpCha() 
{
	// TODO: Add your command handler code here
	// 获取选中的列表项，并取其该列表项的学号内容
	CListCtrl& m_ListCtrl = GetListCtrl();
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox("你还没有选中列表项！");
		return;
	}
	int nItem = m_ListCtrl.GetNextSelectedItem( pos );
	CString strItem;
	strItem = m_ListCtrl.GetItemText( nItem, 0 );
	// 打开表
	CString strSql;
	strSql.Format("SELECT * FROM student WHERE studentno='%s'", strItem);
	BSTR bstrSQL = strSql.AllocSysString();		// 将CString转换成BSTR
	m_pRecordset->Open( bstrSQL,(IDispatch*)m_pConnection, adOpenDynamic, adLockOptimistic, adCmdText); 
	
	// 将表中的数据读取到对话框中
	CStuInfoDlg dlg;
	dlg.m_strNo = strItem;
	_variant_t value;			// VARIANT数据类型
	value = m_pRecordset->GetCollect("studentname");	// 得到字段studentname的值
	dlg.m_strName.Format("%s", (char*)_bstr_t(value));
	value = m_pRecordset->GetCollect("xb");	// 得到字段xb的值
	if ( value == _variant_t(true) )
		dlg.m_bMale = true;
	else
		dlg.m_bMale = false;
	value = m_pRecordset->GetCollect("birthday");	// 得到字段birthday的值
	COleDateTime t(value);
	CTime time(t.GetYear(), t.GetMonth(), t.GetDay(), 0, 0, 0 );
	dlg.m_tBirth = time;
	value = m_pRecordset->GetCollect("special");	// 得到字段special的值
	dlg.m_strSpecial.Format("%s", (char*)_bstr_t(value));
	if (IDOK != dlg.DoModal()) return;
	// 修改记录
	m_pRecordset->PutCollect("studentno",_variant_t(dlg.m_strNo));
	m_pRecordset->PutCollect("studentname",_variant_t(dlg.m_strName));
	if (dlg.m_bMale)
		m_pRecordset->PutCollect("xb",_variant_t(true));
	else
		m_pRecordset->PutCollect("xb",_variant_t(false));
	COleDateTime birth( dlg.m_tBirth.GetYear(), dlg.m_tBirth.GetMonth(), 
		dlg.m_tBirth.GetDay(), 0, 0, 0);
	m_pRecordset->PutCollect("birthday",_variant_t(birth));
	m_pRecordset->PutCollect("special",_variant_t(dlg.m_strSpecial));
	m_pRecordset->Update();	// 使修改有效
	m_pRecordset->Close();
	ResetListItem();
}

void CEx_ADOView::OnOpDel() 
{
	// TODO: Add your command handler code here
	CListCtrl& m_ListCtrl = GetListCtrl();
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox("你还没有选中列表项！");
		return;
	}
	int nItem = m_ListCtrl.GetNextSelectedItem( pos );
	CString strItem;
	strItem = m_ListCtrl.GetItemText( nItem, 0 );
	CString str;
	str.Format("你确实要删除 %s 列表项(记录)吗？", strItem );
	if ( IDOK != MessageBox(str, "删除确认", MB_ICONQUESTION | MB_OKCANCEL ))
		return;
	// 这里使用命令对象来删除
	_CommandPtr pCmd;
	pCmd.CreateInstance(__uuidof(Command));	// 初始化Command指针
	pCmd->ActiveConnection = m_pConnection;	// 指向已有的连接
	CString strComm;
	strComm.Format("DELETE FROM student WHERE studentno='%s'", strItem);
	pCmd->CommandText = strComm.AllocSysString();
	pCmd->Execute(NULL, NULL, adCmdText );	// 执行命令

/*	// 若使用Recordset来操作，则代码如下
	CString strSql;
	strSql.Format("SELECT * FROM student WHERE studentno='%s'", strItem);
	BSTR bstrSQL = strSql.AllocSysString();		// 将CString转换成BSTR
	m_pRecordset->Open( bstrSQL,(IDispatch*)m_pConnection, adOpenDynamic, adLockOptimistic, adCmdText); 
	m_pRecordset->Delete(adAffectCurrent);		// 删除当前行
	m_pRecordset->MoveFirst();					// 使删除有效
	m_pRecordset->Close();*/
	ResetListItem();
}
