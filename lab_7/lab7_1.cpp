#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y); printf(" <-0-> ");
}
void draw_bullet(int x, int y)
{
	gotoxy(x, y); printf("^");
}
void clear_bullet(int x, int y)
{
	gotoxy(x, y); printf(" ");
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
	gotoxy(80-intlen(s), 0);
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
	srand(time(0));
	char ch = '.';
	int x = 38, y = 20;
	int bx, by;
	int bullet = 0;
	int s = 0 , sy;
	score(s);
	draw_ship(x, y);
	for (int i = 1;i <= 20;i++)
	{
		gotoxy(randrange(10,70),randrange(2,5));
		printf("*");
	}
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { draw_ship(--x, y); }
			if (ch == 'd') { draw_ship(++x, y); }
			if (bullet != 1 && ch == ' ') { bullet = 1; bx = x + 3; by = y - 1; sy = by-1; }
			fflush(stdin);
		}
		if (bullet == 1) {

			clear_bullet(bx, by);
			if (by == 0) { bullet = 0; }
			else draw_bullet(bx, --by);
			if (cursor(bx, --sy) == '*') { s++; score(s); Beep(300, 100); }
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}
