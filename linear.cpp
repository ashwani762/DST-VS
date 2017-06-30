#include "stdafx.h"
#include "linear.h"

char *source_linear = "algo/linear.txt";
char *theory_linear = "theory/linear.txt";
char *string_linear = "Linear Search";

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
linear::linear(int n) {
	size = n;
	a = new int[size];
}

linear::~linear() {
	delete[] a;
	size = 0;
}

void linear::get() {
	int n;
	printw("Enter the size of array: ");
	scanw("%d", &n);
	size = n;
	a = new int[n];
	printw("Enter the elements of the array:\n");
	for (int i = 0; i<size; ++i) {
		printw("a[%d]: ", i);
		scanw("%d", &a[i]);
		echo();
	}

	printw("Enter the elemnt to search for: ");
	scanw("%d", &item);
	echo();
}

void linear::display() {
	int flag = 0;

	int space = 0;

	clear();
	init(string_linear);

	printw("Array is:\n");

	printw("\n");
	for (int i = 0; i<size; i++) {
		
		
		for (int i = 0; i < size; i++) {
			printw("%d ", a[i]);
		}printw("\n");
		
		if (a[i] == item ) {
			for (int i = 0; i < space; i++) {
				printw(" ");
			}
			printw("^\n");
					
			printw("Element found at location %d\n", i + 1);
			flag = 1;
			break;
		}
		else {
			for (int i = 0; i < space; i++) {
				printw(" ");
			}
			printw("^\n");
			space += 2;
		}
	}

	if (flag == 0) {
		printw("Element Not found");
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void init_linear() {
	call(string_linear, theory_linear, source_linear, execute, display_search_menu);
}


void execute() {
	linear l;
	l.get();
	l.display();
}