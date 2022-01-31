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
	printf("\n ***** NAME - ADVAIT MARATHE  *****\n");
	printf("\n ***** REG -  18BEE0164       *****\n");
	printf("\n ***** CIRCULAR QUEUE MENU    *****\n");
	printf("\n ***** 0 shows deleted item   *****\n");
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
	
	if((front == 0) && (rear == MAX-1))
	{
		printf("\n !!!!! QUEUE OVERFLOW !!!!!");
	}
	
	else if((front == -1) && (rear == -1))
	{
		front = 0;
		rear = 0;
		printf("\n Enter element to add - ");
		scanf("%d",&val);
    	queue[rear] = val;	
	}
	
	else
	{	
		printf("\n Enter element to add - ");
		scanf("%d",&val);
		rear = (rear + 1) % MAX;
    	queue[rear] = val;
	}
	
	
}
 
void dequeue()
{
	if(front == -1)
	{
		printf("\n !!!!! QUEUE UNDERFLOW !!!!!");
	}
	else
	{
    	
		if (front == rear) 
		{
      		front = -1;
      		rear = -1;
    	} 
    
    	else 
		{
      		queue[front] = 0;
			front = (front + 1) % MAX;
    	}

	}
}
 
void display()
{
	int i;
	
	if(front == -1 )
	{
		printf("\n !!!!! QUEUE UNDERFLOW !!!!!");
	}
	
	else
	{
		printf("\n Queue is - \n");
		for(i = 0; i < rear+1; i++)
			printf(" %d,",queue[i]);
	}
}
