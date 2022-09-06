import java.util.*;
public class Hamiltonian {
	static int adj[][] = new int[10][10];
	static int x[] = new int[10];
	static int n;
	public static void main(String args[]) {
		Scanner src = new Scanner(System.in);
		System.out.println("Enter the number of nodes");
		n = src.nextInt();
		x[0] = 0;
		for (int i = 1; i < n; i++)
			x[i] = -1;
		System.out.println("Enter the adjacency matrix");
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adj[i][j] = src.nextInt();
		getHCycle(1);
	}
	public static void nextValue(int k) {
		int i = 0;
		while (true) {
			x[k] += 1;
			if (x[k] == n)
				x[k] = -1;
			if (x[k] == -1)
				return;
			if (adj[x[k - 1]][x[k]] == 1)
				for (i = 0; i < k; i++)
					if (x[i] == x[k])
						break;
			if (i == k)
				if (k < n - 1 || k == n - 1 && adj[x[n - 1]][0] == 1)
					return;
		}
	}
	public static void getHCycle(int k) {
		while (true) {
			nextValue(k);
			if (x[k] == -1)
				return;
			if (k == n - 1) {
				System.out.println("\nSolution : ");
				for (int i = 0; i < n; i++)
					System.out.print((x[i] + 1) + " -> ");
				System.out.println("1");
			} else
				getHCycle(k + 1);
		}
	}
}