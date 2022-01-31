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

void create(struct Node** head, int n)
{
	int i, data;
	struct Node *prev, *nitm;
	prev = NULL;
	nitm = NULL;
	
	for(i = 0; i < n; i++)
	{
		printf("\n Enter the data for node %d - ", i + 1);
		scanf("%d", &data);
		nitm = (struct Node*) malloc(sizeof(struct Node));
		nitm -> key = data;
		nitm -> nxt = NULL;
		
		if(prev != NULL)
			prev -> nxt = nitm;
		
		prev = nitm;
		if((*head) == NULL)
			(*head) = nitm;
	}
	prev -> nxt = (*head);
}


bool search(struct Node* head, int x)
{
    struct Node* ptr = head;
    while (ptr != NULL)
	{
		ptr = ptr -> nxt;
		
		if(ptr -> key == x)
			return true;
		
		if(ptr == head)
			break;
	}
	return false;
    
}

void reverse(struct Node** head)
{
	struct Node *prev, *tmp, *nxt, *last;
	
	if(*head == NULL)
		return;
	
	last = (*head);
	prev = (*head);
	tmp = (*head) -> nxt;
	(*head) = (*head) -> nxt;
	
	while((*head) != last)
	{
		(*head) = (*head) -> nxt;
		tmp -> nxt = prev;
		prev = tmp;
		tmp = (*head);
	}
	
	tmp -> nxt = prev;
	(*head) = prev;
}

void print(struct Node** head)
{
	struct Node* ptr = (*head);
	printf("\n The list is - ");
	while (ptr != NULL)
	{
		printf("%d -> ", ptr -> key);
		ptr = ptr -> nxt;
		if(ptr == (*head))
			break;
	}
}

int dist(struct Node** head, int one, int two)
{
	if(search(*head, one) && search(*head, two))
	{
		struct Node* tmp = (*head);
		int dist = 0;
		
		while(tmp -> key != one)
			tmp = tmp -> nxt;
		
		while(tmp -> key != two)
		{
			dist += 1;
			tmp = tmp -> nxt;
		}
		
		return dist;
	}
	
	else
	{
		printf(" !!!!! One of the elements not in list !!!!!");
		return -1;
	}
}

int main()
{
	int ch_1, ch_2;
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n ***** CIRCULAR LIST MENU    *****\n");
	
	first_menu:
	{
		printf("\n\n 1. Creation\n 2. Reversal\n 3. Distance between elements\n 4. Display\n 5. Exit");
		printf("\n\n Enter your choice (1 - 5) - ");
		scanf("%d",&ch_1);
	}
			
	if(ch_1 == 1)
	{
		printf("\n *****      CREATION          *****\n");
		printf("\n Enter the number of elements to be added - ");
		int n;
		scanf("%d", &n);
		create(&head_ptr, n);	
		goto first_menu;
	}
	
	if(ch_1 == 2)
	{
		reverse(&head_ptr);
		printf(" <<<<< List reversed sucessfully. >>>>>");
		goto first_menu;
	}
	
	if(ch_1 == 3)
	{
		int one, two;
		printf(" Enter the 1st element - ");
		scanf("%d", &one);
		printf(" Enter the 2nd element - ");
		scanf("%d", &two);
		printf("\n The distance between %d and %d is %d.", one, two, dist(&head_ptr, one, two));
		goto first_menu;
	}
	
	if(ch_1 == 4)
	{
		print(&head_ptr);
		goto first_menu;
	}
	
	if(ch_1 == 5)
	{
		exit(0);
	}
}
