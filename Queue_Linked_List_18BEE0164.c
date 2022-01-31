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

void delete_node(struct Node** head)
{
	struct Node *tmp = *head, *prev;
	if(tmp != NULL)
	{
		*head = tmp -> nxt;
		free(tmp);
		return;
	}

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
	printf("\n ***** QUEUE  MENU     *****\n");
	
	first_menu:
	{
		printf("\n\n 1. Insert\n 2. Delete\n 3. Search\n 4. Display\n 5. Exit");
		printf("\n\n Enter your choice (1 - 5) - ");
		scanf("%d",&ch_1);
	}
			
	if(ch_1 == 1)
	{
		int d;
		printf(" Enter the data to be appended - ");
		scanf("%d", &d);
		append(&head_ptr, d);
		goto first_menu;
	}
		
	if(ch_1 == 2)
	{
		delete_node(&head_ptr);
		goto first_menu;
					
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
