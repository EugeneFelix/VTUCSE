import java.util.Scanner;
public class KnapsackDynamic {
	public static void main(String... args) {
		int p[] = new int[10];
		int w[] = new int[10];
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the no of items");
		int n = in.nextInt();
		System.out.println("*****WEIGHTS*****");
		for (int i = 1; i <= n; i++) {
			System.out.println("Enter the weight of item " + i);
			w[i] = in.nextInt();
		}
		System.out.println("*****PROFITS*****");
		for (int i = 1; i <= n; i++) {
			System.out.println("Enter the profit of item " + i);
			p[i] = in.nextInt();
		}
		System.out.println("Enter the knapsack capacity");
		int capacity = in.nextInt();
		knapsack(p, w, capacity, n);
	}



	static void knapsack(int p[], int w[], int capacity, int n) {
		int i, j;
		int solution[][] = new int[10][10];
		int x[] = new int[10];
		for (i = 1; i <= n; i++)
			for (j = 1; j <= capacity; j++)
				if (i == 0 || j == 0)
					solution[i][j] = 0;
				else if ((j - w[i]) < 0)
					solution[i][j] = solution[i - 1][j];
				else
					solution[i][j] = Math.max(solution[i - 1][j], solution[i - 1][   j - w[i]   ] + p[i]);
		System.out.println("Knapsack Solution");
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= capacity; j++)
				System.out.print(solution[i][j] + "\t");
			System.out.print("\n");
		}
		System.out.println("The maximum profit is " + solution[n][capacity]);
		i = n;
		j = capacity;
		while (i != 0 && j != 0) {
			if (solution[i][j] != solution[i - 1][j]) {
				x[i] = 1;
				j -= w[i];
			}
			i--;
		}
		System.out.println("Selected items are: ");
		for (i = 1; i <= n; i++)
			if (x[i] == 1)
				System.out.print(i + " ");
	}
}