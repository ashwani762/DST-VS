#include "functions.h"

struct node
{
	int data;
	node *next;
};

void init_linkedlist();
void execute_linked();
void display(int);
extern void show_windows();

void create();
void display(int);
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();