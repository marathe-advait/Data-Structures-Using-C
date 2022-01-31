/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
	int key;
	struct Node *nxt;
};

struct Node *head_ptr = NULL;

void push(struct Node** head, int data)
{
	struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
	nitm -> key = data;
	nitm -> nxt = (*head);
	(*head) = nitm;
}

void insert(struct Node* prev, int data)
{
	if(prev == NULL)
	{
		printf(" The previous node cannot be null.");
		return;
	}
	
	struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
	nitm -> key = data;
	nitm -> nxt = prev -> nxt;
	prev -> nxt = nitm;
}

void append(struct Node** head, int data)
{
	struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
	struct Node* last = *head;
	nitm -> key = data;
	nitm -> nxt = NULL;
	
	if(*head == NULL)
	{
		*head = nitm;
		return;
	}
	
	while(last -> nxt != NULL)
		last = last -> nxt;
	
	last -> nxt = nitm;
	return;
}

void swapnodes(struct Node** head, int x, int y)
{
    struct Node *prev_x = NULL, *curr_x = *head;
    while(curr_x && curr_x -> key != x)
    {
    	prev_x = curr_x;
    	curr_x = curr_x -> nxt;
	}
	
	struct Node *prev_y = NULL, *curr_y = *head;
    while(curr_y && curr_y -> key != y)
    {
    	prev_y = curr_y;
    	curr_y = curr_y -> nxt;
	}
	
	if (curr_x == NULL || curr_y == NULL)
        return;
 
    if (prev_x != NULL)
        prev_x -> nxt = curr_y;
    else
        *head = curr_y;
 
    if (prev_y != NULL)
        prev_y -> nxt = curr_x;
    else
        *head = curr_x;
 
    struct Node* tmp = curr_y -> nxt;
    curr_y -> nxt = curr_x -> nxt;
    curr_x -> nxt = tmp;
}

void swapkeys(struct Node** head, int x, int y)
{
    struct Node *prev_x = NULL, *curr_x = *head;
    while(curr_x && curr_x -> key != x)
    {
    	prev_x = curr_x;
    	curr_x = curr_x -> nxt;
	}
	
	struct Node *prev_y = NULL, *curr_y = *head;
    while(curr_y && curr_y -> key != y)
    {
    	prev_y = curr_y;
    	curr_y = curr_y -> nxt;
	}
	
	int tmp;
	tmp = curr_x -> key;
	curr_x -> key = curr_y -> key;
	curr_y -> key = tmp;
}

void print(struct Node* ptr)
{
	printf("\n The list is - ");
	while (ptr != NULL)
	{
		printf("%d -> ", ptr -> key);
		ptr = ptr -> nxt;
	}
}

int main()
{
	int ch_1, ch_2, x, y;
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n ***** LINKED LIST  MENU     *****\n");
	
	first_menu:
	{
		printf("\n\n 1. Insertion\n 2. Swap\n 3. Display\n 4. Exit");
		printf("\n\n Enter your choice (1 - 4) - ");
		scanf("%d",&ch_1);
	}
			
	if(ch_1 == 1)
	{
		printf("\n ***** INSERTION MENU        *****");
		while(1)
		{
			printf("\n\n 1. Push\n 2. Insert\n 3. Append\n 4. Return To Previous Menu");
			printf("\n\n Enter your choice (1 - 5) - ");
			scanf("%d",&ch_2);
			switch(ch_2)
			{
				case 1:	{
							int d;
							printf(" Enter the data to be pushed - ");
							scanf("%d", &d);
							push(&head_ptr, d);
							break;
						}
							
				case 2: {
							int d;
							printf(" Enter the data to be inserted - ");
							scanf("%d", &d);
							int pos;
							printf(" Enter the position to insert - ");
							scanf("%d",&pos);
							struct Node* tmp = head_ptr;
							int i;
							for(i = 0; i < pos-1; i++)
								tmp = tmp -> nxt;
							insert(tmp, d);
							break;
						}
							
				case 3:	{
							int d;
							printf(" Enter the data to be appended - ");
							scanf("%d", &d);
							append(&head_ptr, d);
							break;
						}
									
				case 4: goto first_menu;
						break;
					
				default: printf("\n !!!!! WRONG CHOICE !!!!!");
			}
		}
	}
		
	if(ch_1 == 2)
	{
		printf("\n ***** SWAP  MENU          *****");
		while(1)
		{
			
			printf("\n\n 1. Swap The Nodes \n 2. Swap The Keys \n 3. Return To Previous Menu");
			printf("\n\n Enter your choice (1 - 3) - ");
			scanf("%d", &ch_2);
			
			if(ch_2 == 1 || ch_2 == 2)
			{
				printf("\n\n Enter the elements to be swapped - ");
				scanf("%d %d", &x, &y);
			
				if(ch_2 == 1)
					swapnodes(&head_ptr, x, y);
			
				else if(ch_2 == 2)
					swapkeys(&head_ptr, x, y);
			}	
			
			else 
				goto first_menu;
		}
	}

		
	if(ch_1 == 3)
	{
		print(head_ptr);
		goto first_menu;	
	}
	
	if(ch_1 == 4)
		exit(0);
	
	else
	{
		printf("\n !!!!! WRONG CHOICE !!!!!");
		goto first_menu;
	}
	
	return(0);
}
