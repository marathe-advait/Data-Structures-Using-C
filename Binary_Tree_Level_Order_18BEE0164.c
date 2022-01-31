/*	Name - Advait Marathe
	Reg - 18BEE0164			*/
	
#include <stdio.h>
#include <stdlib.h>
#define qsize 500

struct Node 
{
	int key;
	struct Node* left;
	struct Node* right;
};

struct Node** Queue(int*, int*);
void enqueue(struct Node**, int*, struct Node*);
struct Node* dequeue(struct Node**, int*);

void levelorder(struct Node* root)
{
	int rear, front;
	struct Node** queue = Queue(&front, &rear);
	struct Node* tmp = root;

	while (tmp) 
	{
		printf(" %d ", tmp -> key);

		if (tmp -> left)
			enqueue(queue, &rear, tmp -> left);

		if (tmp -> right)
			enqueue(queue, &rear, tmp -> right);

		tmp = dequeue(queue, &front);
	}
}

struct Node** Queue(int* front, int* rear)
{
	struct Node** queue = (struct Node**) malloc(sizeof(struct Node*) * qsize);
	*front = *rear = 0;
	return queue;
}

void enqueue(struct Node** queue, int* rear, struct Node* nitm)
{
	queue[*rear] = nitm;
	(*rear)++;
}

struct Node* dequeue(struct Node** queue, int* front)
{
	(*front)++;
	return queue[*front - 1];
}

struct Node* create(int data)
{
	struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
	nitm -> key = data;
	nitm -> left = NULL;
	nitm -> right = NULL;

	return nitm;
}

/* Driver program to test above functions*/
int main()
{
	struct Node* root = create(1);
	root -> left = create(2);
	root -> right = create(3);
	root -> left -> left = create(4);
	root -> left -> right = create(5);
	root -> right -> left = create(6);
	root -> right -> right = create(7);
	
	/*		 1
		   /   \		
		  2     3			//	Binary tree created using the above code.
		 / \   / \
	    4   5 6   7
	*/
	
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n *****   BINARY   TREE       *****\n");

	printf("\n Level order traversal - ");
	levelorder(root);

	return 0;
}

