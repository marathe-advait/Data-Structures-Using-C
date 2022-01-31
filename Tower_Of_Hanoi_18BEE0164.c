#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


struct Stack
{
	unsigned len;
	int top;
	int *arr;
};

struct Stack* create(unsigned size)
{
	int i;
	struct Stack* pole = (struct Stack*) malloc(sizeof(struct Stack));
	pole -> len = size;
	pole -> top = -1;
	pole -> arr = (int*) malloc(pole -> len * sizeof(int));
	
	for(i = 1; i < size + 1; i++)
		pole -> arr[i] = i;
	
	return pole;
}

bool overflow(struct Stack* pole)
{
	return (pole -> top == pole -> len - 1);
}

bool underflow(struct Stack* pole)
{
	return (pole -> top == -1);
}

void push(struct Stack *pole, int disc)
{
	if (overflow(pole))
		return;
	
	pole -> arr[++pole -> top] = disc;
}

int pop(struct Stack* pole)
{
	if (underflow(pole))
		return INT_MIN;
	
	return pole -> arr[pole -> top--];
}

void display(struct Stack* pole)
{
	int i;
	for(i = pole -> top; i >= 0; i--)
		printf("%d, ", pole -> arr[i]);
}

void move(struct Stack *src, struct Stack *dest, char s, char d)
{
	int SrcDisk = pop(src);
	int DestDisk = pop(dest);

	if (DestDisk == INT_MIN)
	{
		push(src, DestDisk);
		printf("\n Move disk %d from %c to %c ", DestDisk, d, s);
	}

	else if (SrcDisk == INT_MIN)
	{
		push(dest, SrcDisk);
		printf("\n Move disk %d from %c to %c ", SrcDisk, s, d);
	}

	else if (SrcDisk > DestDisk)
	{
		push(src, SrcDisk);
		push(src, DestDisk);
		printf("\n Move disks %d and %d to %c ", SrcDisk, DestDisk, s);
	}

	else
	{
		push(dest, DestDisk);
		push(dest, SrcDisk);
		printf("\n Move disks %d and %d to %c ", SrcDisk, DestDisk, d);
	}
	
	printf("\n The Pole %c is - ", s);
	display(src);
	printf("\n The Pole %c is - ", d);
	display(dest);
}

void tower_of_hanoi(int n, struct Stack *src, struct Stack *aux, struct Stack *dest)
{
	int i;
	char s = 'S', d = 'D', a = 'A';
	
	if(n == 1)
	{
		move(src, dest, s, d);
		return;
	}
	
	tower_of_hanoi(n-1, src, dest, aux);
	move(src, dest, s, d);
	tower_of_hanoi(n-1, aux, src, dest);
}

int main()
{
	unsigned num_of_disks = 3;

	struct Stack *src, *dest, *aux;

	src = create(num_of_disks);
	aux = create(num_of_disks);
	dest = create(num_of_disks);

	tower_of_hanoi(num_of_disks, src, aux, dest);
	return 0;
}

