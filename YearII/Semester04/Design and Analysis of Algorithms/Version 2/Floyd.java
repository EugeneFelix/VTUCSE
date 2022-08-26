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
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				a[i][j] = in.nextInt();
		//////CALL MR. FLOYD//////
						floyd(a, n);
		///////BID ADIEU TO MR. FLOYD//////
		System.out.println("All pair shortest path matrix:");
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++)
			  System.out.print(a[i][j] + "\t");
			System.out.println(" ");
		}
		in.close();
	}
	
	static void floyd(int d[][], int n) {
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
	}
}