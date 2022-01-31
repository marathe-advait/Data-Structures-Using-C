/*	Name - Advait Marathe
	Reg - 18BEE0164			*/
	
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include<string.h>
#define ssize 500

struct Node 
{
	char key;
	struct Node* left;
	struct Node* right;
};

char char_stack[ssize];
int char_top = -1;

struct Node** Stack(int* node_top)
{
	struct Node** stack = (struct Node**) malloc(sizeof(struct Node*) * ssize);
	*node_top = -1;
	return stack;
}

void node_push(struct Node** stack, int* node_top, struct Node* nitm)
{
	stack[*node_top] = nitm;
	(*node_top)++;
}

struct Node* node_pop(struct Node** stack, int* node_top)
{
	(*node_top)--;
	return stack[*node_top + 1];
}

void char_push(char char_stack[], char ele)
{
	char_top++;
	char_stack[char_top] = ele;
}

char char_pop(char char_stack[])
{
	char_top--;
	return char_stack[char_top + 1];
}

bool char_stack_empty()
{
	return char_top == -1;
}

struct Node* create(char data)
{
	struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
	nitm -> key = data;
	nitm -> left = NULL;
	nitm -> right = NULL;

	return nitm;
}

struct Node* Expression_Tree(char exp[], int exp_size)
{
	int node_top, i;
	struct Node** node_stack = Stack(&node_top);
	struct Node* p;
	struct Node* q;
	struct Node* r;
	
	int pr[123] = {0};
	pr['+'] = pr['-'] = 1;
	pr['*'] = pr['/'] = 2;
	pr['^'] = 3;
	pr['('] = 0;
	
	for(i = 0; i < exp_size; i++)
	{
		if(exp[i] == '(')
			char_push(char_stack, exp[i]);
		
		else if(isalpha(exp[i]))
		{
			p = create(exp[i]);
			node_push(node_stack, &node_top, p);
		}
		
		else if(pr[exp[i]] > 0)
		{
			while(!char_stack_empty() && char_stack[char_top] != '(' && ((exp[i] == '^' && pr[char_stack[char_top]] >= pr[exp[i]]) || (exp[i] == '^' && pr[char_stack[char_top]] > pr[exp[i]])))
			{
				p = create(char_pop(char_stack));
				q = node_pop(node_stack, &node_top);
				r = node_pop(node_stack, &node_top);
				
				p -> left = r;
				p -> right = q;
				node_push(node_stack, &node_top, p);
			}
			
			char_push(char_stack, exp[i]);
		}
		
		else if(exp[i] == ')')
		{
			while(!char_stack_empty() && char_stack[char_top] != '(')
			{
				p = create(char_pop(char_stack));
				q = node_pop(node_stack, &node_top);
				r = node_pop(node_stack, &node_top);
				
				p -> left = r;
				p -> right = q;
			}
			
			char c = char_pop(char_stack);
		}
		
	}
	p = node_pop(node_stack, &node_top);
	return p;
}

void inorder(struct Node* root)
{
	if(root == NULL)
		return;
	
	inorder(root -> left);
	printf(" %d ", root -> key);
	inorder(root -> right);
}

void preorder(struct Node* root)
{
	if(root == NULL)
		return;
	
	printf(" %d ", root -> key);
	preorder(root -> left);
	preorder(root -> right);
}

void postorder(struct Node* root)
{
	if(root == NULL)
		return;
	
	postorder(root -> left);
	postorder(root -> right);
	printf(" %d ", root -> key);
}

int main()
{
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n *****   EXPRESSION   TREE   *****\n");
	
	char exp[100];
	printf("\n Enter the expression - ");
	scanf("%s", &exp);
	int size = sizeof(exp)/sizeof(exp[0]);
	
	struct Node* root = Expression_Tree(exp, size);
	printf("\n The postfix expression is - ");
	postorder(root);
	printf("\n");
	
	printf("\n The prefix expression is - ");
	preorder(root);	
}
