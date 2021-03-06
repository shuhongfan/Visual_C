#include <windows.h>

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);		// 窗口过程

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine, int nCmdShow)
{
     HWND       	hwnd ;		// 窗口句柄
     MSG        	msg ;		// 消息
     WNDCLASS		wndclass ;	// 窗口类
     wndclass.style  			= CS_HREDRAW | CS_VREDRAW ;
     wndclass.lpfnWndProc   	= WndProc ;
     wndclass.cbClsExtra    	= 0 ;
     wndclass.cbWndExtra    	= 0 ;
     wndclass.hInstance     	= hInstance ;
     wndclass.hIcon         	= LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       	= LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground 	= GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  	= NULL;
     wndclass.lpszClassName 	= "HelloWin";		// 窗口类名
     if (!RegisterClass (&wndclass))				// 注册窗口
     {
          MessageBox (NULL, "窗口注册失败！", "HelloWin", 0) ;
          return 0 ;
     }
     // 创建窗口
     hwnd = CreateWindow ("HelloWin",                 	// 窗口类名
                          "我的窗口",					// 窗口标题
                          WS_OVERLAPPEDWINDOW,    		// 窗口样式
                          CW_USEDEFAULT,            	// 窗口最初的 x 位置
                          CW_USEDEFAULT,             	// 窗口最初的 y 位置
                          480,             				// 窗口最初的 x 大小,CW_USEDEFAULT
                          320,             				// 窗口最初的 y 大小
                          NULL,                       	// 父窗口句柄
                          NULL,							// 窗口菜单句柄
                          hInstance,                 	  // 应用程序实例句柄
                          NULL) ;                     // 创建窗口的参数
     ShowWindow (hwnd, nCmdShow) ;		// 显示窗口				
     UpdateWindow (hwnd) ;				// 更新窗口，包括窗口的客户区
     // 进入消息循环：当从应用程序消息队列中检取的消息是WM_QUIT时，则退出循环。
     while (GetMessage (&msg, NULL, 0, 0))  {
		  	TranslateMessage (&msg) ;			// 转换某些键盘消息
         	DispatchMessage (&msg) ;			// 将消息发送给窗口过程，这里是WndProc
     }
     return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC				hdc;
	PAINTSTRUCT		ps;
	RECT			rc;

    switch (message)
	{
		case	WM_CREATE:		// 窗口创建产生的消息
				return 0 ;          

		case	WM_PAINT:
				hdc		= BeginPaint( hwnd, &ps );
				GetClientRect( hwnd, &rc );		// 获取窗口客户区大小
				DrawText( hdc, TEXT("Hello Windows!"), -1, &rc, 
							DT_SINGLELINE | DT_CENTER |DT_VCENTER );
				EndPaint( hwnd, &ps );
		  		return 0 ;          

		case	WM_DESTROY:		// 当窗口关闭时产生的消息
				PostQuitMessage (0) ;
				return 0 ;
     }
     return DefWindowProc (hwnd, message, wParam, lParam) ; // 执行默认的消息处理
}
