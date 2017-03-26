#include<Windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PSTR iCmdLine, int iCmdShow) {
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND hwnd;
	MSG msg;
	/* обща базова информация за прозорците от този клас */
	WNDCLASS wndclass;
	wndclass.style = CS_HREDRAW | CS_VREDRAW; //казва че при всяка промяна на прозореца трябва да се прерисува content-а му хоризонтални и вертикално 
	wndclass.lpfnWndProc = WndProc; // !!! прозорците асоциирани с този клас
	// ще използват тази процедура за обработка на съобщения !!! казва че всички съобщения генерирани от този тип клас ще бъдат обработвани от тази процедура (указател към функция)
	wndclass.cbClsExtra = 0; // указва дали е нужно програмата да използва допълнителна памет за собствени цели
	wndclass.cbWndExtra = 0; // същото като горното
	wndclass.hInstance = hInstance; // уникалния идентификационен номер на ЦЯЛАТА ПРОГРАМА - не на отделния прозорец създаван от CreateWindow(...)
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //указва че клиентската част на процосеца background-a ще е бял
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName; //!!! името на класа което ще бъде използвано по късно за общото описание на прозорци от този тип - тоест така ще се знае текущия прозорец с кой клас да бъде
	// свързан когато се създава нов прозорец 
	if (!RegisterClass(&wndclass)) { // регистрира класа за да укаже че ще се ползва по нататък във CreateWindow и CreateWindowEx
		MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
		return 0;
	}
	/* конкретна информация за текущия прозорец */
	hwnd = CreateWindow(szAppName, // ето така се свързват класа със конкретния прозорец за да се вземат характеристиките със името 
		TEXT("The Hello Program"), // името на прозореца
		WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL, // родителски прозорец
		NULL, // handle за меню
		hInstance, // инстанция на програмата
		NULL); // указател към структури от данни  които ние искаме нашия прозорец да използва 

	/*прозорците са създадени но не са визуализирани на video display (екрана)*/
	ShowWindow(hwnd, iCmdShow); // визуализира прозореца с дадения handle и дисплей със iCmdShow
	UpdateWindow(hwnd); // казва че иска прозореца да бъде Painted като изпраща съобщение на WndProc
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	switch (message) {
	case WM_CREATE:
		PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_SYNC);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, TEXT("Hello, Windows 98!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
