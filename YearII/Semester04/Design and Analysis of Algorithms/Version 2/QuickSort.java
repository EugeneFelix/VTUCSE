import java.util.Scanner;
import java.util.Random;
public class QuickSort {
	/*
	*Sir Tony Hoare in 1959
	* O(n²)/O(n logn)
	*/
	public void main(String[] args) {
		int a[] = new int[100000];
		int n, i;
		double start, end;
		Scanner in = new Scanner(System.in);
		System.out.println("\t\tEnter the size of the array");
		n = in.nextInt();
		Random rand = new Random();
		for (i = 0; i < n; i++)
			a[i] = rand.nextInt(1000);
		System.out.println("Array elements to be sorted are");
		for (i = 0; i < n; i++)
			System.out.print(a[i] + "\t");
		a[n] = 999;
		start = System.nanoTime();
		quicksort(a, 0, n - 1);
		end = System.nanoTime();
		System.out.println("\n\t\tThe sorted elements are");
		for (i = 0; i < n; i++)
			System.out.print(a[i] + "   ");
			double time = end - start;
			double ttime = time / 1_000_000_000;
		System.out.println("\n\t\the time taken to sort is " + time+ "ns or " + ttime + "s");
	}

	static void quicksort(int a[], int lx, int rx) {
		if (lx < rx) {
			int pidx = partition(a, lx, rx);
			quicksort(a, lx, pidx - 1);
			quicksort(a, pidx + 1, rx);
		}
	}
	static int partition(int a[], int l, int r) {
		int p = l;
		for (int j = l + 1; j <= r; j++)
			if (a[j] < a[l])
				swap(a, j, ++p);
		swap(a, l, p);
		return p;
	}
	static void swap(int a[], int i, int j) {
		int temp;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}