/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<process.h>
#include<stdlib.h>
 
#define MAX 5
 
int front = -1, queue[MAX], rear = -1;
void enqueue();
void dequeue();
void display();
 
int main()
{
	int ch;
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n ***** QUEUE  MENU           *****\n");
	while(1)
	{
		printf("\n\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit");
		printf("\n\n Enter your choice (1 - 4) - ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();
					break;
					
			case 2: dequeue();
					break;
					
			case 3: display();
					break;
					
			case 4: exit(0);
			
			default: printf("\n !!!!! WRONG CHOICE !!!!!");
		}
	}
	return(0);
}

void enqueue()
{
	int val;
	if(rear == MAX-1)
	{
		printf("\n !!!!! QUEUE OVERFLOW !!!!!");
	}
	else
	{	
		printf("\n Enter element to add - ");
		scanf("%d",&val);
		rear = rear+1;
		queue[rear] = val;
		front = 0;
	}
}
 
void dequeue()
{
	if(front == MAX)
	{
		printf("\n !!!!! QUEUE UNDERFLOW !!!!!");
	}
	else
	{
		int i;
		printf("\n Deleted element is %d",queue[front]);
		front = front+1;
		
	}
}
 
void display()
{
	int i;
	if(front == MAX )
	{
		printf("\n !!!!! QUEUE UNDERFLOW !!!!!");
	}
	else
	{
		printf("\n Queue is - \n");
		for(i = front; i <= rear; ++i)
			printf(" %d,",queue[i]);
	}
}
