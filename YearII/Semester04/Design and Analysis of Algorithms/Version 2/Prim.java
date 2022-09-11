import java.util.Scanner;

public class Prim {
	public void main(String[] args) {
		int c[][] = new int[10][10];
		Scanner in = new Scanner(System.in);
		System.out.println("********* PRIMS ALGORITHM *********");
		System.out.println("Enter the number of nodes");
		int n = in.nextInt();
		System.out.println("Enter the cost matrix");
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				c[i][j] = in.nextInt();
		System.out.println("Minimum Spanning Tree Edges and costs are");
		djp(c, n);
	}
	static void djp(int c[][], int n) {
		int count = 0, totalCost = 0, u = 0, v = 0;
		boolean isVisited[] = new boolean[10];
		for (int i = 1; i <= n; i++)
			isVisited[i] = false;
		/////////SAME AS KRUSKAL/////////
		isVisited[1] = true;
		while (count != (n - 1)) {
			int min = 999;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (isVisited[i])
						if (c[i][j] < min) {
							min = c[i][j];
							v = i;
							u = j;
							}
			if (!isVisited[u]) {
				isVisited[u] = true;
				totalCost += min;
				System.out.println(u + "--->" + v + "=" + min);
				count++;
			}
			c[u][v] = c[v][u] = 999;
		}
		System.out.println("Minimum cost is " + totalCost);
	}
}