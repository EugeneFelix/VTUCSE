import java.util.*;
public class Hamiltonian {
	static int adj[][] = new int[10][10];
	static int solution[] = new int[10];
	static int n;
	public void main(String args[]) {
		Scanner src = new Scanner(System.in);
		System.out.println("Enter the number of nodes");
		n = src.nextInt();
		solution[0] = 0;
		for (int i = 1; i < n; i++)
			solution[i] = -1;
		System.out.println("\nEnter the adjacency matrix");
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adj[i][j] = src.nextInt();
		HCycle(1);
	}


	public static void nextSafe(int k) {
		while (true) {
			solution[k] += 1;

			if (solution[k] == n)
				solution[k] = -1;

			if (solution[k] == -1)
				return;

			if (adj[    solution[k - 1]    ][  solution[k]   ] == 1) {
				int i;
				for (i = 0; i < k; i++)
					if (solution[i] == solution[k])
						break;
				if (i == k)
					if (k < n - 1 || (k == n - 1 && adj[solution[n - 1]][0] == 1))
						return;
			}
		}
	}
	public static void HCycle(int k) {
		while (true) {
			nextSafe(k);

			if (solution[k] == -1) return;

			if (k == n - 1)
				printSol();
			else
				HCycle(k + 1);
		}
	}
	public static void printSol() {
		System.out.println("\nSolution : ");
		for (int i = 0; i < n; i++)
			System.out.print((solution[i] + 1) + " -> ");
		System.out.println("1");
	}
}