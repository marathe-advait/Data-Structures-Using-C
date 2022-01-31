/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

struct Node
{
	int top;
	int *arr;
	unsigned len;
};

struct Node* Stack(unsigned len)
{
	struct Node* stack = (struct Node*) malloc(sizeof(struct Node));
	
	if(!stack)
		return NULL;
	
	stack -> top = -1;
	stack -> len = len;
	stack -> arr = (int*) malloc(stack -> len * sizeof(int));
	return stack;	
}

int empty(struct Node* stack)
{
	return stack -> top == -1;
}

char pop(struct Node* stack)
{
	if(!empty(stack))
		return stack -> arr[stack -> top--];
	return '$';
}

void push(struct Node* stack, char op)
{
	stack->arr[++stack -> top] = op;
}

int get_postfix(char *exp)
{
	struct Node* stack = Stack(strlen(exp));
	int i;
	
	if(!stack)
		return -1;
	
	for(i = 0; exp[i]; i++)
	{
		if(isdigit(exp[i]))
			push(stack, exp[i] - '0');
		
		else
		{
			int m = pop(stack);
			int n = pop(stack);
			switch(exp[i])
			{
				case '+':	push(stack, n + m);
							break;
				case '-':	push(stack, n - m);
							break;
				case '*':	push(stack, n * m);
							break;
				case '/':	push(stack, n / m);
							break;
			}
		}
	}
	return pop(stack);
}

int main()
{
	char exp[200];
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n Enter the postfix notation - ");
	scanf("%s", &exp);
	printf(" The result is - %d", get_postfix(exp));	
	return(0);
}
