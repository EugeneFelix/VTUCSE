import java.util.Scanner;

public class Dijkstra {
	public void main(String[] args) {
		int cost[][] = new int[10][10];
		Scanner in = new Scanner(System.in);
		System.out.println("\t\t******* DIJKSTRA'S ALGORITHM ******");
		System.out.println("Enter the number of nodes: ");
		int n = in.nextInt();
		System.out.println("Enter the cost matrix");
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cost[i][j] = in.nextInt();
		System.out.println("Enter the source vertex: ");
		int src = in.nextInt();
		dijkstras(cost, n, src);
	}
	static void dijkstras(int cost[][], int n, int src) {
		int count = 0, temp = 0, min;
		boolean visited[] = new boolean[10];
		int sptSet[] = new int[10];
		for (int i = 1; i <= n; i++)
			visited[i] = false;
		for (int i = 1; i <= n; i++)
			sptSet[i] = cost[src][i];
		for (int i = 1; i <=n; i++)
			System.out.print(sptSet[i] + "  ");
		visited[src] = true;
		sptSet[src] = 0;
		count++;
		while (count != n) {
			min = 999;
			for (int i = 1; i <= n; i++)
				if (visited[i] == false)
					if (sptSet[i] < min) {
						min = sptSet[i];
						temp = i;
					}
			visited[temp] = true;
			count++;
			for (int i = 1; i <= n; i++)
				if (visited[i] == false)
					if (sptSet[i] > sptSet[temp] + cost[temp][i])
						sptSet[i] = sptSet[temp] + cost[temp][i];
		}
		System.out.println("The shortest distance between ");
		for (int i = 1; i <= n; i++) {
			System.out.println(src + " ---> " + i + " is " + sptSet[i]);
		}
	}
}