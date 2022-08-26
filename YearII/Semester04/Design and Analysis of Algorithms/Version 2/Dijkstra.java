import java.util.Scanner;

public class Dijkstra {
	public void main(String[] args) {
		int cost[][] = new int[10][10];
		Scanner in = new Scanner(System.in);
		System.out.println("**** DIJKSTRA'S ALGORITHM ******");
		System.out.println("Enter the number of nodes: ");
		int n = in.nextInt();
		System.out.println("Enter the cost matrix");
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cost[i][j] = in.nextInt();
		System.out.println("Enter the source vertex: ");
		int src = in.nextInt();
		in.close();
		dijkstras(cost, n, src);
	}
	/* $¢$¢$¢$¢$¢$¢$¢ End Main $¢$¢$¢$¢$¢$¢$¢$ */
	static void dijkstras(int cost[][], int n, int src) {
		int count = 0, temp = 0, min;
		int visited[] = new int[10];
		int sptSet[] = new int[10];
		for (int i = 1; i <= n; i++) // Initialise visited to 0.
			visited[i] = 0;
		for (int i = 1; i <= n; i++) // Initialise sptSet with all values from source to other vertices.
			sptSet[i] = cost[src][i];
		visited[src] = 1; //Source is visited already.
		sptSet[src] = 0; //Distance to itself is 0.
		count++; //Count including src is 1 now.
		while (count != n) { // While more vertices are present.
			min = 999;
			for (int i = 1; i <= n; i++)
				if (visited[i] == 0)
					if (sptSet[i] < min) { /* if edge exits */
						min = sptSet[i];
						temp = i;
					}
					
					
			{
				    visited[temp] = 1;
		    		count++;
			}
			
			
			
			for (int i = 1; i <= n; i++)
				if (visited[i] == 0)
					if (sptSet[i] > sptSet[temp] + cost[temp][i])
						sptSet[i] = sptSet[temp] + cost[temp][i];
		}
		
		
		
		System.out.println("The shortest distance between ");
		for (int i = 1; i <= n; i++) {
			System.out.println(src + "--->" + i + "=" + sptSet[i]);
		}
	}
}