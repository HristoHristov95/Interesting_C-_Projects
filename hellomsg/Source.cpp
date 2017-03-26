#include<Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PSTR szCmdLine, int iCmdShow) {
	MessageBox(NULL, TEXT("Hello windows 98!"), TEXT("Hello,msg"), MB_OK);
	return 0;
}