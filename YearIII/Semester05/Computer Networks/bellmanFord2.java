class bellmanFord2 {
	static void BellmanFord(int graph[][], int V, int E, int src) {
		int memo[] = new int[V];
		for (int i = 0; i < V; i++)
			memo[i] = Integer.MAX_VALUE;
		memo[src] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (int j = 0; j < E; j++) {
				if (memo[graph[j][0]] != Integer.MAX_VALUE && memo[graph[j][0]] + graph[j][2] < memo[graph[j][1]])
					memo[graph[j][1]] = memo[graph[j][0]] + graph[j][2];
			}
		}
		for (int i = 0; i < E; i++) {
			int x = graph[i][0];
			int y = graph[i][1];
			int weight = graph[i][2];
			if (memo[x] != Integer.MAX_VALUE &&
					memo[x] + weight < memo[y])
				System.out.println("Graph contains negative"
								   + " weight cycle");
		}

		System.out.println("Vertex Distance from Source");
		for (int i = 0; i < V; i++)
			System.out.println(i + "\t\t" + memo[i]);
	}

	public void main(String[] args) {
		int V = 5;
		int E = 8;
		int graph[][] = { { 0, 1, -1 }, { 0, 2, 4 },
			{ 1, 2, 3 }, { 1, 3, 2 },
			{ 1, 4, 2 }, { 3, 2, 5 },
			{ 3, 1, 1 }, { 4, 3, -3 }
		};
		BellmanFord(graph, V, E, 0);
	}
}