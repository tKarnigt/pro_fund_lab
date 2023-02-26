#include <stdio.h>
#include <windows.h>
#include <conio.h>

void drawship(int, int);
void gotoxy(int, int);
void eraseship(int, int);

int main()
{
	char ch = ' ';
	int x = 40, y = 20;
	drawship(x, y);
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a' && x>=1) drawship(--x, y);
			if (ch == 'd' && x<=80) drawship(++x, y);
			if (ch == 'w') { eraseship(x, y); drawship(x, --y); }
			if (ch == 's') { eraseship(x, y); drawship(x, ++y); }
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}

void drawship(int x, int y)
{
	gotoxy(x, y);
	printf(" <-0-> ");
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void eraseship(int x, int y)
{
	gotoxy(x, y);
	printf("      ");
}
