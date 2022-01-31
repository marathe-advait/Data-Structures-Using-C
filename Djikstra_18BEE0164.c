/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

#define V 6

int min(int dist[], bool shortest[])
{
	int min_dist = INT_MAX, min_index, v;
	int n;

	for (v = 0; v < V; v++)
	{
		if (shortest[v] == false && dist[v] <= min_dist)
		{
			min_dist = dist[v];
			min_index = v;
		}
	}
	
	return min_index;
}

void Solution(int dist[])
{
	printf(" Vertex \t\t Distance from Source\n");
	int i;
	for (i = 0; i < V; i++)
		printf(" %d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V], i, count, v;
	bool shortest[V];
	
	for (i = 0; i < V; i++)
		dist[i] = INT_MAX, shortest[i] = false;

	dist[src] = 0;
	
	for (count = 0; count < V - 1; count++) 
	{
		int u = min(dist, shortest);
		shortest[u] = true;

		for (v = 0; v < V; v++)
		{
			if (!shortest[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}	

	}
	
	Solution(dist);
}

int main()
{

	int graph[V][V] = { { 0, 4, 0, 0, 0, 8},
						{ 4, 0, 8, 0, 0, 11},
						{ 0, 8, 0, 2, 0, 0},
						{ 0, 0, 2, 0, 6, 7},
						{ 0, 0, 0, 6, 0, 1},
						{ 8, 11, 0, 7, 1, 0}};

	dijkstra(graph, 0);

	return 0;
}

