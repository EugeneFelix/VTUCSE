package com.vtucse_iv;

import java.util.Random;
import java.util.Scanner;
class QuickSort {
  private int a[];
  public QuickSort(int[] a) {
    this.a = a;
  }
  public int partition(int a[], int m, int p) {
    int v = a[m];
    int i = m;
    int j = p;
    do {
      while (a[++i] < v);
      while (a[--j] > v);
      if (i < j)
        interchange(a, i, j);
    } while (i <= j);
    a[m] = a[j];
    a[j] = v;
    return j;
  }
  public void qSort(int p, int q) {
    int j;
    if (p < q) {
      j = partition(a, p, q + 1);
      qSort(p, j - 1);
      qSort(j + 1, q);
    }
  }
  public void interchange(int a[], int i, int j) {
    int t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
}
public class QuickSortDemo {
  public static void main(String[] args) {
    int n, a[], i;
    Scanner input = new Scanner(System.in);
    System.out.println("Enter the Size of an Array: ");
    n = input.nextInt();
    a = new int[n + 1];
    Random rn = new Random();
    System.out.println("System automatically generates numbers ");
    for (i = 0; i < n; ++i) {
      a[i] = rn.nextInt(n);
    }
    a[i] = 100000; //Sentinel value 
    QuickSort qSort = new QuickSort(a);
    System.out.println("Before Sort: ");
    for (i = 0; i < n; ++i) {
      System.out.print(a[i] + "\t");
    }
    int p = 0;
    int q = n - 1;
    qSort.qSort(p, q);
    System.out.println("\n\nAfter Sort: ");
    for (i = 0; i < n; ++i) {
      System.out.print(a[i] + "\t");
    }
    int step = 2000;
    double duration;
    /* times for n = 0, 10, ..., 100, 200, ..., 5000 */
    System.out.println("\n\nN\tRepetitions\tTime\n");
    for (n = 5000; n < 50000; n += step) {
      a = new int[n + 1];
      qSort = new QuickSort(a);
      /*get time for size n */
      long repetitions = 0;
      long start = System.nanoTime();
      do {
        repetitions++;
        for (i = 0; i < n; ++i) a[i] = rn.nextInt(n);
        a[i] = 100000; //Sentinel value qSort.qSort(0, n - 1);
      } while (System.nanoTime() - start < 1000000000); /* repeat until enough time has elapsed */
      duration = ((double)(System.nanoTime() - start)) / 1000000000;
      duration /= repetitions;
      System.out.println(n + "\t" + repetitions + "\t\t" + duration);
    }
  }
}