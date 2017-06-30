#include "stdafx.h"
#include "menu.h"

char *choices[] = {
	"Search",
	"Sort",
	"Queue",
	"Stack",
	"Linked List",
	"Exit"
};

char *search[] = {
	"Linear",
	"Binary",
	"Go Back"
};

char *sort[] = {
	"Bubble Sort",
	"Selection Sort",
	"Insertion Sort",
	"Quick Sort",
	"Merge Sort",
	"Go Back"

};

int n_choices = sizeof(choices) / sizeof(char *);
int n_search_choices = sizeof(search) / sizeof(char *);
int n_sort_choices = sizeof(sort) / sizeof(char *);

// Driving Function
void show_windows() {
	int choice;
	choice = show_menu(choices, n_choices, "DST Algorithms");
	switch (choice) {
	case 1:display_search_menu();
		break;
	case 2:display_sort_menu();
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:init_linkedlist();
		break;
	case 6:exit(0);
		break;
	}
}

void display_search_menu() {
	int choice;
	choice = show_menu(search, n_search_choices, "Search");
	switch (choice) {
	case 1:init_linear();
		break;
	case 3:show_windows();
		break;
	default:printw("Will not come to default ever!!!");
	}
}

void display_sort_menu() {
	int choice;
	choice = show_menu(sort, n_sort_choices, "Sort");
	switch (choice) {
	case 1:init_bubble();
		break;
	case 6:show_windows();
		break;
	default:printw("Will not come to default ever!!!");
	}
}