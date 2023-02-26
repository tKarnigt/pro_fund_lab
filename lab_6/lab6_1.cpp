#include <stdio.h>
#include <windows.h>
#include <conio.h>

void drawship(int, int);
void gotoxy(int, int);
void eraseship(int, int);
void cursor(bool);
void color(int, int);
void bullet(int, int);
void erasebullet(int, int);

int main()
{
	char ch = ' ', drt = 's';
	int x = 40, y = 20;
	int xb[5], yb[5];
	int countb = 0, blt[5] = { 0,0,0,0,0 };
	cursor(0);
	drawship(x, y);
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a') drt = 'l';
			if (ch == 'd') drt = 'r';
			if (ch == 's') drt = 's';
			if (ch == ' ' && blt[countb] == 0)
			{
				drt = 's';
				blt[countb] = 1;
				xb[countb] = x + 2;
				yb[countb] = y - 1;
				countb++;
				countb %= 5;
			}
			fflush(stdin);
		}
		if (drt == 'l' && x >= 2) { eraseship(x, y); drawship(--x, y); }
		if (drt == 'r' && x <= 80) { eraseship(x, y); drawship(++x, y); }
		if (drt == 's') { eraseship(x, y); drawship(x, y); }
		for (int i = 0;i < 5; i++)
		{
			if (blt[i] == 1)
			{
				erasebullet(xb[i], yb[i]);
				if (yb[i] > 0) bullet(xb[i], --yb[i]);
				else blt[i] = 0;
			}
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}

void drawship(int x, int y)
{
	gotoxy(x, y);
	color(2, 4);
	printf("<-0->");
	color(7, 0);
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void eraseship(int x, int y)
{
	gotoxy(x, y);
	color(0, 0);
	printf("     ");
}

void cursor(bool vsb)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = vsb;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void color(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void bullet(int x, int y)
{
	gotoxy(x, y);
	printf("^");
}

void erasebullet(int x, int y)
{
	gotoxy(x, y);
	printf(" ");
}
