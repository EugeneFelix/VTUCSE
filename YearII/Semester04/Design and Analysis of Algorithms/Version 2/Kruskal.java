import java.util.Scanner;

public class Kruskal {
	public void main(String[] args) {
		int c[][] = new int[10][10];
		Scanner in = new Scanner(System.in);
		System.out.println("********* KRUSKAL'S ALGORITHM *******");
		System.out.println("Enter the number of nodes: ");
		int n = in.nextInt();
		System.out.println("Enter the cost matrix");
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				c[i][j] = in.nextInt();
		System.out.println("Minimum Spanning Tree and Edge costs are");
		kruskal(c, n);
	}
	static void kruskal(int c[][], int n) {
		int v = 0, a = 0, u = 0, b = 0, edgeCount = 0, mincost = 0;
		int parent[] = new int[10];
		for (int i = 1; i <= n; i++)
			parent[i] = 0;
		///////// SAME AS PRIM/////////
		while (edgeCount != (n - 1)) {
			int min = 999;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (c[i][j] < min) {
						min = c[i][j];
						v = a = i;
						u = b = j;
					}
			while (parent[v] != 0)
				v = parent[v];
			while (parent[u] != 0)
				u = parent[u];
			if (v != u) {
				edgeCount += 1;
				mincost += min;
				parent[u] = v;
				System.out.println(a + " --->" + b + "=" + min);
			}
			c[a][b] = c[b][a] = 999;
		}
		System.out.println("Mincost = " + mincost);
	}
}