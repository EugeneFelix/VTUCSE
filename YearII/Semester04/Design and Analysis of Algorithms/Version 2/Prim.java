import java.util.Scanner;
public class Prim {
	static final int INF = 9999;
	public void main(String[] args) {
		int c[][] = new int[10][10];
		int i, j;
		Scanner in = new Scanner(System.in);
		System.out.println("********* PRIMS ALGORITHM *********");
		System.out.println("Enter the number of nodes");
		int n = in.nextInt();
		System.out.println("Enter the cost matrix");
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				c[i][j] = in.nextInt();
			}
		}
		System.out.println("Minimum Spanning Tree Edges and costs are");
		djp(c, n);
	}
	
	static void djp(int c[][], int n) {
		int ne = 0, mincost = 0;
		int v = 0, u = 0, i, j, min;
		int visited[] = new int[10];
		for (i = 1; i <= n; i++)
			visited[i] = 0;
		visited[1] = 1;
		//////WAIT A WHILE///////
		while (ne != (n - 1)) {
			min = INF;
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					if (visited[i] == 1) {
						if (c[i][j] < min) {
							min = c[i][j];
							u = j;
							v = i;
						}
					}
				}
			}
			if (visited[u] == 0) {
				visited[u] = 1;
				ne = ne + 1;
				mincost = mincost + min;
				System.out.println(u + "--->" + v + "=" + min);
			}
			c[u][v] = c[v][u] = INF;
		}
		//////END A WHILE//////
		System.out.println("Minimum cost is " + mincost);
	}
}