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
	cs.style |= LVS_REPORT;		// ������
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
	CString strHeader[]={"ѧ��","����", "�Ա�","��������","רҵ"};
	int nLong[] = {80, 80, 60, 100, 180};
	for (int nCol=0; nCol<sizeof(strHeader)/sizeof(CString); nCol++)
		m_ListCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_CENTER,nLong[nCol]);


	::CoInitialize(NULL); // COM������ʼ��
	m_pConnection.CreateInstance(__uuidof(Connection)); //��ʼ��Connectionָ��
	m_pRecordset.CreateInstance(__uuidof(Recordset));	//��ʼ��Recordsetָ��
	// ��������ԴΪ��Database Example For VC++��
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
	BSTR bstrSQL = strSql.AllocSysString();		// ��CStringת����BSTR
	m_pRecordset->Open( bstrSQL,(IDispatch*)m_pConnection, adOpenDynamic, adLockOptimistic, adCmdText); 
	// �򿪱�student
	while(!m_pRecordset->adoEOF)	// �������м�¼
	{ 
		_variant_t value;			// VARIANT��������
		value = m_pRecordset->GetCollect("studentno");	// �õ��ֶ�studentno��ֵ
		m_ListCtrl.InsertItem( nItem, (char*)_bstr_t(value));
		value = m_pRecordset->GetCollect("studentname");	// �õ��ֶ�studentname��ֵ
		m_ListCtrl.SetItemText( nItem, 1, (char*)_bstr_t(value));
		value = m_pRecordset->GetCollect("xb");	// �õ��ֶ�xb��ֵ
		_variant_t bValue(true);
		if ( value == bValue )
			m_ListCtrl.SetItemText( nItem, 2, "��");
		else
			m_ListCtrl.SetItemText( nItem, 2, "Ů");
		value = m_pRecordset->GetCollect("birthday");	// �õ��ֶ�birthday��ֵ
		m_ListCtrl.SetItemText( nItem, 3, (char*)_bstr_t(value));
		value = m_pRecordset->GetCollect("special");	// �õ��ֶ�special��ֵ
		m_ListCtrl.SetItemText( nItem, 4, (char*)_bstr_t(value));
		m_pRecordset->MoveNext();//ת����һ����¼
	}
	m_pRecordset->Close();
}

void CEx_ADOView::OnDestroy() 
{
	CListView::OnDestroy();
	// TODO: Add your message handler code here
	if (m_pConnection)
		m_pConnection->Close();// �ر�����	
}

void CEx_ADOView::OnOpAdd() 
{
	// TODO: Add your command handler code here
	CStuInfoDlg dlg;
	if (IDOK != dlg.DoModal()) return;
	CString strSql = "SELECT * FROM student";
	BSTR bstrSQL = strSql.AllocSysString();		// ��CStringת����BSTR
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
	m_pRecordset->Update();	// ʹ�����Ч
	m_pRecordset->Close();
	ResetListItem();
}

void CEx_ADOView::OnOpCha() 
{
	// TODO: Add your command handler code here
	// ��ȡѡ�е��б����ȡ����б����ѧ������
	CListCtrl& m_ListCtrl = GetListCtrl();
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox("�㻹û��ѡ���б��");
		return;
	}
	int nItem = m_ListCtrl.GetNextSelectedItem( pos );
	CString strItem;
	strItem = m_ListCtrl.GetItemText( nItem, 0 );
	// �򿪱�
	CString strSql;
	strSql.Format("SELECT * FROM student WHERE studentno='%s'", strItem);
	BSTR bstrSQL = strSql.AllocSysString();		// ��CStringת����BSTR
	m_pRecordset->Open( bstrSQL,(IDispatch*)m_pConnection, adOpenDynamic, adLockOptimistic, adCmdText); 
	
	// �����е����ݶ�ȡ���Ի�����
	CStuInfoDlg dlg;
	dlg.m_strNo = strItem;
	_variant_t value;			// VARIANT��������
	value = m_pRecordset->GetCollect("studentname");	// �õ��ֶ�studentname��ֵ
	dlg.m_strName.Format("%s", (char*)_bstr_t(value));
	value = m_pRecordset->GetCollect("xb");	// �õ��ֶ�xb��ֵ
	if ( value == _variant_t(true) )
		dlg.m_bMale = true;
	else
		dlg.m_bMale = false;
	value = m_pRecordset->GetCollect("birthday");	// �õ��ֶ�birthday��ֵ
	COleDateTime t(value);
	CTime time(t.GetYear(), t.GetMonth(), t.GetDay(), 0, 0, 0 );
	dlg.m_tBirth = time;
	value = m_pRecordset->GetCollect("special");	// �õ��ֶ�special��ֵ
	dlg.m_strSpecial.Format("%s", (char*)_bstr_t(value));
	if (IDOK != dlg.DoModal()) return;
	// �޸ļ�¼
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
	m_pRecordset->Update();	// ʹ�޸���Ч
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
		MessageBox("�㻹û��ѡ���б��");
		return;
	}
	int nItem = m_ListCtrl.GetNextSelectedItem( pos );
	CString strItem;
	strItem = m_ListCtrl.GetItemText( nItem, 0 );
	CString str;
	str.Format("��ȷʵҪɾ�� %s �б���(��¼)��", strItem );
	if ( IDOK != MessageBox(str, "ɾ��ȷ��", MB_ICONQUESTION | MB_OKCANCEL ))
		return;
	// ����ʹ�����������ɾ��
	_CommandPtr pCmd;
	pCmd.CreateInstance(__uuidof(Command));	// ��ʼ��Commandָ��
	pCmd->ActiveConnection = m_pConnection;	// ָ�����е�����
	CString strComm;
	strComm.Format("DELETE FROM student WHERE studentno='%s'", strItem);
	pCmd->CommandText = strComm.AllocSysString();
	pCmd->Execute(NULL, NULL, adCmdText );	// ִ������

/*	// ��ʹ��Recordset�����������������
	CString strSql;
	strSql.Format("SELECT * FROM student WHERE studentno='%s'", strItem);
	BSTR bstrSQL = strSql.AllocSysString();		// ��CStringת����BSTR
	m_pRecordset->Open( bstrSQL,(IDispatch*)m_pConnection, adOpenDynamic, adLockOptimistic, adCmdText); 
	m_pRecordset->Delete(adAffectCurrent);		// ɾ����ǰ��
	m_pRecordset->MoveFirst();					// ʹɾ����Ч
	m_pRecordset->Close();*/
	ResetListItem();
}
