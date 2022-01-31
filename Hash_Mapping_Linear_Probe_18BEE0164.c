/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data 
{
	int key, value;
};

struct hash_item
{
	int flag;
	struct data *item;
};

struct hash_item *hash_table;

int table_capacity;
int size = 0;

int hash_code(int value)
{
	return ((3 * value + 2) % table_capacity);
}

void init_array()
{
	int i;
	
	for(i = 0; i < table_capacity; i++)
	{
		hash_table[i].flag = 0;
		hash_table[i].item = NULL;
	}
}

void insert(int value)
{
	int ind = hash_code(value);
	int i = ind;
	
	struct data* nitm = (struct data*) malloc(sizeof(struct data));
	nitm -> value = value;
	
	while (hash_table[i].flag == 1) 
    {
 
		i = (i + 1) % table_capacity;
	
		if (i == ind) 
    	{
			printf("\n Hash table is full, cannot insert any more item. \n");
			return;
		}
 
    }
    
    nitm -> key = i;
	hash_table[i].flag = 1;
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
	    	printf("\n  %d \t|\t  %d ", tmp -> key, tmp -> value);
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
