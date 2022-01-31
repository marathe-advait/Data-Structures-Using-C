/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct Word
{
	char word[128], mean[256];				// Word and its corresponding definition.
	struct Word *left;
	struct Word *right;
};

struct Word* root = NULL;

struct Word* create(char *nword, char *nmean)
{
	struct Word* nitm = (struct Word*) malloc(sizeof(struct Word));
	
	strcpy(nitm -> word, nword);
	strcpy(nitm -> mean, nmean);
	nitm -> left = NULL;
	nitm -> right = NULL;
	
	return nitm;
}

void insert (char *nword, char *nmean)
{
	struct Word *parent = NULL, *current = NULL, *nitm = NULL;
	int res = 0;
	
	if(!root)								// If the BST is empty, a new node is created and assigned to the root.
	{
		root = create(nword, nmean);
		return;	
	}
	
	for(current = root; current != NULL; current = (res > 0) ? current -> right : current -> left)
	{
		res = strcasecmp(nword, current -> word);			// If the ASCII value > 0, for example, di appears after de, di > de and vice versa.
								
		if(res == 0)										// If the word already exists.
		{
			printf("\n !!!!! DUPLICATE ENTRY !!!!! \n");
			return;											
		}
		
		parent = current;
	}
	
	nitm = create(nword, nmean);							
	(res > 0) ? (parent -> right = nitm) : (parent -> left = nitm);		// If the word is smaller than traverse to the left, else traverse to right.
	return;
}

void search(char* query)
{
	struct Word* tmp = NULL;
	int flag = 0, res = 0;
	
	if(root == NULL)
	{
		printf("\n !!!!! EMPTY DICTIONARY !!!!!");
		return;
	}
	
	tmp = root;
	
	while(tmp)
	{
		if((res = strcmp(tmp -> word, query)) == 0)					// If the query matches with any word in the dictionary
		{
			printf("\n WORD - %s", tmp -> word);
			printf("\n MEANING - %s", tmp -> mean);
			printf("\n");
			flag = 1;
			break;
		}
		
		else
			tmp = (res > 0) ? (tmp -> left) : (tmp -> right);		// If the word is smaller than traverse to the left, else traverse to right.
	}
	
	if(!flag)
		printf("\n !!!!! ELEMENT NOT FOUND !!!!!");
	
	return;
}

void del_word(char *query)
{
	struct Word *parent = NULL, *current = NULL, *tmp = NULL;
	int res = 0, flag = 0;
	
	if(!root)
	{
		printf("\n !!!!! EMPTY DICTIONARY !!!!! \n");
		return;
	}
	
	current = root;
	
	while(1)
	{
		res = strcasecmp(current -> word, query);
			
		if(res == 0)													
			break;	
			
		flag = res;
		parent = current;
		current = (res > 0) ? (current -> left) : (current -> right);				// If the word is smaller than traverse to the left, else traverse to right.
		
		if(current == NULL)
		{
			printf("\n !!!!! ELEMENT NOT FOUND !!!!! \n");
			return;
		}
	}
	
	if(current -> right == NULL)
	{
		if(current == root && current -> left == NULL)							// If only root element exists
		{
			free(current);
			root = NULL;
			return;
		}
		
		else if(current == root)												// If the root is deleted, the element on the left of root is made as new root.
		{
			root = current -> left;
			free(current);
		}
		
		(flag > 0) ? (parent -> left = current -> left) : (parent -> right = current -> right);
	}
	
	else
	{
		tmp = current -> right;
		
		if(!tmp -> left)														// If the root is a leaf node	
		{
			tmp -> left = current -> left;										
			
			if(current == root)
			{
				root = tmp;
				free(current);
				return;
			}
			
			(flag > 0) ? (parent -> left = tmp) : (parent -> right = tmp);
		}
		
		else
		{
			struct Word* succ = NULL;											// If the root has two children
			
			while(1)
			{
				succ = tmp -> left;
				
				if(!tmp -> left)
					break;
				
				tmp = succ;
			}
			
			tmp -> left = succ -> right;										// The right child is made as left child of previous node
			succ -> left = current -> left;										// The left child is made the left child of current node
			succ -> right = current -> right;									// The right child is made the right child of current node
			
			if(current == root)
			{
				root = succ;
				free(current);
				
			}	
			
			(flag > 0) ? (parent -> left = succ) : (parent -> right = succ);
		}
	}
	
	free(current);
	return;
}

void inorder(struct Word* root)
{
	if(root == NULL)
		return;
	
	inorder(root -> left);
	printf("\n WORD - %s ", root -> word);
	printf("\n MEANING - %s ", root -> mean);
	printf("\n ================================================== \n");
	inorder(root -> right);
}

int main()
{
	int choice;
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n *****  BST   DICTIONARY     *****\n");
	
	char word[128];
	char mean[256];
	
	while(1)
	{
		printf("\n 1. INSERTION \n 2. DELETION \n 3. SEARCHING \n 4. DISPLAY DICTIONARY \n 5. EXIT\n");
		printf("\n Enter your choice - ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:	{
						printf("\n Enter the word - ");
						scanf("%s", &word);
						printf("\n Enter the meaning - ");
						scanf("%s", &mean);
						insert(word, mean);
						break;
					}
					
			case 2:	{
						printf("\n Enter the word to be deleted - ");
						scanf("%s", &word);
						del_word(word);
						break;
					}
					
			case 3:	{
						printf("\n Enter the word to be searched - ");
						scanf("%s", &word);
						search(word);
						break;
					}
					
			case 4: {
						inorder(root);
						break;
					}
			
			case 5:	{
						exit(0);
						break;
					}
			
			default: printf("\n !!!!! WRONG CHOICE. TRY AGAIN !!!!!");
					 break;
		}
	}
	
	return(0);
}
