#include "stdio.h"
#include "stdlib.h"
int adjMat[10][10], start, bfsDone[10], dfsDone[10], n;

void create()
{
	int i, j;
	printf("Enter the Number of vertices:\n");
	scanf("\t%d", &n);
	printf("Enter the adjacency vertices \n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &adjMat[i][j]);
		}
	}
}


void bfs(int start)
{
	int queue[10], f = 0, r = -1, i, j;
	bfsDone[start] = 1;
	queue[++r] = start;
	printf("Nodes reachable are \n");
	while (f <= r)
	{
		i = queue[f];
		f++;
		printf("%d\t", i);
		for (j = 1; j <= n; j++)
		{
			if (adjMat[i][j] == 1 && !bfsDone[j])
			{
				bfsDone[j] = 1;
				queue[++r] = j;
			}
		}
	}
	printf("\n Vertices are not reachable \n");
	for (i = 1; i <= n; i++)
	{
		if (bfsDone[i] == 0)
		{
			printf("%d\t", i);
		}
		bfsDone[i] = 0;
	}
}


void dfs(int start)
{
	int j;
	dfsDone[start] = 1;
	for (j = 1; j <= n; j++)
	{
		if (adjMat[start][j] == 1 && dfsDone[j] == 0)
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
				if (dfsDone[i] == 0)
				{
					printf("Graph is not connected\n");
					exit(0);
				}
			}
			printf("Graph is connected \n");
			break;
		case 4:
			printf("\nSad to see you go, Have a good one!\n");
			exit(EXIT_SUCCESS);
		default:
			printf("Invalid Option !!\n");
		}
	}
}
