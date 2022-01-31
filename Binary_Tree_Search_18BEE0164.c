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

int getlevel(struct Node* node, int value, int level)
{
    if (node == NULL)
        return 0;
 
    if (node -> key == value)
        return level;
 
    int downlevel = getlevel(node->left, value, level+1);
    
	if (downlevel != 0)
        return downlevel;
 
    downlevel = getlevel(node->right, value, level+1);
    
    return downlevel;
}

int level(struct Node *node, int value)
{
    return getlevel(node, value, 1);
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
	
	int value;
	printf("\n Enter the value to be searched - ");
	scanf("%d", &value);
	
	if(level(root, value) == 0)
		printf("\n !!!!! ELEMENT NOT FOUND !!!!!");
	
	else
		printf("\n The node %d found at level %d.", value, level(root, value));
	
	return(0);
}
