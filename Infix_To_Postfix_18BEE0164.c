/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

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

char peek(struct Node* stack)
{
	return stack -> arr[stack -> top];
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

int op(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':	return 1;
		case '*':	
		case '/':	return 2;
		case '^':	return 3;
	}
	return -1;
}

int infix_to_postfix(char *exp)
{
	int i, k;
	
	struct Node* stack = Stack(strlen(exp));
	
	if(!stack)
		return -1;
	
	for(i = 0, k = -1; exp[i]; ++i)
	{
		if(op(exp[i]))
			exp[++k] = exp[i];
		
		else if(exp[i] == '(')
			push(stack, exp[i]);
		
		else if(exp[i] == ')')
		{
			while(!empty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			
			if(!empty(stack) && peek(stack) != '(')
				return -1;
				
			else
				pop(stack);
		}
		
		else
		{
			while(!empty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}
	}
	
	while(!empty(stack))
		exp[++k] = pop(stack);
	
	exp[++k] = '\0';
	printf(" The postfix expression is - %s", exp);
}

int main()
{
	char exp[200];
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n Enter the infix notation - ");
	scanf("%s", &exp);
	infix_to_postfix(exp);	
	return(0);
}
