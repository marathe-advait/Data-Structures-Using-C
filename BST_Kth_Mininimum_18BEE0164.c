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

struct Node* Kth_Min(struct Node* root, int index)
{
	if(root == NULL)
		return NULL;
	
	struct Node* left = Kth_Min(root -> left, index);
	
	if(left != NULL)
		return left;
	
	index = index - 1;
	
	if(index == 0)
		return root;
	
	return Kth_Min(root -> right, index);
}

int main()
{
	struct Node* root = NULL;
	
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n ***** BINARY SEARCH TREE    *****\n");
	
	int size, i;
	printf("\n Enter the nodes in BST - ");
	scanf("%d", &size);
	printf("\n");
	
	for(i = 0; i < size; i++)
	{
		int data;
		printf("\n Enter the node - ");
		scanf("%d", &data);
		
		if(i == 0)
			root = insert(root, data);
		
		else
			insert(root, data);
	}
	
	int k;
	printf("\n Enter k for finding kth smallest element - ");
	scanf("%d", &k);
	
	struct Node* element = Kth_Min(root, k);
	printf("\n The element at position %d is %d.", k, element -> key);
	return(0);
}
