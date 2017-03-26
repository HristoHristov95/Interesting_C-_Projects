#include<Windows.h>
#include<tchar.h>
#include<stdio.h>
int CDECL MessageBoxPrint(PTCHAR szCaption, PTCHAR szFormat, ...) {
	TCHAR arr[1024];
	va_list args;
	va_start(args, szFormat);
	_vsntprintf(arr, sizeof(arr) / sizeof(TCHAR), szFormat, args);
	va_end(args);
	return MessageBox(NULL, arr, szCaption, 0);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PSTR szCmdLine, int iCmdShow) {
	int cxScreen, cyScreen;
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);
	MessageBoxPrint(TEXT("ScrnSize"), TEXT("The screen is %i pixels wide by %i pixels high."), cxScreen, cyScreen);
	return 0;
}