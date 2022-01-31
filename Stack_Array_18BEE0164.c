/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<process.h>
#include<stdlib.h>
 
#define MAX 5
 
int top = -1, stack[MAX];
void push();
void pop();
void display();
 
int main()
{
	int ch;
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n ***** STACK  MENU           *****\n");
	while(1)
	{
		printf("\n\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit");
		printf("\n\n Enter your choice (1 - 4) - ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
					break;
					
			case 2: pop();
					break;
					
			case 3: display();
					break;
					
			case 4: exit(0);
			
			default: printf("\n !!!!! WRONG CHOICE !!!!!");
		}
	}
	return(0);
}

void push()
{
	int val;
	if(top == MAX-1)
	{
		printf("\n !!!!! STACK OVERFLOW !!!!!");
	}
	else
	{	
		printf("\n Enter element to add - ");
		scanf("%d",&val);
		top = top+1;
		stack[top] = val;
	}
}
 
void pop()
{
	if(top == -1)
	{
		printf("\n !!!!! STACK UNDERFLOW !!!!!");
	}
	else
	{
		printf("\n Deleted element is %d",stack[top]);
		top = top-1;
	}
}
 
void display()
{
	int i;
	if(top == -1 )
	{
		printf("\n !!!!! STACK UNDERFLOW !!!!!");
	}
	else
	{
		printf("\n STACK is - \n");
		for(i = top; i >= 0; --i)
			printf(" %d,",stack[i]);
	}
}
