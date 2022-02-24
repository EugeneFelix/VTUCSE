package com.vtucse_iv;

import java.util.*;
public class Floyds {
  static int n, i, j, k;
  public void floyd(int n, int[][] cost) {
    for (k = 1; k <= n; k++) {
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
          cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        }
      }
    }
    System.out.println("all pair shortest paths matrix \n");
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        System.out.print(cost[i][j] + " ");
      }
      System.out.println();
    }
  }
  public int min(int i, int j) {
    if (i < j) return i;
    else return j;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Eneter the no of vertices\n");
    n = sc.nextInt();
    int cost[][] = new int[n + 1][n + 1];
    System.out.println("Enter the cost matrix:");
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) cost[i][j] = sc.nextInt();
    Floyds f = new Floyds();
    f.floyd(n, cost);
  }
}