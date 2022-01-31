/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

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

void depth_first_search(struct graph* nitm, int vertex) 
{
	struct node* adj = nitm -> adjacency_lists[vertex];
	struct node* tmp = adj;
	nitm -> visited[vertex] = 1;
	printf("\n Visited %d \n", vertex);
	
	while (tmp != NULL) 
	{
		int connected = tmp -> vertex;
		if (nitm -> visited[connected] == 0) 
		{
			depth_first_search(nitm, connected);
		}
    	tmp = tmp->nxt;
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
	
	depth_first_search(nitm, 0);
	return 0;
}
