#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define WIDTH 30
#define HEIGHT 10

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *title);
void print_menu(WINDOW *menu_win, int highlight, char *choice[], int choices);
int show_menu(char *menu[], int no_of_choices, char *string);
void instruction();
void init(char *string);
void showfile(char *source, char *string,int n);
void call(char *string, char *theory_string, char *source_string, void(*execute)(), void(*menu)());
void swap(int &, int &);

#endif