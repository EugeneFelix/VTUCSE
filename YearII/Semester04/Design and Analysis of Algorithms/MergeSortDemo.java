package com.vtucse_iv;

import java.util.Random;
import java.util.Scanner;


class MergeSort {
  private int a[];
  public MergeSort(int[] a) {
    this.a = a;
  }
  void merge(int low, int mid, int high) {
    int b[] = new int[high + 1];
    int h = low;
    int i = low;
    int j = mid + 1;
    int k;
    while ((h <= mid) && (j <= high)) {
      if (a[h] <= a[j]) b[i++] = a[h++];
      else b[i++] = a[j++];
    }
    if (h > mid) {
      for (k = j; k <= high; ++k) b[i++] = a[k];
    } else {
      for (k = h; k <= mid; ++k) b[i++] = a[k];
    }
    for (k = low; k <= high; ++k) a[k] = b[k];
  }
  void mergeSort(int low, int high) {
    int mid;
    if (low < high) {
      mid = (low + high) / 2;
      mergeSort(low, mid);
      mergeSort(mid + 1, high);
      merge(low, mid, high);
    }
  }
}
public class MergeSortDemo {
  public static void main(String[] args) {
    int n, a[], i;
    Scanner input = new Scanner(System.in);
    System.out.println("Enter the Size of an Array: ");
    n = input.nextInt();
    a = new int[n + 1];
    Random rn = new Random();
    System.out.println("System automatically generates numbers ");
    for (i = 0; i < n; ++i) {
      a[i] = rn.nextInt(n); //a[i] = input.nextInt(); 
    }
    a[i] = 100000; //Sentinel value 
    MergeSort mSort = new MergeSort(a);
    System.out.println("Before Sort: ");
    for (i = 0; i < n; ++i) {
      System.out.print(a[i] + "\t");
    }
    int low = 0;
    int high = n - 1;
    mSort.mergeSort(low, high);
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
      mSort = new MergeSort(a);
      /*get time for size n */
      long repetitions = 0;
      long start = System.nanoTime();
      do {
        repetitions++;
        for (i = 0; i < n; ++i) a[i] = rn.nextInt(n);
        a[i] = 100000; //Sentinel value 
        mSort.mergeSort(0, n - 1);
      } while (System.nanoTime() - start < 1000000000); /* repeat until enough time has elapsed */
      duration = ((double)(System.nanoTime() - start)) / 1000000000;
      duration /= repetitions;
      System.out.println(n + "\t" + repetitions + "\t\t" + duration);
    }
  }
}