// StatScoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ex_Student.h"
#include "StatScoreDlg.h"

#include "CourseSet.h"
#include "ScoreSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatScoreDlg dialog


CStatScoreDlg::CStatScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStatScoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStatScoreDlg)
	m_strCourseNO = _T("");
	m_strCourseName = _T("");
	m_strCredit = _T("");
	m_strOpen = _T("");
	//}}AFX_DATA_INIT
	m_nNum = 0;
}


void CStatScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStatScoreDlg)
	DDX_Control(pDX, IDC_COMBO_COURSENO, m_comboCourseNO);
	DDX_CBString(pDX, IDC_COMBO_COURSENO, m_strCourseNO);
	DDX_Text(pDX, IDC_STATIC_COURSE, m_strCourseName);
	DDX_Text(pDX, IDC_STATIC_CREDIT2, m_strCredit);
	DDX_Text(pDX, IDC_STATIC_OPEN, m_strOpen);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStatScoreDlg, CDialog)
	//{{AFX_MSG_MAP(CStatScoreDlg)
	ON_BN_CLICKED(IDC_BUTTON_DISP, OnButtonDisp)
	ON_CBN_SELCHANGE(IDC_COMBO_COURSENO, OnSelchangeComboCourseno)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatScoreDlg message handlers

void CStatScoreDlg::OnButtonDisp() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	ResetScoreData();
/*	int nScore[] = {66,82,79,74,86,82,67,60,45,44,77,98,65,90,66,76,66,
		62,83,84,97,43,67,57,60,60,71,74,60,72,81,69,79,91,69,71,81};// ԭʼ�ɼ�
	m_nNum = 0;
	for (int i=0; i<sizeof(nScore)/sizeof(int); i++)
	{
		m_nScore[m_nNum] = nScore[i];
		m_nNum ++;
	}*/

	Invalidate();
}

void CStatScoreDlg::OnSelchangeComboCourseno() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int nIndex = m_comboCourseNO.GetCurSel();
	if (nIndex == CB_ERR) return;
	m_comboCourseNO.GetLBText( nIndex, m_strCourseNO);
	CCourseSet cSet;
	cSet.m_strFilter.Format("courseno='%s'", m_strCourseNO);
	cSet.Open();
	if (!cSet.IsEOF())
	{
		m_strCourseName = cSet.m_coursename;
		m_strCredit.Format("%4.1f", cSet.m_credit);
		m_strOpen.Format("%d", cSet.m_openterm);
		UpdateData(FALSE);
	}
	if (cSet.IsOpen()) cSet.Close();
	ResetScoreData();
}

BOOL CStatScoreDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// ��ʼ���γ̺�
	CCourseSet cSet;
	cSet.Open();
	while (!cSet.IsEOF())
	{
		m_comboCourseNO.AddString(cSet.m_courseno);	
		cSet.MoveNext();
	}
	if (cSet.IsOpen()) cSet.Close();
	m_comboCourseNO.SetCurSel(0);	
	OnSelchangeComboCourseno();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CStatScoreDlg::DrawScore()
{
	if (m_nNum == 0)
	{
		MessageBox("û�иÿγ̵ĳɼ���¼��");
		return;
	}
	CWnd* pWnd = GetDlgItem(IDC_DRAW);	// ���IDC_DRAW�ؼ�����ָ��
	CDC* pDC = pWnd->GetDC();			// ��ô��ڵ�ǰ���豸����ָ��
	CFont *font = pWnd->GetFont();
	CFont *oldFont = pDC->SelectObject( font );

	int nScoreNum[] = { 0, 0, 0, 0, 0};			// ���ɼ��ε������ĳ�ʼֵ
	// ����������ͳ�Ƹ������ε�����
	for (int i=0; i<m_nNum; i++)
	{
		int nSeg = m_nScore[i] / 10;			// ȡ����"ʮ"λ�ϵ�ֵ
		if (nSeg < 6)	nSeg = 5;			// <60��
		if (nSeg == 10 ) nSeg = 9;			// ��Ϊ100�֣���Ϊ>90������
		nScoreNum[nSeg - 5] ++;				// �������μ���
	}
	int nSegNum = sizeof(nScoreNum)/sizeof(int);	// �����ж��ٸ�������

	// �����������������
	int nNumMax = nScoreNum[0];					
	for (i=1; i<nSegNum; i++)
	{
		if (nNumMax < nScoreNum[i]) nNumMax = nScoreNum[i];
	}
	
	CRect rc;
	pWnd->GetClientRect(rc);
	pDC->Rectangle( rc );
	rc.DeflateRect( 40, 40 );				// ��С���δ�С

	int nSegWidth = rc.Width()/nSegNum;		// ����ÿ�εĿ��
	int nSegHeight = rc.Height()/nNumMax;	// ����ÿ�εĵ�λ�߶�

	COLORREF crSeg = RGB(0,0,192);			// ����һ����ɫ����

	CBrush brush1( HS_FDIAGONAL, crSeg );
	CBrush brush2( HS_BDIAGONAL, crSeg );
	CPen   pen( PS_INSIDEFRAME, 2, crSeg );

	CBrush* oldBrush = pDC->SelectObject( &brush1 );	// ��brush1ѡ���豸����
	CPen* oldPen = pDC->SelectObject( &pen );			// ��penѡ���豸����

	CRect rcSeg(rc);
	rcSeg.right = rcSeg.left + nSegWidth;		// ʹÿ�εľ��ο�ȵ���nSegWidth
	CString strSeg[]={"<60","60-70","70-80","80-90",">=90"};
	CRect rcStr;
	for (i=0; i<nSegNum; i++)
	{
		// ��֤���ڵľ��������ʽ����ͬ
		if (i%2) 
			pDC->SelectObject( &brush2 );	
		else
			pDC->SelectObject( &brush1 );	

		rcSeg.top = rcSeg.bottom - nScoreNum[i]*nSegHeight - 2;	// ����ÿ�ξ��εĸ߶�
		pDC->Rectangle(rcSeg);

		if (nScoreNum[i] > 0)
		{
			CString str;
			str.Format("%d��", nScoreNum[i]);
			pDC->DrawText( str, rcSeg, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		}
		rcStr = rcSeg;
		rcStr.top = rcStr.bottom + 2;
		rcStr.bottom += 20;
		pDC->DrawText( strSeg[i], rcStr, DT_CENTER | DT_VCENTER | DT_SINGLELINE );

		rcSeg.OffsetRect( nSegWidth, 0 );		// ���ƾ���
	}

	pDC->SelectObject( oldBrush );			// �ָ�ԭ���Ļ�ˢ����
	pDC->SelectObject( oldPen );			// �ָ�ԭ���Ļ�������
	pDC->SelectObject( oldFont );

}

void CStatScoreDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CWnd* pWnd = GetDlgItem(IDC_DRAW);
	pWnd->UpdateWindow();
	DrawScore();

	// Do not call CDialog::OnPaint() for painting messages
}

void CStatScoreDlg::ResetScoreData()
{
	CScoreSet sSet;
	sSet.m_strFilter.Format("studentno LIKE '%s%%' AND course='%s'",
		m_strClass.Left(6), m_strCourseNO);
	sSet.Open();
	m_nNum = 0;
	while (!sSet.IsEOF())
	{
		m_nScore[m_nNum] = (int)(sSet.m_score+0.5);
		m_nNum++;
		sSet.MoveNext();
	}
	if (sSet.IsOpen()) sSet.Close();
}
