/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
	int key;
	struct Node *nxt;
	struct Node *prev;
};

struct Node *head_ptr = NULL;

void push(struct Node** head, int data)
{
	if (*head == NULL)
    {
        struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
        nitm -> key = data;
        nitm -> nxt = nitm -> prev = nitm;
        *head = nitm;
        return;
    }
	
	struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
	struct Node* last = (*head) -> prev;
	
	nitm -> key = data;
	nitm -> nxt = *head;
	nitm -> prev = last;
	
	last -> nxt = nitm;
	
	if((*head) != NULL)
		(*head) -> prev = nitm;
	
	(*head) = nitm;
}

void insert(struct Node* prev_n, int data)
{
	if(prev_n == NULL)
	{
		printf(" The previous node cannot be null.");
		return;
	}
	
	struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
	nitm -> key = data;
	nitm -> nxt = prev_n -> nxt;
	prev_n -> nxt = nitm;
	nitm -> prev = prev_n;
	
	if(nitm -> nxt != NULL)
		nitm -> nxt -> prev = nitm;

}

void append(struct Node** head, int data)
{

    if (*head == NULL)
    {
        struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
        nitm -> key = data;
        nitm -> nxt = nitm -> prev = nitm;
        *head = nitm;
        return;
    }
 
    struct Node *last = (*head) -> prev;
 
    struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
    
	nitm -> key = data;
 	nitm -> nxt = *head;
 	(*head) -> prev = nitm;
 	nitm -> prev = last;
 	last -> nxt = nitm;
}

struct Node* reverse(struct Node** head)
{
	if (*head == NULL)
        return NULL;
 
    struct Node* new_head = NULL;
    struct Node* last = (*head) -> prev;
    struct Node* tmp = last, *prev;

    while (tmp -> prev != last) 
	{
        prev = tmp -> prev;
		append (&new_head, tmp -> key);
        tmp = prev;
    }
    
    append(&new_head, tmp -> key);
    return new_head;
}

int distance(struct Node** head, int x, int y)
{
	struct Node *tmp = *head;
	int d = 0;
	
	while(tmp -> key != x)
	{
		tmp = tmp -> nxt;
	}
	
	while(tmp -> key != y)
	{
		tmp = tmp -> nxt;
		d++;	
	}
	
	return d;	
}

void print(struct Node* head)
{
	struct Node* tmp = head;

	if(head == NULL)
	{
		printf("!!!!! UNDERFLOW !!!!!");
		return;
	}
	
	printf("\n Forward Traversal - ");
	while (tmp -> nxt != head)
	{
		printf("%d -> ", tmp -> key);
		tmp = tmp -> nxt;
	}
	printf("%d -> ", tmp -> key);
	
	struct Node* last = head -> prev;
	tmp = last;
	
	printf("\n Reverse Traversal - ");
	while (tmp -> prev != last)
	{
		printf("%d -> ", tmp -> key);
		tmp = tmp -> prev;
	}
	printf("%d -> ", tmp -> key);
}

int main()
{
	int ch_1, ch_2, x, y;
	printf("\n *****     NAME - ADVAIT MARATHE     *****\n");
	printf("\n *****     REG -  18BEE0164          *****\n");
	printf("\n ***** CIRCULAR LINKED LIST  MENU    *****\n");
	
	first_menu:
	{
		printf("\n\n 1. Insertion\n 2. Reversal\n 3. Distance between nodes\n 4. Display\n 5. Exit");
		printf("\n\n Enter your choice (1 - 5) - ");
		scanf("%d",&ch_1);
	}
			
	if(ch_1 == 1)
	{
		printf("\n ***** INSERTION MENU        *****");
		while(1)
		{
			printf("\n\n 1. Push\n 2. Insert\n 3. Append\n 4. Return To Previous Menu");
			printf("\n\n Enter your choice (1 - 4) - ");
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
		head_ptr = reverse(&head_ptr);
		goto first_menu;
	}
	
	if(ch_1 == 3)
	{
		printf("\n Enter the elements - ");
		scanf("%d %d", &x, &y);
		int dist = distance(&head_ptr, x, y);
		printf(" The distance between nodes is %d.", dist);
		goto first_menu;
	}
		
	if(ch_1 == 4)
	{
		print(head_ptr);
		goto first_menu;	
	}
	
	if(ch_1 == 5)
		exit(0);
	
	else
	{
		printf("\n !!!!! WRONG CHOICE !!!!!");
		goto first_menu;
	}
	
	return(0);
}
