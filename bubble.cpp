#include "stdafx.h"
#include "bubble.h"

char *source_bubble = "algo/linear.txt";
char *theory_bubble = "theory/linear.txt";
char *string_bubble = "Bubble Sort";

void graph(int n) {
	int i;
	printw("%d", n);
	for (i = 0; i<n; i++)
	{
		printw("--");
	}
	printw("|\n");
}

void init_bubble() {
	call(string_bubble, theory_bubble, source_bubble, execute_bubble, display_sort_menu);
}

void execute_bubble() {
	int a[10] = { 13,6,3,10,7,4,2,5,8,17 }, i, j, k;

	for (i = 0; i<10; i++)
	{
		graph(a[i]);

	}
	refresh();
	clear();
	init(string_bubble);
	_sleep(500);

	for (i = 0; i<10 - 1; i++)
	{
		for (j = 0; j<10 - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				swap(a[j], a[j + 1]);
				//a[j] ^= a[j + 1] ^= a[j] ^= a[j + 1];
			}
			printw("Pass %d\n\n", i + 1);
			for (k = 0; k<10; k++)
			{
				graph(a[k]);

			}
			refresh();
			clear();
			init(string_bubble);
			_sleep(500);
		}
	}
	printw("After Sorting\n");
	for (i = 0; i<10; i++)
	{
		graph(a[i]);
		refresh();

	}
	
	//clear();
	init(string_bubble);
	_sleep(500);
	instruction();
}