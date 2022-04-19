#include "stdio.h"
#include "stdlib.h"

int a[50][50], q[20], visited[20], reach[20], n, i, j;
int f = 0, r = -1, count = 0;

void bfs(int src) {
	for(i=1; i<n; i++)
      if(a[src][i] && !visited[i])
         q[++r] = i;
   if(f <= r) {
   	visited[q[f]] = 1;
   	bfs(q[f++]);
   }
}

void dfs(int src) {
	int i, reach[src] = 1;
}