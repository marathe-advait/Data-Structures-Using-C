/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 7

int min(int key[], bool mst[])
{
	int min = INT_MAX, min_index, v;

	for (v = 0; v < V; v++)
		if (mst[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

int MST(int parent[], int graph[V][V])
{
	printf("Edge \tWeight\n");
	int i;
	for (i = 1; i < V; i++)
		printf("%d - %d \t%d \n", parent[i] + 1, i + 1, graph[i][parent[i]]);
}

void prim(int graph[V][V])
{
	int parent[V], key[V], i, count;
	bool mst[V];

	for (i = 0; i < V; i++)
		key[i] = INT_MAX, mst[i] = false;

	key[0] = 0, parent[0] = -1;

	for (count = 0; count < V - 1; count++) 
	{
		int u = min(key, mst);
		mst[u] = true;
		int v;

		for (v = 0; v < V; v++)
		{
			if (graph[u][v] && mst[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
		}
	}
	
	MST(parent, graph);
}

int main()
{
	int graph[V][V] = { { 00, 28, 00, 00, 00, 10, 00},
						{ 28, 00, 16, 00, 00, 00, 14},
						{ 00, 16, 00, 12, 00, 00, 00},
						{ 00, 00, 12, 00, 22, 00, 18},
						{ 00, 00, 00, 22, 00, 25, 24}, 
						{ 10, 00, 00, 00, 25, 00, 00},
						{ 00, 14, 00, 18, 24, 00, 00} };

	prim(graph);
	return 0;
}
