#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include<time.h>

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void color(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void drawship(int x, int y)
{
	gotoxy(x, y);
	color(2, 4);
	printf("<-0->");
	color(7, 0);
}
void eraseship(int x, int y)
{
	gotoxy(x, y);
	color(0, 0);
	printf("     ");
}
void setcursor(bool vsb)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = vsb;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
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
int randrange(int x, int y)
{
	int random = rand() % (y - x + 1) + x;
	return random;
}
int intlen(int x)
{
	int count = 0;
	if (x == 0) return 1;
	else {
		while (x != 0) { count++; x = x / 10; }
		return count;
	}
}
void score(int s)
{
	gotoxy(80 - intlen(s), 0);
	printf("%d", s);
}
char cursor(int x, int y)
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];
}

int main()
{
	char ch = '.', drt = 's';
	int x = 37, y = 20;
	int xb[5], yb[5];
	int countb = 0, blt[5] = { 0,0,0,0,0 };
	int s = 0, sy[5];
	setcursor(0);
	drawship(x, y);
	srand(time(0));
	score(s);
	for (int i = 1;i <= 20;i++)
		{
			gotoxy(randrange(10, 70), randrange(2, 5));
			printf("*");
		}
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
				sy[countb] = yb[countb] - 1;
				countb++;
				countb %= 5;
			}
			fflush(stdin);
		}
		if (drt == 'l' && x >= 1) { eraseship(x, y); drawship(--x, y); }
		if (drt == 'r' && x <= 74) { eraseship(x, y); drawship(++x, y); }
		if (drt == 's') { eraseship(x, y); drawship(x, y); }
		for (int i = 0;i < 5; i++)
		{
			if (blt[i] == 1)
			{
				erasebullet(xb[i], yb[i]);
				if (yb[i] > 0) bullet(xb[i], --yb[i]);
				else blt[i] = 0;
				if (cursor(xb[i], --sy[i]) == '*') { s++; score(s); Beep(300, 100); }
			}
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}
