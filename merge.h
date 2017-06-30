#include "functions.h"

class merge_sort {
	int *a;
public:
	merge_sort();
	void merge(int left, int mid, int right);
	void mergesort(int left, int right);
	void display();
	void graph(int);
};