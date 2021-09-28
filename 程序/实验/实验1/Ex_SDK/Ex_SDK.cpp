#include <windows.h>
#include <math.h>
#include <stdio.h>
// ��һԪ���η��̵ĸ����������ظ��ĸ���
int GetRoot(float a, float b, float c, double *root)
{
	double delta, deltasqrt;
	delta = b*b - 4.0 * a * c;
	if (delta<0.0) return 0;	// �޸�
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
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);		// ���ڹ���
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine, int nCmdShow)
{
     HWND       	hwnd ;	// ���ھ��
     MSG        	msg ;		// ��Ϣ
     WNDCLASS	wndclass ;	// ������
     wndclass.style  			= CS_HREDRAW | CS_VREDRAW ;	
     wndclass.lpfnWndProc   	= WndProc ;					
     wndclass.cbClsExtra    	= 0 ;
     wndclass.cbWndExtra    	= 0 ;
     wndclass.hInstance     	= hInstance ;
     wndclass.hIcon         	= LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       	= LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground 	= (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  	= NULL ;
     wndclass.lpszClassName 	= "SDKWin";		// ��������
     if (!RegisterClass (&wndclass))				// ע�ᴰ��
     {
          MessageBox (NULL, "����ע��ʧ�ܣ�", "HelloWin", 0) ;
          return 0 ;
     }
     // ��������
     hwnd = CreateWindow ("SDKWin",                 		// ��������
                          "ʵ��1����Windows��̻���",		// ���ڱ���
                          WS_OVERLAPPEDWINDOW,    	// ������ʽ
                          CW_USEDEFAULT,            	// ��������� x λ��
                          CW_USEDEFAULT,             	// ��������� y λ��
                          CW_USEDEFAULT,             	// ��������� x ��С
                          CW_USEDEFAULT,             	// ��������� y ��С
                          NULL,                       	// �����ھ��
                          NULL,                       	// ���ڲ˵����
                          hInstance,                  	// Ӧ�ó���ʵ�����
                          NULL) ;                     	// �������ڵĲ���
     ShowWindow (hwnd, nCmdShow) ;			// ��ʾ����				
     UpdateWindow (hwnd) ;					// ���´��ڣ��������ڵĿͻ���
     while (GetMessage (&msg, NULL, 0, 0))
     {
		  	TranslateMessage (&msg) ;		// ת��ĳЩ������Ϣ
         	DispatchMessage (&msg) ;		// ����Ϣ���͸����ڹ��̣�������WndProc
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
		 case WM_CREATE:	// ���ڴ�����������Ϣ
				hwndEdit = CreateWindow("edit", NULL, WS_CHILD|WS_VISIBLE|WS_BORDER,
								10, 60, 200, 25, hwnd, NULL, NULL, NULL );
				hwndButton = CreateWindow("button", "��  ��",
                                 WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
								240, 60, 80, 25, hwnd, NULL, NULL, NULL );
			  	return 0 ; 
		 case WM_COMMAND:	// ������Ϣ���ؼ�������֪ͨ������wParam�ĸ�����
				if (((HWND)lParam == hwndButton )&&( HIWORD(wParam) == BN_CLICKED ))	
// ���°�ť
				{
					// ��ȡ�༭��ؼ�������,������ת����float��ֵ
					GetWindowText( hwndEdit, strEdit, 80); 	// ��ȡ�༭������
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
						a[i] = (float)atof(strA[i]);	// ���ַ���ת����float��ֵ
					int n = GetRoot(a[0], a[1], a[2], root);
					if (n<1)	strcpy(str, "�����޸�!") ;
					else 	sprintf(str,"���̵Ľ�Ϊ��%f, %f", root[0], root[1]);
					InvalidateRect(hwnd, NULL, TRUE);
				}
		 case WM_PAINT:
			  	hdc = BeginPaint(hwnd, &ps);
				strcpy(strHint,  "������һԪ���η��̵�3��ϵ�����м��ö��ŷָ�"); 
				TextOut(hdc, 10, 40, strHint, strlen(strHint));
				TextOut(hdc, 10, 90, str, strlen(str));
				EndPaint(hwnd, &ps);
		  		return 0 ;          
		 case WM_DESTROY:	// �����ڹر�ʱ��������Ϣ
			  	PostQuitMessage (0) ;
			  	return 0 ;
     }
     return DefWindowProc (hwnd, message, wParam, lParam) ; // ִ��Ĭ�ϵ���Ϣ����
}
