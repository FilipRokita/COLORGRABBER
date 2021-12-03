//COLORGRABBER
//Filip Rokita
//www.filiprokita.com

#include <iostream>
#include <Windows.h>

using namespace std;

char key;

void menu()
{
	cout << "KEY: "; cin >> key;
	cout << endl;
}

void colorgrabber()
{
	while (true)
	{
		if (GetAsyncKeyState(key))
		{
			HDC hdc = GetDC(NULL);
			POINT p;
			GetCursorPos(&p);
			COLORREF color = GetPixel(hdc, p.x, p.y);
			ReleaseDC(NULL, hdc);
			cout << "RED: " << (int)GetRValue(color) << " ; " << "GREEN: " << (int)GetGValue(color) << " ; " << "BLUE: " << (int)GetBValue(color) << endl;
			Sleep(1000);
		}
	}
}

int main()
{
	system("title COLORGRABBER - www.filiprokita.com");
	menu();
	colorgrabber();
	return 0;
}