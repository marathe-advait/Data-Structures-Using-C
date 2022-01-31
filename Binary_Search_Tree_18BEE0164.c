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

struct Node* insert(struct Node* root, int data)
{
	struct Node* nitm = create(data);
	struct Node* tmp = root;
	struct Node* y = NULL;
	
	while(tmp != NULL)
	{
		y = tmp;
		
		if(data < tmp -> key)
			tmp = tmp -> left;
		
		else
			tmp = tmp -> right;
	}
	
	if(y == NULL)
		y = nitm;
	
	else if(data < y -> key)
		y -> left = nitm;
	
	else
		y -> right = nitm;
}

void inorder(struct Node* root)
{
	if(root == NULL)
		return;
	
	inorder(root -> left);
	printf(" %d ", root -> key);
	inorder(root -> right);
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
	printf("\n ***** BINARY SEARCH TREE    *****\n");
	
	printf("\n Inorder traversal - ");
	inorder(root);
	printf("\n");
}
