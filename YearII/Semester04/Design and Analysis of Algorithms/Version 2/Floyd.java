import java.util.Scanner;
public class Floyd {
	public void main(String[] args) {
		int a[][] = new int[10][10];
		int i, j, n;
		Scanner in = new Scanner(System.in);
		System.out.println("***********FLOYD'SALGORITHM**********");
		System.out.println("Enter the number of vertices: ");
		n = in.nextInt();
		System.out.println("Enter the adjacency matrix");
		for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) a[i][j] = in.nextInt();
		floyd(a, n);
		System.out.println("All pair shortest path matrix:");
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) System.out.print(a[i][j] + "\t");
			System.out.println();
		}
	} static void floyd(int d[][], int n) {
		int i, j, k;
		for (k = 1; k <= n; k++) {
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	} static int min(int a, int b) {
		if (a < b) {
			return a;
		} else {
			return b;
		}
	}
}