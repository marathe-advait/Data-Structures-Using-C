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

void delete_node(struct Node** head, int data)
{
	struct Node *tmp = *head, *prev;
	if(tmp != NULL && tmp -> key == data)
	{
		*head = tmp -> nxt;
		free(tmp);
		return;
	}
	
	while (tmp != NULL && tmp -> key != data) 
	{
        prev = tmp;
        tmp = tmp->nxt;
    }
 
    if (tmp == NULL)
        return;
 
    prev -> nxt = tmp -> nxt;
 
    free(tmp);
}

void delete_list(struct Node** head)
{
   struct Node* tmp = *head;
   struct Node* next;
 
   while (tmp != NULL)
   {
       next = tmp -> nxt;
       free(tmp);
       tmp = next;
   }
   
   *head = NULL;
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
	printf("\n The list is - ");
	while (ptr != NULL)
	{
		printf("%d -> ", ptr -> key);
		ptr = ptr -> nxt;
	}
}

int main()
{
	int ch_1, ch_2;
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n ***** LINKED LIST  MENU     *****\n");
	
	first_menu:
	{
		printf("\n\n 1. Insertion\n 2. Deletion\n 3. Search\n 4. Display\n 5. Exit");
		printf("\n\n Enter your choice (1 - 5) - ");
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
		printf("\n ***** DELETION  MENU        *****");
		while(1)
		{
			printf("\n\n 1. Delete single node\n 2. Delete entire list\n 3. Return To Previous Menu");
			printf("\n\n Enter your choice (1 - 5) - ");
			scanf("%d",&ch_2);
			switch(ch_2)
			{
				case 1:	{
							int d;
							printf(" Enter the data to be deleted - ");
							scanf("%d", &d);
							delete_node(&head_ptr, d);
							break;
						}
						
				case 2: {
							delete_list(&head_ptr);
							printf(" List deleted successfully.");
							goto first_menu;
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
		exit(0);
	
	else
	{
		printf("\n !!!!! WRONG CHOICE !!!!!");
		goto first_menu;
	}
	
	return(0);
}
