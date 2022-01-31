/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#define qsize 1000

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b)
{
    return (a > b)? a : b;
}

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

struct Node* create(int data)
{
    struct Node* nitm = (struct Node*) malloc(sizeof(struct Node));
    nitm -> key = data;
    nitm -> left = NULL;
    nitm -> right = NULL;
    nitm -> height = 1;
    return nitm;
}

struct Node *rotate_right(struct Node *y)
{
    struct Node *x = y -> left;
    struct Node *tmp = x -> right;
 
    x -> right = y;
    y -> left = tmp;
 
    y -> height = max(height(y -> left), height(y -> right)) + 1;
    x -> height = max(height(x -> left), height(x -> right)) + 1;
 
    return x;
}

struct Node *rotate_left(struct Node *x)
{
    struct Node *y = x -> right;
    struct Node *tmp = y -> left;
 
    y -> left = x;
    x -> right = tmp;
 
    x -> height = max(height(x -> left), height(x -> right)) + 1;
    y -> height = max(height(y -> left), height(y -> right)) + 1;
 
    return y;
}

int balance_factor(struct Node *nitm)
{
    if (nitm == NULL)
        return 0;
    return height(nitm -> left) - height(nitm -> right);
}

struct Node* insert(struct Node* node, int data)
{
    if (node == NULL)
        return(create(data));
 
    if (data < node -> key)
        node -> left  = insert(node -> left, data);
        
    else if (data > node -> key)
        node -> right = insert(node -> right, data);
    
	else
        return node;
 
    node -> height = 1 + max(height(node -> left), height(node -> right));
 
    int balance = balance_factor(node);
 
    if (balance > 1 && data < node -> left -> key)
        return rotate_right(node);
 
    if (balance < -1 && data > node -> right -> key)
        return rotate_left(node);
 
    if (balance > 1 && data > node -> left -> key)
    {
        node -> left =  rotate_left(node -> left);
        return rotate_right(node);
    }
 
    if (balance < -1 && data < node -> right -> key)
    {
        node -> right = rotate_right(node -> right);
        return rotate_left(node);
    }
 
    return node;
}

struct Node * min_node(struct Node* node)
{
    struct Node* tmp = node;
    
    while (tmp -> left != NULL)
        tmp = tmp -> left;
 
    return tmp;
}

struct Node* del_node(struct Node* root, int data)
{
    if (root == NULL)
        return root;
 
    if ( data < root -> key )
        root -> left = del_node(root -> left, data);
 
    else if( data > root -> key )
        root -> right = del_node(root -> right, data);
 
    else
    {
        if((root -> left == NULL) || (root -> right == NULL))
        {
            struct Node *tmp = root -> left ? root -> left : root -> right;
 
            if (tmp == NULL)
            {
                tmp = root;
                root = NULL;
            }
            
            else
             *root = *tmp;
            
			free(tmp);
        }
        
        else
        {
            struct Node* tmp = min_node(root -> right);
            root -> key = tmp -> key;
            root -> right = del_node(root -> right, tmp -> key);
        }
    }

    if (root == NULL)
		return root;
 
    root -> height = 1 + max(height(root -> left), height(root -> right));
 
    int balance = balance_factor(root);
 
    if (balance > 1 && balance_factor(root -> left) >= 0)
        return rotate_right(root);
 
    if (balance > 1 && balance_factor(root -> left) < 0)
    {
        root -> left =  rotate_left(root -> left);
        return rotate_right(root);
    }
 
    if (balance < -1 && balance_factor(root -> right) <= 0)
        return rotate_left(root);
 
    if (balance < -1 && balance_factor(root -> right) > 0)
    {
        root -> right = rotate_right(root -> right);
        return rotate_left(root);
    }
 
    return root;
}

void inorder(struct Node* root)
{
	if(root == NULL)
		return;
	
	inorder(root -> left);
	printf(" %d ", root -> key);
	inorder(root -> right);
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
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n *****     AVL     TREE      *****\n");
	
	int first_choice;
	char second_choice;
	struct Node* root = NULL;
	first_menu:
	{
		printf("\n\n 1. Insert Node \n 2. Delete Node \n 3. Display the AVL Tree\n 4. Exit\n");
		printf("\n Enter your choice - ");
		scanf("%d", &first_choice);
	}
	
	if(first_choice == 1)
	{
		printf("\n Enter the number of elements to be inserted - ");
		int size;
		scanf("%d", &size);
		int i, data[size];
		for(i = 0; i < size; i++)
		{
			printf("\n Enter the element %d - ", i + 1);
			scanf("%d", &data[i]);
			root = insert(root, data[i]);
		}
		
		goto first_menu;
	}
	
	else if(first_choice == 2)
	{
		printf("\n Enter the data to be deleted - ");
		int data;
		scanf("%d", &data);
		root = del_node(root, data);
		
		goto first_menu;
	}
	
	else if(first_choice == 3)
	{
		printf("\n INORDER TRAVERSAL - ");
		inorder(root);
		printf("\n LEVEL ORDER TRAVERSAL - ");
		levelorder(root);
		
		goto first_menu;
	}
	
	else if(first_choice == 4)
		exit(0);
		
	else
	{
		printf("\n !!!!! Wrong Choice. Try Again !!!!!\n");
		goto first_menu;
	}
	
	return(0);
}
