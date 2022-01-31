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

int height(struct Node* root)
{
	if(root == NULL)
		return(0);
		
	else
	{
		int lheight = height(root -> left);
		int rheight = height(root -> right);
		
		if(lheight > rheight)
			return lheight + 1;
		
		else
			return rheight + 1;
	}
}

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
	
	printf("\n Inorder traversal - ");
	inorder(root);
	printf("\n");
	
	printf("\n Preorder traversal - ");
	preorder(root);
	printf("\n");
	
	printf("\n Postorder traversal - ");
	postorder(root);
	printf("\n");
	
	printf("\n The height of tree is %d.", height(root));
	
	return(0);
}
