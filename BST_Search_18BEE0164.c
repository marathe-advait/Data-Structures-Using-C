/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool search(struct Node* node, int data)
{
	if(node == NULL)
		return false;
	
	if(node -> key == data)
		return true;
	
	if(data < node -> key)
		return search(node -> left, data);
	
	if(data > node -> key)
		return search(node -> right, data);
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
	printf("\n *****  SEARCH  IN  BST      *****\n");
	
	int data;
	printf("\n Enter the data to be searched - ");
	scanf("%d", &data);
	search(root, data) ? printf("\n The element present in the tree."): printf("\n Element not present in the tree.");
	return(0);
}
