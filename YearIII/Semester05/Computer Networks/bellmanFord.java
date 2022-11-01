import java.util.Scanner;
public class bellmanFord {
	public static final int MAX_VALUE = 999;
	public void bellmanFords(int s, int cost[][], int n, int distance[]) {
		for (int node = 1; node <= n; node++)
			distance[node] = MAX_VALUE;
		distance[s] = 0;
		for (int node = 1; node <= n - 1; node++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (cost[i][j] != MAX_VALUE)
						if (distance[j] > distance[i] + cost[i][j])
							distance[j] = distance[i] + cost[i][j];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (cost[i][j] != MAX_VALUE)
					if (distance[j] > distance[i] + cost[i][j])
						System.out.println("The Graph contains negative egde cycle");
		for (int vertex = 1; vertex <= n; vertex++)
			if (distance[vertex] < 0)
				System.out.println("Distance from " + s + " to " + vertex + " is: " + distance[vertex] + ". Negative edge");
			else
				System.out.println("Distance from " + s + " to " + vertex + " is: " + distance[vertex]);
	}

	public void main(String[] args) {
		int n = 0;
		int source;
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter the number of vertices:");
		n = scanner.nextInt();
		int cost[][] = new int[n + 1][n + 1];
		int[] distance= new int[n + 1];
		System.out.println("Enter the adjacency matrix:");
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				cost[i][j] = scanner.nextInt();
				if (i == j) {
					cost[i][j] = 0;
					continue;
				}
				if (cost[i][j] == 0)
					cost[i][j] = MAX_VALUE;
			}
		System.out.println("Enter the source vertex");
		source = scanner.nextInt();
		bellmanFord bell = new bellmanFord();
		bell.bellmanFords(source, cost, n , distance);
		scanner.close();
	}
}