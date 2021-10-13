#pragma once // trÃ¡nh Ä‘á»¥ng Ä‘á»™ thÆ° viá»‡n khi gá»i chá»“ng file lÃªn nhau
#include <stdio.h>
#include <conio.h>
#include<ctime> /* thÆ° viá»‡n há»— trá»£ vá» thá»i gian thá»±c */
#include "windows.h" // thÆ° viá»‡n nÃ y bÃ¡ Ä‘áº¡o láº¯m nhÃ© - chá»©a nhiá»u Ä‘á»“ chÆ¡i nek - cá»© tÃ¬m hiá»ƒu dáº§n dáº§n s
//======= láº¥y tá»a Ä‘á»™ x cá»§a con trá» hiá»‡n táº¡i =============
#define KEY_NONE	-1
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

//========= láº¥y tá»a Ä‘á»™ y cá»§a con trá» hiá»‡n táº¡i =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

//============== dá»‹ch con trá» hiá»‡n táº¡i Ä‘áº¿n Ä‘iá»ƒm cÃ³ tá»a Ä‘á»™ (x,y) ==========
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//============= Ä‘áº·t mÃ u cho chá»¯ =========
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

//============== lÃ m áº©n trá» chuá»™t ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

//======= tráº£ vá» mÃ£ phÃ­m ngÆ°á»i dÃ¹ng báº¥m =========
int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
