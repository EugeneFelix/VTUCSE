import java.util.Scanner;

public class Kruskal {
	public void main(String[] args) {
		int c[][] = new int[10][10];
		int i, j, mincost = 0;
		Scanner in = new Scanner(System.in);
		System.out.println("********* KRUSKAL'S ALGORITHM *******");
		System.out.println("Enter the number of nodes: ");
		int n = in.nextInt();
		System.out.println("Enter the cost matrix");
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				c[i][j] = in.nextInt();
			}
		}
		System.out.println("The minimum spanning tree cost is: ");
		kruskal(c, n);
	}
	static void kruskal(int c[][], int n) {
		int ne, mincost;
		int a = 0, b = 0, v = 0, u = 0, i, j, min;
		int parent[] = new int[10];
		ne = 0;
		mincost = 0;
		for (i = 1; i <= n; i++)
			parent[i] = 0;
		while (ne != (n - 1)) {
			min = 999;
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					if (c[i][j] < min) {
						min = c[i][j];
						v = i;
						u = j;
						a = i;
						b = j;
					}
			while (parent[v] != 0)
				v = parent[v];
			while (parent[u] != 0)
				u = parent[u];
			if (v != u) {
				ne += 1;
				mincost += min;
				parent[u] = v;
				System.out.println(a + "--->" + b + "=" + min);
			}
			c[a][b] = c[b][a] = 999;
		}
		System.out.println("Mincost = " + mincost);
	}
}