// Ex_StudentDoc.cpp : implementation of the CEx_StudentDoc class
//

#include "stdafx.h"
#include "Ex_Student.h"

#include "Ex_StudentDoc.h"

#include "StuInfoDlg.h"
#include "StudentSet.h"

#include "CourseDlg.h"
#include "CourseSet.h"

#include "ScoreDlg.h"
#include "ScoreSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc

IMPLEMENT_DYNCREATE(CEx_StudentDoc, CDocument)

BEGIN_MESSAGE_MAP(CEx_StudentDoc, CDocument)
	//{{AFX_MSG_MAP(CEx_StudentDoc)
	ON_COMMAND(ID_OP_ADD, OnOpAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc construction/destruction

CEx_StudentDoc::CEx_StudentDoc()
{
	// TODO: add one-time construction code here
	m_nInfoType = 0;
	m_nViewPos = 0;

}

CEx_StudentDoc::~CEx_StudentDoc()
{
}

BOOL CEx_StudentDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc serialization

void CEx_StudentDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc diagnostics

#ifdef _DEBUG
void CEx_StudentDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEx_StudentDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_StudentDoc commands

void CEx_StudentDoc::OnOpAdd() 
{
	// TODO: Add your command handler code here
	if (m_nInfoType == 1)
		AddStudentInfo();
	else if (m_nInfoType == 2)
		AddCourseInfo();
	else if (m_nInfoType == 3)
		AddScoreInfo();
}

void CEx_StudentDoc::AddStudentInfo()
{
	CStuInfoDlg dlg;
	if (dlg.DoModal() != IDOK) return;
	// ��student������µļ�¼��Ϊ�˷�ֹ��ͬ�ļ�¼��ӣ����������ж�
	CStudentSet infoSet;
	infoSet.m_strFilter.Format("studentname='%s' AND studentno='%s'",
		dlg.m_strName, dlg.m_strNO);
	infoSet.Open();
	if (!infoSet.IsEOF()) {
		AfxMessageBox(dlg.m_strName + " ѧ����¼����ӹ���");
		if (infoSet.IsOpen())
			infoSet.Close();
		return;
	}
	if (infoSet.IsOpen()) infoSet.Close();

	CStudentSet addSet;
	if (addSet.Open())	{
		// ���һ���¼�¼
		addSet.AddNew();
		addSet.m_studentname	= dlg.m_strName;
		addSet.m_studentno		= dlg.m_strNO;
		addSet.m_xb				= dlg.m_bSex;
		addSet.m_birthday		= dlg.m_tBirth;
		addSet.m_special		= dlg.m_strSpecial;
		//addSet.m_totalcredit	= 0.0;

		addSet.Update();
		addSet.Requery();
	}
	if (addSet.IsOpen())addSet.Close();

	// �����︴����Ƭ�ļ�
	CString strFileTO;
	strFileTO.Format("c://%s.bmp", dlg.m_strNO);
	if (!dlg.m_strPhotoFilePath.IsEmpty())
		DoCopyFile(strFileTO, dlg.m_strPhotoFilePath);

	AfxMessageBox("�Եȼ����Ӻ󣬵���[ȷ��]��ť��",MB_OK|MB_ICONINFORMATION); 

	// ����ͼ���͸�����Ϣ
	// 1,2,3 ��ʾѧ����Ϣ��ӡ��޸ġ�ɾ��
	this->UpdateAllViews( NULL, 1, (CObject *)new CString(dlg.m_strNO) );
}

void CEx_StudentDoc::AddScoreInfo()
{
	CScoreDlg dlg;
	if (m_strCourseNO.IsEmpty())
		dlg.m_strCourseNO = m_strCourseNO;
	if (dlg.DoModal()!= IDOK) return;
	m_strCourseNO = dlg.m_strCourseNO;
	CScoreSet sSet;
	sSet.Open();

	sSet.AddNew();
	sSet.m_course		= dlg.m_strCourseNO;
	sSet.m_studentno	= dlg.m_strStudentNO;
	sSet.m_score		= dlg.m_fScore;
	sSet.m_credit		= dlg.m_fCredit;
	sSet.Update();
	sSet.Requery();

	sSet.Close();

	AfxMessageBox("�Եȼ����Ӻ󣬵���[ȷ��]��ť��",MB_OK|MB_ICONINFORMATION); 

	// ����ͼ���͸�����Ϣ
	// 1,2,3 ��ʾѧ����Ϣ��ӡ�ɾ�����޸�
	this->UpdateAllViews( NULL, 1, (CObject *)new CString(dlg.m_strStudentNO) );
}

void CEx_StudentDoc::AddCourseInfo()
{
	CCourseDlg dlg;
	if (dlg.DoModal()!= IDOK) return;
	// ���жϿγ���Ϣ�Ƿ���ӹ���Ȼ�������
	CCourseSet cSet;
	cSet.m_strFilter.Format("courseno='%s'",dlg.m_strNO);
	cSet.Open();
	if (!cSet.IsEOF()) {
		AfxMessageBox(dlg.m_strNO + " �γ�����ӹ���");
		if (cSet.IsOpen())
			cSet.Close();
		return;
	}
	if (cSet.IsOpen()) cSet.Close();

	CCourseSet addSet;
	if (addSet.Open())	{
		// ���һ���¼�¼
		addSet.AddNew();
		addSet.m_courseno		= dlg.m_strNO;
		addSet.m_coursename		= dlg.m_strName;
		addSet.m_coursetype		= dlg.m_strType;
		addSet.m_openterm		= dlg.m_nOpen;
		addSet.m_hours			= BYTE(dlg.m_nHours);
		addSet.m_credit			= dlg.m_fCredit;
		addSet.m_special		= dlg.m_strSpecial;

		addSet.Update();
		addSet.Requery();
	}
	if (addSet.IsOpen())addSet.Close();

	// �����б���ͼ
	AfxMessageBox("�Եȼ����Ӻ󣬵���[ȷ��]��ť��",MB_OK|MB_ICONINFORMATION); 
	// 1,2,3 ��ʾ�γ���Ϣ��ӡ�ɾ�����޸�
	this->UpdateAllViews( NULL, 1, (CObject *)new CString(dlg.m_strNO) );

}

void CEx_StudentDoc::DoCopyFile(CString strFileTo, CString strFileFrom)
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
