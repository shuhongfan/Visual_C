#include <windows.h>
#include <math.h>
#include <stdio.h>
// 求一元二次方程的根，函数返回根的个数
int GetRoot(float a, float b, float c, double *root)
{
	double delta, deltasqrt;
	delta = b*b - 4.0 * a * c;
	if (delta<0.0) return 0;	// 无根
	deltasqrt = sqrt(delta);
	if (a!=0.0) 	{
		root[0] = (-b + deltasqrt)/(2.0 * a);
		root[1] = (-b - deltasqrt)/(2.0 * a);
	} else
		if (b!=0.0) 	root[0] = root[1] = -c/b;
		else	return 0;
	if (root[0] == root[1]) return 1;
	else return 2;
}
char str[80];
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);		// 窗口过程
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine, int nCmdShow)
{
     HWND       	hwnd ;	// 窗口句柄
     MSG        	msg ;		// 消息
     WNDCLASS	wndclass ;	// 窗口类
     wndclass.style  			= CS_HREDRAW | CS_VREDRAW ;	
     wndclass.lpfnWndProc   	= WndProc ;					
     wndclass.cbClsExtra    	= 0 ;
     wndclass.cbWndExtra    	= 0 ;
     wndclass.hInstance     	= hInstance ;
     wndclass.hIcon         	= LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       	= LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground 	= (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  	= NULL ;
     wndclass.lpszClassName 	= "SDKWin";		// 窗口类名
     if (!RegisterClass (&wndclass))				// 注册窗口
     {
          MessageBox (NULL, "窗口注册失败！", "HelloWin", 0) ;
          return 0 ;
     }
     // 创建窗口
     hwnd = CreateWindow ("SDKWin",                 		// 窗口类名
                          "实验1——Windows编程基础",		// 窗口标题
                          WS_OVERLAPPEDWINDOW,    	// 窗口样式
                          CW_USEDEFAULT,            	// 窗口最初的 x 位置
                          CW_USEDEFAULT,             	// 窗口最初的 y 位置
                          CW_USEDEFAULT,             	// 窗口最初的 x 大小
                          CW_USEDEFAULT,             	// 窗口最初的 y 大小
                          NULL,                       	// 父窗口句柄
                          NULL,                       	// 窗口菜单句柄
                          hInstance,                  	// 应用程序实例句柄
                          NULL) ;                     	// 创建窗口的参数
     ShowWindow (hwnd, nCmdShow) ;			// 显示窗口				
     UpdateWindow (hwnd) ;					// 更新窗口，包括窗口的客户区
     while (GetMessage (&msg, NULL, 0, 0))
     {
		  	TranslateMessage (&msg) ;		// 转换某些键盘消息
         	DispatchMessage (&msg) ;		// 将消息发送给窗口过程，这里是WndProc
     }
     return msg.wParam ;
}
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	 HDC			hdc;
	 PAINTSTRUCT	ps;
	 static	HWND	hwndButton, hwndEdit;
	 char				strEdit[80], strA[3][80], strHint[80];
	 float				a[3];
	 double			root[2];
	 int				i, j, k, m;
     switch (message)
     {
		 case WM_CREATE:	// 窗口创建产生的消息
				hwndEdit = CreateWindow("edit", NULL, WS_CHILD|WS_VISIBLE|WS_BORDER,
								10, 60, 200, 25, hwnd, NULL, NULL, NULL );
				hwndButton = CreateWindow("button", "计  算",
                                 WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
								240, 60, 80, 25, hwnd, NULL, NULL, NULL );
			  	return 0 ; 
		 case WM_COMMAND:	// 命令消息，控件产生的通知代码在wParam的高字中
				if (((HWND)lParam == hwndButton )&&( HIWORD(wParam) == BN_CLICKED ))	
// 按下按钮
				{
					// 获取编辑框控件的内容,并将其转换成float数值
					GetWindowText( hwndEdit, strEdit, 80); 	// 获取编辑框内容
					k = 0;	m = 0;
					for (j=0; j<80; j++)
					{
						if (strEdit[j] == ','){
							k++; m = 0;
						}
						else {
							strA[k][m] = strEdit[j];
							m++;
						}
					}
					for (i=0; i<3; i++)
						a[i] = (float)atof(strA[i]);	// 将字符串转换成float数值
					int n = GetRoot(a[0], a[1], a[2], root);
					if (n<1)	strcpy(str, "方程无根!") ;
					else 	sprintf(str,"方程的解为：%f, %f", root[0], root[1]);
					InvalidateRect(hwnd, NULL, TRUE);
				}
		 case WM_PAINT:
			  	hdc = BeginPaint(hwnd, &ps);
				strcpy(strHint,  "请输入一元二次方程的3个系数，中间用逗号分隔"); 
				TextOut(hdc, 10, 40, strHint, strlen(strHint));
				TextOut(hdc, 10, 90, str, strlen(str));
				EndPaint(hwnd, &ps);
		  		return 0 ;          
		 case WM_DESTROY:	// 当窗口关闭时产生的消息
			  	PostQuitMessage (0) ;
			  	return 0 ;
     }
     return DefWindowProc (hwnd, message, wParam, lParam) ; // 执行默认的消息处理
}
