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

struct Node* insert(struct Node* node, int data)
{
	if(node == NULL)
		return create(data);
	
	if(data < node -> key)
		node -> left = insert(node -> left, data);
	
	if(data > node -> key)
		node -> right = insert(node -> right, data);
	
	return node;
}

struct Node* min(struct Node* node)
{
    struct Node* tmp = node;
    
    while (tmp && tmp -> left != NULL)
        tmp = tmp -> left;
 
    return tmp;
}

struct Node* delete_node(struct Node* root, int data)
{
    if (root == NULL)
        return root;
 
    if (data < root -> key)
        root -> left = delete_node(root -> left, data);

    else if (data > root -> key)
        root -> right = delete_node(root -> right, data);
 
    else  
	{
        if (root -> left == NULL) 
		{
            struct Node* tmp = root -> right;
            free(root);
            return tmp;
        }
        
        else if (root -> right == NULL) 
		{
            struct Node* tmp = root -> left;
            free(root);
            return tmp;
        }
 
        struct Node* tmp = min(root -> right);
        root -> key = tmp -> key;
        root -> right = delete_node(root -> right, tmp -> key);
    }
    return root;
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
	struct Node* root = NULL;
	root = insert(root, 4);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 6);
	insert(root, 5);
	insert(root, 7);
	
	/*		 4
		   /   \		
		  2     6			//	Binary tree created using the above code.
		 / \   / \
	    1   3 5   7
	*/
	
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n ***** DELETION  IN  BST     *****\n");
	printf("\n Level order traversal - ");
	levelorder(root);
	printf("\n");
	int data;
	printf("\n Enter the data to be deleted - ");
	scanf("%d", &data);
	root = delete_node(root, data);
	printf("\n Level order traversal - ");
	levelorder(root);
	
	return(0);
}
