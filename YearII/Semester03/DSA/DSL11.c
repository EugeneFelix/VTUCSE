#include "stdio.h"
#include "stdlib.h"
int a[10][10], start, visited1[10], visited2[10], n;

void create()
{
	int i, j;
	printf("Enter the Number of vertices:\n");
	scanf("%d", &n);
	printf("Enter the adjacency vertices \n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
}
void bfs(int start)
{
	int queue[10], f = 0, r = -1, i, j;
	visited1[start] = 1;
	queue[++r] = start;
	printf("Nodes reachable are \n");
	while (f <= r)
	{
		i = queue[f];
		f++;
		printf("%d\t", i);
		for (j = 1; j <= n; j++)
		{
			if (a[i][j] == 1 && visited1[j] == 0)
			{
				visited1[j] = 1;
				queue[++r] = j;
			}
		}
	}
	printf("\n Vertices are not reachable \n");
	for (i = 1; i <= n; i++)
	{
		if (visited1[i] == 0)
		{
			printf("%d\t", i);
		}
		visited1[i] = 0;
	}
}
void dfs(int start)
{
	int j;
	visited2[start] = 1;
	for (j = 1; j <= n; j++)
	{
		if (a[start][j] == 1 && visited2[j] == 0)
		{
			printf("%d------->%d\n", start, j);
			dfs(j);
		}
	}
}


int main()
{
	int i;
	int ch;
	while (1)
	{
		printf("\n\t1.Create\n\t 2.BFS\n\t 3.DFS\n\t 4.Exit \n");
		printf("Enter your choice ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			create();
			break;
		case 2:
			printf("BFS Traverasl\n");
			printf("Enter the source Vertices:\n");
			scanf("%d", &start);
			bfs(start);
			break;
		case 3:
			printf("DFS Traversal\n");
			printf("Enter the source Vertices:\n");
			scanf("%d", &start);
			dfs(start);
			for (i = 1; i <= n; i++)
			{
				if (visited2[i] == 0)
				{
					printf("Graph is not connected\n");
					exit(0);
				}
			}
			printf("Graph is connected \n");
			break;
		case 4:
			exit(0);
		default:
			printf("Invalid Option !!\n");
		}
	}
}
