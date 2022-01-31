#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
 
# define MAX 20
 
char str[MAX], stack[MAX];
int top = -1;
 
char pop()
{
      return stack[top--];
}
 
void push(char c)
{
      stack[++top] = c;
}

bool opr(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
 
void postfix_to_infix(char exp[])
{
      int i, len;
      char ele, op;
      len = strlen(exp);
      for(i = 0; i < MAX; i++)
      {
            stack[i] = 0;
      }
      printf("\n Infix Expression - ");
      printf("%c", exp[0]);
      for(i = 1; i < len; i++)
      {
            if(opr(exp[i]))
            {
                  ele = pop();
                  op = exp[i];
                  printf(" %c %c", op, ele);
            }
            else
            {
                  push(exp[i]);
            }
      }
      printf("%c", exp[top--]);
}
 
int main()
{
      char exp[50];
      printf("\n Enter Postfix Expression - ");
      scanf("%s", &exp);
      postfix_to_infix(exp);
      printf("\n");
      return 0;
}
