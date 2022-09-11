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
			System.out.print("  " + a[i]);
		System.out.println();
		start = System.nanoTime();

		mergesort(a, size);

		end = System.nanoTime();
		System.out.println("\tThe sorted elements are\n");
		for (int i = 0; i < size; i++)
			System.out.print("  " + a[i]);
		System.out.println();
		System.out.println("\nThe time taken to sort is " + (end - start) + "nS");
	}


	static void mergesort(int a[], int n) {
		if (n < 2)
			return;
		int mid = n / 2;
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
}