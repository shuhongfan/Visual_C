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
	HWND hWnd=GetSafeHwnd();			// 获得当前窗口句柄
	HDC hDC=::GetDC(hWnd);				// 获得与窗口句柄相关联的设备环境
	wglMakeCurrent(hDC,m_hGLRC);		// 设置当前的渲染环境
	DrawScene();						// 绘制场景
	wglMakeCurrent(NULL,NULL);			// 取消当前的渲染环境
	SwapBuffers(hDC);					// 将图形显示在窗口的设备环境中
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
	glClearColor(0.0,0.0,0.0,0.0);				// 设置清屏所需要的颜色
	glClear(GL_COLOR_BUFFER_BIT);		// 清屏
	glPushMatrix();						// 把当前操作矩阵压入矩阵堆栈
	glColor3f(1.0,0.0,1.0);					// 设置绘图颜色
	auxWireTeapot(0.4);					// 绘制茶壶的线框模型
	glPopMatrix();							// 恢复当前操作矩阵
	glFinish();							// 完成绘制
}

int CEx_OpenGLView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),  	// 该结构的大小
		1,                              		// 该结构的版本号，这里必须为1
		PFD_DRAW_TO_WINDOW |       		// 支持屏幕绘图
		  PFD_SUPPORT_OPENGL |        	// 支持OpenGL
		  PFD_DOUBLEBUFFER,          	// 支持双缓冲
		PFD_TYPE_RGBA,                	// 像素颜色模式为RGBA
		24,                             		// 颜色的位数为24位
		0, 0, 0, 0, 0, 0,               			// 忽略各颜色分量在RGBA的位数
		0,                              		// 在RGBA中没有alpha成分
		0,                              		// 忽略alpha的偏移量
		0,                              		// 没有累加缓冲区
		0, 0, 0, 0,                     		// 忽略累加缓冲区中各颜色的位数
		32,                             		// z缓冲区的深度为32位
		0,                              		// 没有模板缓冲区
		0,                              		// 没有辅助缓冲区
		PFD_MAIN_PLANE,             		// 设为主平面类型
		0,                              		// 保留，这里必须是0
		0, 0, 0                         		// 忽略层、颜色等的屏蔽
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
