package com.vtucse_iv;

import java.util.Scanner;
public class Tsp {
  static int cost[][];
  public int tsp(int[] path, int start, int n) {
    int i, j, k, ccost;
    int[] mintour = new int[n + 1];
    int[] temp = new int[n + 1];
    if (start == n - 1) return cost[path[n - 1]][path[n]] + cost[path[n]][1];
    int mincost = 999;
    for (i = start + 1; i <= n; i++) {
      for (j = 1; j <= n; j++) temp[j] = path[j];
      temp[start + 1] = path[i];
      temp[i] = path[start + 1];
      if (cost[path[start]][path[i]] + (ccost = tsp(temp, start + 1, n)) < mincost) {
        mincost = cost[path[start]][path[i]] + ccost;
        for (k = 1; k <= n; k++) mintour[k] = temp[k];
      }
    }
    for (i = 1; i <= n; i++) path[i] = mintour[i];
    return mincost;
  }
  public static void main(String[] args) {
    int mincost, n, i, j;
    Scanner s = new Scanner(System.in);
    System.out.println("enter the no of cities");
    n = s.nextInt();
    int path[] = new int[n + 1];
    cost = new int[n + 1][n + 1];
    System.out.println("Enter the cost matrix");
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) cost[i][j] = s.nextInt();
    for (i = 1; i <= n; i++) path[i] = i;
    Tsp obj = new Tsp();
    mincost = obj.tsp(path, 1, n);
    System.out.println("tsp tour");
    for (i = 1; i <= n; i++) System.out.print(path[i] + "--->");
    System.out.println("1");
    System.out.println("Tourcost=" + mincost);
  }
}