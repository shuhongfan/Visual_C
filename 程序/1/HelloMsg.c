#include <windows.h>
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int nCmdShow)
{
     MessageBox (NULL,  TEXT("Hello, World!"),  TEXT("Hello"),  
		 MB_ICONQUESTION | MB_ABORTRETRYIGNORE) ;
     return 0 ;
}
