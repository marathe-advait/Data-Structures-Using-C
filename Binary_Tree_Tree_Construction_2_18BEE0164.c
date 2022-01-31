/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define qsize 1000

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
};

struct Node* create(int data)
{
	struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
	
	nitm -> key = data;
	nitm -> left = NULL;
	nitm -> right = NULL;
	
	return nitm;
}

int search(int arr[], int key, int start, int end)
{
	if(arr[start] == key)
		return start;
		
	search(arr, key, start+1, end);
}

struct Node* construct(int preorder[], int postorder[], int* preorder_index, int start, int end, int size)
{
    if (*preorder_index >= size || start > end)
        return NULL;
 
    struct Node* root = create( preorder[*preorder_index] );
    ++ *preorder_index;
 
    if (start == end)
        return root;
 
    int postorder_index = search(postorder, preorder[*preorder_index], start, end);
 
    if (postorder_index <= end)
    {
        root -> left = construct(preorder, postorder, preorder_index, start, postorder_index, size);
        root -> right = construct(preorder, postorder, preorder_index,postorder_index + 1, end - 1, size);
    }
 
    return root;
}

struct Node* Binary_Tree (int preorder[], int postorder[], int size)
{
    int preorder_index = 0;
    return construct(preorder, postorder, &preorder_index, 0, size - 1, size);
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

int main()
{
	int size, i;
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n *****   TREE  CONSTRUCTION  *****\n");
	
	printf("\n Enter the size of array - ");
	scanf("%d", &size);
	
	int postorder[size], preorder[size];
	printf("\n Enter the elements in preorder.\n");
	for(i = 0; i < size; i++)
	{
		printf("\n Enter the element %d - ", i+1);
		scanf("%d", &preorder[i]);
	}
	
	printf("\n Enter the elements in postorder.\n");
	for(i = 0; i < size; i++)
	{
		printf("\n Enter the element %d - ", i+1);
		scanf("%d", &postorder[i]);
	}
	
	struct Node* root = Binary_Tree(preorder, postorder, size);
	
	printf("\n The level order of binary tree is - ");
	levelorder(root);
}
