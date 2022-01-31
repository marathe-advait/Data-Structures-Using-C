/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data 
{
	int key, value;							// Key Value Pair for Dictionary
};

struct hash_item
{
	int flag;								// Checks whether the location is empty or not, one key hs exactly one value
	struct data *item;						// Data pointer in hash table
};

struct hash_item *hash_table;

int table_capacity;
int size = 0;								// Size shows the number of elements in the hash table

int hash_code(int value)
{
	return ((value * value + 3 * value + 2) % table_capacity);		// Hash function determines how to rank data
}

void init_array()
{
	int i;
	
	for(i = 0; i < table_capacity; i++)		// Initialises all locations as available and all items as NULL
	{
		hash_table[i].flag = 0;
		hash_table[i].item = NULL;
	}
}

void insert(int value)
{
	int ind = hash_code(value);				// Gets the hash code of the item
	int i = ind;
	
	struct data* nitm = (struct data*) malloc(sizeof(struct data));
	nitm -> value = value;
	
	while (hash_table[i].flag == 1) 		// Checks if the memory location is occupied
    {
 
		i = (i + 1) % table_capacity;		// If yes, then the linear search for empty location begins
	
		if (i == ind) 
    	{
			printf("\n Hash table is full, cannot insert any more item. \n");
			return;
		}
 
    }
    
    nitm -> key = i;
	hash_table[i].flag = 1;					// The memory location occupied with the new data
    hash_table[i].item = nitm;
    size++;
    
    printf("\n Value %d has been inserted at position %d. \n", value, i + 1);
}

void display()
{
    int i;
    printf("\n KEY \t|\tVALUE ");
    printf("\n--------+--------------");
    for (i = 0; i < table_capacity; i++)
    {
		struct data *tmp = (struct data*) hash_table[i].item;
 
		if (tmp == NULL) 
	    	printf("\n <<<<<   EMPTY ENTRY    >>>>>");
	    
		else
	    	printf("\n  %d \t|\t  %d ", tmp -> key + 1, tmp -> value);
    }
}

int main()
{
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n *****     HASH  MAPPING     *****\n");
	
	printf("\n Enter the size of hash table - ");
	scanf("%d", &table_capacity);
	
	hash_table = (struct hash_item*) malloc(table_capacity * sizeof(struct hash_item));
	init_array();
	
	int i, values[table_capacity];
	for(i = 0; i < table_capacity; i++)
	{
		int value;
		printf("\n Enter the Value %d - ", i + 1);
		scanf("%d", &values[i]);
	}
	
	for(i = 0; i < table_capacity; i++)
	{
		insert(values[i]);
	}
	
	printf("\n <<<<<     HASH    TABLE     >>>>>\n");
	display();
	return(0);
}
