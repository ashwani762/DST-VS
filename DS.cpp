// DS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "functions.h"
#include "menu.h"
#include <Windows.h>

int main()
{
	/*
	|-------------------------------------------------------------------|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|							DST Algorithm							|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|																	|
	|-------------------------------------------------------------------|
	*/

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1000, 641, true);

	
	initscr();
	refresh();
	char * TITLE = "DST ALGORITHMS";
	start_color();

	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	print_in_middle(stdscr, LINES / 2, 0, 0, TITLE);
	getch();

	show_windows();

	refresh();

	endwin();
    return 0;
}

