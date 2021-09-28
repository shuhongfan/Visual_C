// Ex_OpenGLView.cpp : implementation of the CEx_OpenGLView class
//

#include "stdafx.h"
#include "Ex_OpenGL.h"

#include "Ex_OpenGLDoc.h"
#include "Ex_OpenGLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEx_OpenGLView

IMPLEMENT_DYNCREATE(CEx_OpenGLView, CView)

BEGIN_MESSAGE_MAP(CEx_OpenGLView, CView)
	//{{AFX_MSG_MAP(CEx_OpenGLView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEx_OpenGLView construction/destruction

CEx_OpenGLView::CEx_OpenGLView()
{
	// TODO: add construction code here

}

CEx_OpenGLView::~CEx_OpenGLView()
{
}

BOOL CEx_OpenGLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= WS_CLIPSIBLINGS|WS_CLIPCHILDREN;
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEx_OpenGLView drawing

void CEx_OpenGLView::OnDraw(CDC* pDC)
{
	CEx_OpenGLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	HWND hWnd=GetSafeHwnd();			// ��õ�ǰ���ھ��
	HDC hDC=::GetDC(hWnd);				// ����봰�ھ����������豸����
	wglMakeCurrent(hDC,m_hGLRC);		// ���õ�ǰ����Ⱦ����
	DrawScene();						// ���Ƴ���
	wglMakeCurrent(NULL,NULL);			// ȡ����ǰ����Ⱦ����
	SwapBuffers(hDC);					// ��ͼ����ʾ�ڴ��ڵ��豸������
}

/////////////////////////////////////////////////////////////////////////////
// CEx_OpenGLView diagnostics

#ifdef _DEBUG
void CEx_OpenGLView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_OpenGLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_OpenGLDoc* CEx_OpenGLView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_OpenGLDoc)));
	return (CEx_OpenGLDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEx_OpenGLView message handlers

void CEx_OpenGLView::DrawScene()
{
	glClearColor(0.0,0.0,0.0,0.0);				// ������������Ҫ����ɫ
	glClear(GL_COLOR_BUFFER_BIT);		// ����
	glPushMatrix();						// �ѵ�ǰ��������ѹ������ջ
	glColor3f(1.0,0.0,1.0);					// ���û�ͼ��ɫ
	auxWireTeapot(0.4);					// ���Ʋ�����߿�ģ��
	glPopMatrix();							// �ָ���ǰ��������
	glFinish();							// ��ɻ���
}

int CEx_OpenGLView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),  	// �ýṹ�Ĵ�С
		1,                              		// �ýṹ�İ汾�ţ��������Ϊ1
		PFD_DRAW_TO_WINDOW |       		// ֧����Ļ��ͼ
		  PFD_SUPPORT_OPENGL |        	// ֧��OpenGL
		  PFD_DOUBLEBUFFER,          	// ֧��˫����
		PFD_TYPE_RGBA,                	// ������ɫģʽΪRGBA
		24,                             		// ��ɫ��λ��Ϊ24λ
		0, 0, 0, 0, 0, 0,               			// ���Ը���ɫ������RGBA��λ��
		0,                              		// ��RGBA��û��alpha�ɷ�
		0,                              		// ����alpha��ƫ����
		0,                              		// û���ۼӻ�����
		0, 0, 0, 0,                     		// �����ۼӻ������и���ɫ��λ��
		32,                             		// z�����������Ϊ32λ
		0,                              		// û��ģ�建����
		0,                              		// û�и���������
		PFD_MAIN_PLANE,             		// ��Ϊ��ƽ������
		0,                              		// ���������������0
		0, 0, 0                         		// ���Բ㡢��ɫ�ȵ�����
	};
	CClientDC dc(this);
	int pixelformat = ChoosePixelFormat(dc.GetSafeHdc(), &pfd);
	if (SetPixelFormat(dc.GetSafeHdc(), pixelformat, &pfd) == FALSE)
	{
		MessageBox("SetPixelFormat failed");
		return -1;
	}
	m_hGLRC = wglCreateContext(dc.GetSafeHdc());
	
	return 0;
}

void CEx_OpenGLView::OnDestroy() 
{
	
	// TODO: Add your message handler code here
	if 	(wglGetCurrentContext()!=NULL)
		wglMakeCurrent(NULL,NULL);
	if (m_hGLRC!=NULL)
	{
		wglDeleteContext(m_hGLRC);
		m_hGLRC=NULL;
	}
	
	CView::OnDestroy();
}

void CEx_OpenGLView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if(cy > 0)
	{
		CClientDC dc(this);
		wglMakeCurrent(dc.GetSafeHdc(),m_hGLRC);
		glViewport(0, 0, cx, cy);
		wglMakeCurrent(NULL,NULL);
	}
}
