#include "stdafx.h"
#include "linkedlist.h"

char *source_linked = "algo/linear.txt";
char *theory_linked = "theory/linear.txt";
char *string_linked = "Linked list";

int cnt = 0;
node *start = NULL;

void init_linkedlist() {
	call(string_linked, theory_linked, source_linked, execute_linked,show_windows);
}

void execute_linked()
{
	int choice;
	while (1) {
		printw("\n***SINGLE LINKED LIST OPERATIONS:****\n");
		printw("                MENU                             \n");
		printw("---------------------------------------\n");
		printw(" 1.Create     \n");
		printw(" 2.Display    \n");
		printw(" 3.Insert at the beginning    \n");
		printw(" 4.Insert at the end  \n");
		printw(" 5.Insert at specified position       \n");
		printw(" 6.Delete from beginning      \n");
		printw(" 7.Delete from the end        \n");
		printw(" 8.Delete from specified position     \n");
		printw(" 9.Exit       \n");
		printw("--------------------------------------\n");
		printw("Enter your choice:\t");
		scanw("%d", &choice);
		switch (choice)
		{
		case 1:clear();
			init(string_linked);
			create();
			break;
		case 2:clear();
			init(string_linked);
			display(cnt);
			break;
		case 3:clear();
			init(string_linked);
			insert_begin();
			break;
		case 4:clear();
			init(string_linked);
			insert_end();
			break;
		case 5:clear();
			init(string_linked);
			insert_pos();
			break;
		case 6:clear();
			init(string_linked);
			delete_begin();
			break;
		case 7:clear();
			init(string_linked);
			delete_end();
			break;
		case 8:clear();
			init(string_linked);
			delete_pos();
			break;
		case 9:
			show_windows();
			break;
		default:
			printf("\n Wrong Choice:\n");
			break;
		}
	}
}

void create()
{
	node *temp, *ptr;
	temp = (node *)malloc(sizeof(node));
	if (temp == NULL)
	{
		printw("\nOut of Memory Space:\n");
		show_windows();
	}
	printw("\nEnter the data value for the node:\t");
	scanw("%d", &temp->data);
	temp->next = NULL;
	if (start == NULL)
	{
		start = temp;
		cnt++;
	}
	else
	{
		ptr = start;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
		cnt++;
	}
}

void display(int n)
{
	struct node *ptr;
	if (start == NULL)
	{
		printw("\nList is empty:\n");
		printw("_______\n|       |\n| Head  |\n|_______|\n|\n|\nV\nNULL");
		return;
	}
	else
	{
		ptr = start;
		printw("\nThe List elements are:\n");
		while (ptr != NULL)
		{
			if(n==0)
				printw("\t _______ \t\n\t| %3d  |\n\t|_______|\n\t|  Next |\n\t|_______|\n\t    |\n\t ___V___\n", ptr->data);
			else
				printw("\t| %3d  |\n\t|_______|\n\t|  Next |\n\t|_______|\n\t    |\n\t ___V___\n", ptr->data);
			//printw("%d\t", ptr->data);
			ptr = ptr->next;
		}
		printf("\t|       |\n\t| %3d  |\n\t|_______|\n\t|       |\n\t| Next  |\n\t|_______|\n|\n|\n   V   \nNULL", ptr->data);
		
	}
}


void insert_begin()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	if (temp == NULL)
	{
		printw("\nOut of Memory Space:\n");
		return;
	}
	printw("\nEnter the data value for the node:\t");
	scanw("%d", &temp->data);
	temp->next = NULL;
	if (start == NULL)
	{
		start = temp;
		cnt++;
	}
	else
	{
		temp->next = start;
		start = temp;
		cnt++;
	}
}
void insert_end()
{
	node *temp, *ptr;
	temp = (node *)malloc(sizeof(node));
	if (temp == NULL)
	{
		printw("\nOut of Memory Space:\n");
		return;
	}
	printw("\nEnter the data value for the node:\t");
	scanw("%d", &temp->data);
	temp->next = NULL;
	if (start == NULL)
	{
		start = temp;
		cnt++;
	}
	else
	{
		ptr = start;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
		cnt++;
	}
}

void insert_pos()
{
	struct node *ptr, *temp;
	int i, pos;
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printw("\nOut of Memory Space:\n");
		return;
	}
	printw("\nEnter the position for the new node to be inserted:\t");
	scanw("%d", &pos);
	printw("\nEnter the data value of the node:\t");
	scanw("%d", &temp->data);

	temp->next = NULL;
	if (pos == 0)
	{
		temp->next = start;
		start = temp;
		cnt++;
	}
	else
	{
		for (i = 0, ptr = start; i<pos - 1; i++)
		{
			ptr = ptr->next;
			if (ptr == NULL)
			{
				printw("\nPosition not found\n");
				return;
			}
		}
		temp->next = ptr->next;
		ptr->next = temp;
		cnt++;
	}
}
void delete_begin()
{
	node *ptr;
	if (ptr == NULL)
	{
		printw("\nList is Empty:\n");
		return;
	}
	else
	{
		ptr = start;
		start = start->next;
		printw("\nThe deleted element is :%d\t", ptr->data);
		free(ptr);
		cnt--;
	}
}
void delete_end()
{
	node *temp, *ptr;
	if (start == NULL)
	{
		printw("\nList is Empty:");
		return;
	}
	else if (start->next == NULL)
	{
		ptr = start;
		start = NULL;
		printw("\nThe deleted element is:%d\t", ptr->data);
		free(ptr);
		cnt--;
	}
	else
	{
		ptr = start;
		while (ptr->next != NULL)
		{
			temp = ptr;
			ptr = ptr->next;
		}
		temp->next = NULL;
		printw("\nThe deleted element is:%d\t", ptr->data);
		free(ptr);
		cnt--;
	}
}
void delete_pos()
{
	int i, pos;
	struct node *temp, *ptr;
	if (start == NULL)
	{
		printw("\nThe List is Empty:\n");
		return;
	}
	else
	{
		printw("\nEnter the position of the node to be deleted:\t");
		scanw("%d", &pos);
		if (pos == 0)
		{
			ptr = start;
			start = start->next;
			printw("\nThe deleted element is:%d\t", ptr->data);
			free(ptr);
			cnt--;
		}
		else
		{
			ptr = start;
			for (i = 0; i<pos; i++)
			{
				temp = ptr;
				ptr = ptr->next;
				if (ptr == NULL)
				{
					printw("\nPosition not Found:\n");
					return;
				}
			}
			temp->next = ptr->next;
			printw("\nThe deleted element is:%d\t", ptr->data);
			free(ptr);
			cnt--;
		}
	}
}