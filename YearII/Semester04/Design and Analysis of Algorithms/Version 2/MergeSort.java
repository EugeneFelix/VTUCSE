import java.util.Scanner;
import java.util.Random;
public class MergeSort {
	public void main(String[] args) {
		int a[] = new int[100000];
		double start, end;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the size of the array");
		int size = in.nextInt();
		Random rand = new Random();
		for (int i = 0; i < size; i++)
			a[i] = rand.nextInt(500);
		System.out.println("Array elements to be sorted are");
		for (int i = 0; i < size; i++)
			System.out.println("\t\t" + a[i] + "\t");
		start = System.nanoTime();
		
		mergesort(a, size);
		
		end = System.nanoTime();
		System.out.println("\tThe sorted elements are\n");
		for (int i = 0; i < size; i++)
			System.out.println("\t\t" + a[i]);
		System.out.println("\nthe time taken to sort is " + (end - start) + "nS");
		in.close();
	}


	static void mergesort(int a[], int n) {
		if (n < 2) //base case.
			return;
		int mid = n / 2;
		System.out.println("Mid is " + mid);
		int left[] = new int[mid];
		int right[] = new int[n - mid];
		for (int i = 0; i < mid; i++)
			left[i] = a[i];
		for (int i = mid; i < n; i++)
			right[i - mid] = a[i];
		mergesort(left, mid);
		mergesort(right, n - mid);
		merge(a, left, right, mid, n - mid);
	}



	static void merge(int a[], int left[], int right[], int r, int s) {
		int i = 0, j = 0, k = 0;
		while (i < r && j < s)
			if (left[i] <= right[j])
				a[k++] = left[i++];
			else
				a[k++] = right[j++];
		while (i < r)
			a[k++] = left[i++];
		while (j < s)
			a[k++] = right[j++];
	}


	static void copy(int a[], int x, int y, int b[], int k) {
		while (x < y) {
			b[k++] = a[x++];
		}
	}
}