package com.vtucse_iv;

import java.util.Scanner;
public class Kruskals {
  static int parent[], cost[][], mincost, n, i, j, ne, a, b, min, u, v;
  public void kruskal(int n, int[][] cost) {
    ne = 1;
    while (ne < n) {
      min = 999;
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
          if (cost[i][j] < min) {
            min = cost[i][j];
            a = u = i;
            b = v = j;
          }
      }
      u = find(u);
      v = find(v);
      if (v != u) {
        System.out.println(ne + "edge(" + a + "," + b + ")=" + min);
        ne = ne + 1;
        mincost = mincost + min;
        uni(u, v);
      }
      cost[a][b] = cost[b][a] = 999;
    }
    System.out.println("The minimum cost of spanning tree is " + mincost);
  }
  public int find(int i) {
    while (parent[i] != 0) i = parent[i];
    return i;
  }
  public void uni(int i, int j) {
    parent[j] = i;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number of vertices\n");
    n = sc.nextInt();
    int cost[][] = new int[n + 1][n + 1];
    parent = new int[n + 1];
    System.out.println("Enter the cost matrix\n");
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        cost[i][j] = sc.nextInt();
        if (cost[i][j] == 0) cost[i][j] = 999;
      }
    }
    Kruskals k = new Kruskals();
    k.kruskal(n, cost);
  }
}