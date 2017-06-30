#include "functions.h"

void init_linear();
void execute();
extern void display_search_menu();

class linear {
	int *a, size, item;
public:
	linear() { a = 0; }
	linear(int n);
	~linear();
	void get();
	void display();
};

