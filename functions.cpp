#include "stdafx.h"
#include "functions.h"

int startx = 0;
int starty = 0;
char *ins = "z -> Theory, x -> Code, c -> Execute, q -> Back";

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *title) {
	int x, y;
	float temp;

	if (win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if (startx != 0)
		x = startx;
	if (starty != 0)
		y = starty;
	if (width == 0)
		width = 120;

	temp = (width - strlen(title)) / 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", title);
}

void print_menu(WINDOW *menu_win, int highlight, char *choice[], int choices) {
	int x = 2, y = 2;
	box(menu_win, 0, 0);
	for (int i = 0; i < choices; ++i) {
		if (highlight == i + 1) {
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choice[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else {
			mvwprintw(menu_win, y, x, "%s", choice[i]);
		}
		y++;
	}
	wrefresh(menu_win);
}

int show_menu(char *menu[], int no_of_choices, char *string) {
	clear();
	init(string);
	WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;

	noecho();
	cbreak();

	startx = (120 - WIDTH) / 2;
	starty = (30 - HEIGHT) / 2;

	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);

	refresh();

	print_menu(menu_win, highlight, menu, no_of_choices);
	while (1)
	{
		c = wgetch(menu_win);
		switch (c)
		{
		case KEY_UP:
			if (highlight == 1)
				highlight = no_of_choices;
			else
				--highlight;
			break;
		case KEY_DOWN:
			if (highlight == no_of_choices)
				highlight = 1;
			else
				++highlight;
			break;
		case 10:
			choice = highlight;
			break;
		case 'o':
			system("start visualization/Algorithms.html");
			break;
		default:
			//mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
			refresh();
			break;
		}
		print_menu(menu_win, highlight, menu, no_of_choices);
		if (choice != 0)	/* User did a choice come out of the infinite loop */
			break;
	}
	clrtoeol();
	refresh();
	delwin(menu_win);
	return choice;
}

void instruction() {
	WINDOW *win;
	int height, width, start_x, start_y;
	getmaxyx(stdscr, height, width);
	win = newwin(3, width, 34, 0);
	refresh();
	box(win, 0, 0);
	mvwprintw(win, 1, 60 - (strlen(ins) / 2), "%s", ins);
	wrefresh(win);
}

void init(char *string) {
	move(0, 60 - (strlen(string) / 2));
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	attron(COLOR_PAIR(1));
	printw("%s", string);
	attroff(COLOR_PAIR(1));

	move(1, 0);
}

void showfile(char *source, char *string,int n) {
	clear();
	instruction();
	init(string);
	/////////////////////////////////////////////////////////////////
	FILE *file;
	int ch;

	file = fopen(source, "r");
	if (file == NULL)
	{
		perror("Cannot open file");
		exit(1);
	}
	if (n == 1) {
		attron(COLOR_PAIR(1));
		printw("THEORY\n\n");
		attroff(COLOR_PAIR(1));
	}
	else if (n == 2) {
		attron(COLOR_PAIR(1));
		printw("ALGORITHM\n\n");
		attroff(COLOR_PAIR(1));
	}
	while ((ch = fgetc(file)) != EOF) {
		printw("%c", ch);
	}
	fclose(file);
	//////////////////////////////////////////////////////////////////
}

void call(char *string, char *theory_string, char *source_string, void(*execute)(), void(*menu)()) {
	clear();
	init(string);
	instruction();
	int ch;
	do {
		ch = getch();
		switch (ch) {
		case 'z':
			showfile(theory_string, string,1);
			break;
		case 'x':
			showfile(source_string, string,2);
			break;
		case 'c':
			clear();
			init(string);
			init_pair(2, COLOR_WHITE, COLOR_RED);
			attron(COLOR_PAIR(2));
			printw("EXECUTING...\n\n");
			attroff(COLOR_PAIR(2));
			echo();
			
			(*execute)();
			instruction();
			break;
		case 'q':(*menu)();
		}

	} while (ch != 'q');

}

void swap(int &a, int &b) {
	a ^= b ^= a ^= b;
}