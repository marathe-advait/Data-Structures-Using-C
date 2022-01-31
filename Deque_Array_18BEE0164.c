/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<stdbool.h>
 
#define MAX 10
 
int front = -1, queue[MAX], rear = -1;

bool overflow()
{
	return ((front == 0 && rear == MAX-1)||(front == rear + 1));
}

bool underflow()
{
	return (front == -1);
}

void ins_front()
{
	if(overflow())
	{
		printf("\n !!!!! OVERFLOW !!!!!");
		return;
	}
	
	if(front == -1)
	{
		front = 0;
		rear = 0;
	}
	
	else if(front == 0)
		front = MAX-1;
	
	else
		front = front-1;
	
	int val;
	printf("\n Enter element to add on front - ");
	scanf("%d",&val);
	queue[front] = val;
		
}

void ins_end()
{
	if(overflow())
	{
		printf("\n !!!!! OVERFLOW !!!!!");
		return;
	}
	
	if(front == -1)
	{
		front = 0;
		rear = 0;
	}
	
	else if(rear == MAX)
		rear = 0;
	
	else
		rear = rear+1;
	
	int val;
	printf("\n Enter element to add on rear - ");
	scanf("%d",&val);
	queue[rear] = val;
		
}

int peek()
{
	return queue[front];
}

int pop()
{
	return queue[rear];
}

void del_front()
{
	if(underflow())
	{
		printf("\n !!!!! UNDERFLOW !!!!!");
		return;
	}
	
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	
	else if(front == MAX-1)
		front = 0;
	
	else
		front = front+1;
		
}

void del_end()
{
	if(underflow())
	{
		printf("\n !!!!! UNDERFLOW !!!!!");
		return;
	}
	
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	
	else if(rear == 0)
		rear = MAX-1;
	
	else
		rear = rear-1;
		
}

void display()
{
	int i;
	printf("\n Queue is - \n");
	for(i = front; i != rear; i = (i+1)%MAX)
		printf(" %d,",queue[i]);
	printf(" %d", queue[rear]);
}

int main()
{
	int ch;
	printf("\n ***** NAME - ADVAIT MARATHE  *****\n");
	printf("\n ***** REG -  18BEE0164       *****\n");
	printf("\n *****     DEQUE MENU         *****\n");
	
	first_menu:
	{
		printf("\n\n 1. Insertion\n 2. Deletion\n 3. Get element\n 4. Display\n 5. Exit");
		printf("\n\n Enter your choice (1 - 4) - ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: goto insertion;
					break;
					
			case 2: goto deletion;
					break;
					
			case 3: goto get_character;
					break;
					
			case 4: display();
					goto first_menu;
					break;
			
			case 5:	exit(0);
			
			default: printf("\n !!!!! WRONG CHOICE !!!!!");
		}
	}
	
	insertion:
	{
		printf("\n\n 1. Insertion at beginning\n 2. Insertion at end\n 3. Return to previous menu");
		printf("\n\n Enter your choice (1 - 3) - ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: ins_front();
					goto insertion;
					break;
					
			case 2: ins_end();
					goto insertion;
					break;
					
			case 3: goto first_menu;
					break;
			
			default: printf("\n !!!!! WRONG CHOICE !!!!!");
		}
		
	}
	
	deletion:
	{
		printf("\n\n 1. Deletion at beginning\n 2. Deletion at end\n 3. Return to previous menu");
		printf("\n\n Enter your choice (1 - 3) - ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: del_front();
					goto deletion;
					break;
					
			case 2: del_end();
					goto deletion;
					break;
					
			case 3: goto first_menu;
					break;
			
			default: printf("\n !!!!! WRONG CHOICE !!!!!");
		}
		
	}
	
	get_character:
	{
		printf("\n\n 1. Get element from beginning\n 2. Get element from end\n 3. Return to previous menu");
		printf("\n\n Enter your choice (1 - 3) - ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf(" The element at front is - %d", peek());
					goto get_character;
					break;
					
			case 2: printf(" The element at rear is - %d", pop());
					goto get_character;
					break;
					
			case 3: goto first_menu;
					break;
			
			default: printf("\n !!!!! WRONG CHOICE !!!!!");
		}
	}
	
	return(0);
}
