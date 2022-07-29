import java.util.*;
public class QuickSort {
	public void main(String[] args) {
		int a[] = new int[100000];
		int n, i;
		double start, end;
		Scanner in = new Scanner(System.in);
		System.out.println("\t\tEnter the size of the array");
		n = in.nextInt();
		Random rand = new Random();
		for (i = 0; i < n; i++)
			a[i] = rand.nextInt(100);
		System.out.println("Array elements to be sorted are");
		for (i = 0; i < n; i++) {
			System.out.print(a[i] + "\t");
		}
		a[n] = 999;
		start = System.nanoTime();
		quicksort(a, 0, n - 1);
		end = System.nanoTime();
		System.out.println("\n\t\tThe sorted elements are");
		for (i = 0; i < n; i++)
			System.out.print(a[i] + "\t");
		System.out.println("\n\t\the time taken to sort is " + (end - start) + "ns");
	}


	static void quicksort(int a[], int l, int r) {
		if (l < r) {
			int s = partition(a, l, r);
			quicksort(a, l, s - 1);
			quicksort(a, s + 1, r);
		}
	}


	static int partition(int a[], int l, int r) {
		int p, i, j;
		i = l + 1;
		j = r;
		p = a[l];
		while (i <= j) {
			while (a[i] <= p) i++;
			while (a[j] > p) j--;
			if (i < j)
				swap(a, i, j);
		}
		swap(a, l, j);
		return j;
	}

	static void swap(int a[], int i, int j) {
		int temp;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}