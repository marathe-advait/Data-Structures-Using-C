/*	Name - Advait Marathe
	Reg - 18BEE0164			*/

#include<stdio.h>
#define V 4
#define INF 99999

void Solution(int dist[][V])
{
	printf ("\n The following matrix shows the shortest distances between every pair of vertices - \n");
	int i, j;
	
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				printf(" %7s ", "INF");
			else
				printf (" %7d ", dist[i][j]);
		}
		printf("\n");
	}
}

void floyd_warshall (int graph[][V])
{
	int dist[V][V], i, j, k;

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];
	}

	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	
	Solution(dist);
}

int main()
{
	int graph[V][V] = { {0, 9, -4, INF},
						{6, 0, INF, 2},
						{INF, 5, 0, INF},
						{INF, INF, 1, 0} };

	floyd_warshall(graph);
	return 0;
}

