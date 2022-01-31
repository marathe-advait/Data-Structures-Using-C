/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define SIZE 40

struct queue 
{
	int items[SIZE];
	int front;
	int rear;
};

struct queue* Queue() 
{
	struct queue* q = malloc(sizeof(struct queue));
	q -> front = -1;
	q -> rear = -1;
	return q;
}

void enqueue(struct queue* q, int value) 
{
	if (q->rear == SIZE - 1)
		printf("\n Queue is Full !!");
	
	else 
	{
		if (q -> front == -1)
		q -> front = 0;
		q -> rear++;
		q -> items[q -> rear] = value;
	}
}

bool underflow(struct queue* q) 
{
	return (q -> rear == -1);
}

int dequeue(struct queue* q) 
{
	int item;
	if (underflow(q)) 
	{
		printf("\n Queue is empty");
		item = -1;
	} 
	else 
	{
		item = q -> items[q -> front];
		q -> front++;
		if (q -> front > q -> rear) 
		{
			printf("\n Resetting queue ");
			q -> front = q -> rear = -1;
		}
	}
	return item;
}

void display(struct queue* q) 
{
	int i = q -> front;
	
	if (underflow(q)) 
	{
		printf("\n Queue is empty");
	} 
	
	else 
	{
		printf("\n Queue contains - ");
		for (i = q -> front; i < q -> rear + 1; i++)
			printf(" %d ", q -> items[i]);
	}
  
}

struct node 
{
	int vertex;
	struct node* nxt;
};

struct node* Node(int v) 
{
	struct node* nitm = malloc(sizeof(struct node));
	nitm -> vertex = v;
	nitm -> nxt = NULL;
	return nitm;
}

struct graph 
{
	int vertices;
	struct node** adjacency_lists;
	int* visited;
};

struct graph* Graph(int vertices) 
{
	struct graph* nitm = malloc(sizeof(struct graph));
	nitm -> vertices = vertices;
	nitm -> adjacency_lists = malloc(vertices * sizeof(struct node*));
	nitm -> visited = malloc(vertices * sizeof(int));
	int i;
	for (i = 0; i < vertices; i++) 
	{
		nitm -> adjacency_lists[i] = NULL;
		nitm -> visited[i] = 0;
	}
	return nitm;
}

void Edge(struct graph* nitm, int src, int dest) 
{
	struct node* nn = Node(dest);
	nn -> nxt = nitm -> adjacency_lists[src];
	nitm -> adjacency_lists[src] = nn;
	nn= Node(src);
	nn -> nxt = nitm -> adjacency_lists[dest];
	nitm -> adjacency_lists[dest] = nn;
}

void breadth_first_search(struct graph* nitm, int start) 
{
  	struct queue* q = Queue();

  	nitm -> visited[start] = 1;
  	enqueue(q, start);

  	while (!underflow(q)) 
  	{
    	display(q);
    	int current = dequeue(q);
    	printf("\n Visited %d ", current);
		
    	struct node* tmp = nitm -> adjacency_lists[current];
		
    	while (tmp) 
		{
			int adjacent = tmp -> vertex;
		
			if (nitm -> visited[adjacent] == 0) 
			{
				nitm -> visited[adjacent] = 1;
				enqueue(q, adjacent);
			}
      
	  	tmp = tmp -> nxt;
    	}
  	}
}

int main() 
{
	struct graph* nitm = Graph(6);
	Edge(nitm, 0, 1);
	Edge(nitm, 0, 2);
	Edge(nitm, 0, 3);
	Edge(nitm, 1, 2);
	Edge(nitm, 2, 4);
	
	breadth_first_search(nitm, 0);
	return 0;
}
