/*	Name - Advait Marathe
	Reg - 18BEE0164			*/
	
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 100

int front = -1, rear = -1;
char deque[MAX];

void push(char c)
{
	if(front == -1)
	{
		front = 0;
		rear = 0;
	}
	
	else
		rear = rear+1;
	
	deque[rear] = c;
}

bool palindrome(int start, int end)
{
	if(start == end)
		return true;

	
	if(deque[start] != deque[end])
		return false;
	
	if(start < end)
	{
		return palindrome(start + 1, end - 1);
	}
}

int main()
{
	char x[MAX];
	printf("\n Enter the string  - ");
	gets(x);
	
	int n = strlen(x), i;
	
	for(i = 0; i < n; i++)
	{
		if(isalpha(x[i]))
			push(tolower(x[i]));
	}
	
	
	palindrome(front, rear) ? printf(" Palindrome") : printf(" Not Palindrome");
}
