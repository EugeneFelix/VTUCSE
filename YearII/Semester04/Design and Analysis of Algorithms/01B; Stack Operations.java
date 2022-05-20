package com.vtucse_iv;

import java.util.Scanner;

public class StackDemo {
  public static void main(String[] args) {
    int top = -1;
    int n, element, i;
    int[] a;
    Scanner s = new Scanner(System.in);
    System.out.println("Enter Stack Size");
    n = s.nextInt();
    a = new int[n + 1];
    System.out.println("Stack operations are" + "\t" + "1.Push" + "\t" + "2.POP" + "\t" +
      "3.Display" + "\t" + "4.Exit");
    for (;;) {
      System.out.println("Enter your choice");
      int choice = s.nextInt();
      switch (choice) {
      case 1:
        if (top == n - 1) {
          System.out.println("Stack overflow");
        } else {
          System.out.println("Enter element to be pushed");
          element = s.nextInt();
          a[top++] = element;
        }
        break;
      case 2:
        if (top == -1) {
          System.out.println("Stack Underflow");
        } else {
          System.out.println("Popped element " + a[top--]);
        }
        break;
      case 3:
        if (top == -1) {
          System.out.println("Stack Empty");
        } else {
          System.out.println("Elements in stack :");
          for (i = top; i >= 0; i--) {
            System.out.println(a[i]);
          }
        }
        break;
      case 4:
        System.exit(0);
        break;
      }
    }
  }
}