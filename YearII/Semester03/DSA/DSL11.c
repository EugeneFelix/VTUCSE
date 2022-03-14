#include "stdio.h"
#include "stdlib.h"
int a[10][10], src, visited1[10], visited2[10], n;
void create();
void bfs(int);
void dfs(int);
void check();
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
			scanf("%d", &src);
			bfs(src);
			break;
		case 3:
			printf("DFS Traversal\n");
			printf("Enter the source Vertices:\n");
			scanf("%d", &src);
			dfs(src);
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
void bfs(int src)
{
	int q[10], f = 0, r = -1, i, j;
	visited1[src] = 1;
	q[++r] = src;
	printf("Nodes reachable are \n");
	while (f <= r)
	{
		i = q[f];
		f++;
		printf("%d\t", i);
		for (j = 1; j <= n; j++)
		{
			if (a[i][j] == 1 && visited1[j] == 0)
			{
				visited1[j] = 1;
				q[++r] = j;
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
void dfs(int src)
{
	int j;
	visited2[src] = 1;
	for (j = 1; j <= n; j++)
	{
		if (a[src][j] == 1 && visited2[j] == 0)
		{
			printf("%d------->%d\n", src, j);
			dfs(j);
		}
	}
}