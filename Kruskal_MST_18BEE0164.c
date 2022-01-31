/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct edge 
{
	int src, dest, weight;
};

struct graph 
{
	int V, E;
	struct edge* e;
};

struct graph* Graph(int V, int E)
{
	struct graph* nitm = (struct graph*) (malloc(sizeof(struct graph)));
	nitm -> V = V;
	nitm -> E = E;
	nitm -> e = (struct edge*) malloc(sizeof(struct edge) * E);
	return nitm;
}

struct subset 
{
	int parent;
	int rank;
};

int find(struct subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
	int x_root = find(subsets, x);
	int y_root = find(subsets, y);

	if (subsets[x_root].rank < subsets[y_root].rank)
		subsets[x_root].parent = y_root;
	
	else if (subsets[x_root].rank > subsets[y_root].rank)
		subsets[y_root].parent = x_root;

	else
	{
		subsets[y_root].parent = x_root;
		subsets[x_root].rank++;
	}
}

int comp(const void* a, const void* b)
{
	struct edge* a_edge = (struct edge*) a;
	struct edge* b_edge = (struct edge*) b;
	return a_edge -> weight > b_edge -> weight;
}

void kruskal(struct graph* nitm)
{
	int V = nitm -> V;
	struct edge result[V];
	int number_of_edges = 0;
	int i = 0, v; 
	
	qsort(nitm -> e, nitm -> E, sizeof(nitm -> e[0]), comp);

	struct subset* subsets = (struct subset*) malloc(V * sizeof(struct subset));

	for (v = 0; v < V; ++v) 
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while (number_of_edges < V - 1 && i < nitm -> E) 
	{
		struct edge next_edge = nitm -> e[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		if (x != y) 
		{
			result[number_of_edges ++] = next_edge;
			Union(subsets, x, y);
		}
	}

	printf("\n Following are the edges in the constructed MST - \n");
	printf("\n Edge \t\t\t Weight \n");
	int mincost = 0;
	
	for (i = 0; i < number_of_edges; ++i)
	{
		printf(" %c - %c  \t\t %d \n", result[i].src + 65, result[i].dest + 65, result[i].weight);
		mincost += result[i].weight;
	}
	
	printf("\n Minimum Cost Spanning tree - %d",mincost);
	return;
}

int main()
{
	int V = 7;
	int E = 11;
	struct graph* nitm = Graph(V, E);

	nitm -> e[0].src = 0;
	nitm -> e[0].dest = 1;
	nitm -> e[0].weight = 1;
	
	nitm -> e[1].src = 0;
	nitm -> e[1].dest = 2;
	nitm -> e[1].weight = 4;

	nitm -> e[2].src = 1;
	nitm -> e[2].dest = 3;
	nitm -> e[2].weight = 3;

	nitm -> e[3].src = 1;
	nitm -> e[3].dest = 4;
	nitm -> e[3].weight = 6;

	nitm -> e[4].src = 2;
	nitm -> e[4].dest = 3;
	nitm -> e[4].weight = 2;
	
	nitm -> e[5].src = 2;
	nitm -> e[5].dest = 5;
	nitm -> e[5].weight = 5;
	
	nitm -> e[6].src = 3;
	nitm -> e[6].dest = 4;
	nitm -> e[6].weight = 2;
	
	nitm -> e[7].src = 3;
	nitm -> e[7].dest = 5;
	nitm -> e[7].weight = 4;
	
	nitm -> e[8].src = 4;
	nitm -> e[8].dest = 5;
	nitm -> e[8].weight = 2;
	
	nitm -> e[9].src = 4;
	nitm -> e[9].dest = 6;
	nitm -> e[9].weight = 7;
	
	nitm -> e[10].src = 5;
	nitm -> e[10].dest = 6;
	nitm -> e[10].weight = 6;
	
	printf("\n ***** NAME - ADVAIT MARATHE *****\n");
	printf("\n ***** REG -  18BEE0164      *****\n");
	printf("\n ***** KRUSKAL'S ALGORITHM   *****\n");
	kruskal(nitm);
	return 0;
}
