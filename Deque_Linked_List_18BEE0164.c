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
	struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
	nitm -> key = data;
	nitm -> nxt = (*head);
	nitm -> prev = NULL;
	
	if((*head) != NULL)
		(*head) -> prev = nitm;
	
	(*head) = nitm;
}

void append(struct Node** head, int data)
{
	struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
	struct Node* last = *head;
	nitm -> key = data;
	nitm -> nxt = NULL;
	
	if(*head == NULL)
	{
		nitm -> prev = NULL;
		*head = nitm;
		return;
	}
	
	while(last -> nxt != NULL)
		last = last -> nxt;
	
	last -> nxt = nitm;
	nitm -> prev = last;
	
	return;
}

int peek(struct Node** head)
{
	struct Node* tmp = *head;
	return tmp -> key;
}

int pop(struct Node** head)
{
	struct Node* tmp = *head;
   	struct Node* last;
 
   	while (tmp != NULL)
   	{
       	last = tmp;
	   	tmp = tmp -> nxt;
   	}
   	
   	return last -> key;
}

void delete_front(struct Node** head)
{
	
	struct Node *tmp = *head;
	
	if(tmp == NULL)
	{
		printf("!!!!! UNDERFLOW !!!!!");
		return;
	}
	
	*head = tmp -> nxt;
	tmp -> nxt -> prev = NULL;
	free(tmp);
	return;
	
}

void delete_rear(struct Node** head)
{
   struct Node* tmp = *head;
   
   	if(tmp == NULL)
	{
		printf("!!!!! UNDERFLOW !!!!!");
		return;
	}
	
   struct Node* last;
 
   while (tmp != NULL)
   {
       last = tmp;
	   tmp = tmp -> nxt;
   }
   
   last -> prev -> nxt = NULL;
   free(last);
   
}

bool search(struct Node* head, int x)
{
    if (head == NULL)
        return false;
      
    if (head -> key == x)
        return true;
  
    return search(head -> nxt, x);
}

void print(struct Node* ptr)
{
	struct Node* last;
	
	printf("\n Forward Traversal - ");
	while (ptr != NULL)
	{
		printf("%d -> ", ptr -> key);
		last = ptr;
		ptr = ptr -> nxt;
	}
	
	printf("\n Reverse Traversal - ");
	while (last != NULL)
	{
		printf("%d -> ", last -> key);
		last = last -> prev;
	}
}

int main()
{
	int ch_1, ch_2;
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n ***** DEQUE    MENU         *****\n");
	
	first_menu:
	{
		printf("\n\n 1. Insertion\n 2. Deletion\n 3. Search\n 4. Display\n 5. Get Character\n 6. Exit");
		printf("\n\n Enter your choice (1 - 5) - ");
		scanf("%d",&ch_1);
	}
			
	if(ch_1 == 1)
	{
		printf("\n *****    INSERION MENU         *****\n");
		while(1)
		{
			printf("\n\n 1. Insert at front \n 2. Insert at end\n 3. Return To Previous Menu");
			printf("\n\n Enter your choice (1 - 5) - ");
			scanf("%d",&ch_2);
			switch(ch_2)
			{
				case 1:	{
							int d;
							printf(" Enter the data to be inserted at front - ");
							scanf("%d", &d);
							push(&head_ptr, d);
							break;
						}
							
							
				case 2:	{
							int d;
							printf(" Enter the data to be inserted at rear - ");
							scanf("%d", &d);
							append(&head_ptr, d);
							break;
						}
									
				case 3: goto first_menu;
						break;
					
				default: printf("\n !!!!! WRONG CHOICE !!!!!");
			}
		}
	}
		
	if(ch_1 == 2)
	{
		printf("\n ***** DELETION  MENU        *****");
		while(1)
		{
			printf("\n\n 1. Delete single node fron front\n 2. Delete single node from rear\n 3. Return To Previous Menu");
			printf("\n\n Enter your choice (1 - 3) - ");
			scanf("%d",&ch_2);
			switch(ch_2)
			{
				case 1:	{
							delete_front(&head_ptr);
							break;
						}
						
				case 2: {
							delete_rear(&head_ptr);
							break;
						}
						
				case 3:	{
							goto first_menu;
							break;
						}
				
				default: printf("\n !!!!! WRONG CHOICE !!!!!");
			}
		}
	}
		
	if(ch_1 == 3)
	{
		printf(" Enter the element to be searched - ");
		scanf("%d", &ch_2);
		search(head_ptr, ch_2) ? printf(" Element present in the list") : printf(" Element not found");
		goto first_menu;
	}
		
	if(ch_1 == 4)
	{
		print(head_ptr);
		goto first_menu;	
	}
	
	if(ch_1 == 5)
	{
		printf("\n ***** GET  CHARACTER  MENU      *****");
		while(1)
		{
			printf("\n\n 1. Get element from beginning\n 2. Get element from end\n 3. Return to previous menu");
			printf("\n\n Enter your choice (1 - 3) - ");
			scanf("%d",&ch_2);
			switch(ch_2)
			{
				case 1: printf(" The element at front is - %d", peek(&head_ptr));
						break;
						
				case 2: printf(" The element at rear is - %d", pop(&head_ptr));
						break;
						
				case 3: goto first_menu;
						break;
				
				default: printf("\n !!!!! WRONG CHOICE !!!!!");
			}
		}
	}
	
	if(ch_1 == 6)
		exit(0);
	else
	{
		printf("\n !!!!! WRONG CHOICE !!!!!");
		goto first_menu;
	}
	
	return(0);
}
