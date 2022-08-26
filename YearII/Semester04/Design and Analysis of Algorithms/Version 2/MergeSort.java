import java.util.*;
public class MergeSort {
	public void main(String[] args) {
		int a[] = new int[100000];
		double start, end;
		Scanner in = new Scanner(System.in);
		System.out.println("enter the size of the array");
		int size = in.nextInt();
		Random rand = new Random();
		for (int i = 0; i < size; i++)
			a[i] = rand.nextInt(50);
		System.out.println("Array elements to be sorted are");
		for (int i = 0; i < size; i++)
			System.out.println("\t\t" + a[i] + "\t");
		start = System.nanoTime();
		////////call mergeSort()//////////
		mergesort(a, size);
		//////////////////////////////////////
		end = System.nanoTime();
		System.out.println("\nthe sorted elements are\n");
		for (int i = 0; i < size; i++)
			System.out.println("\t\t" + a[i] + "\t");
		System.out.println("\nthe time taken to sort is " + (end - start) + "nS");
		in.close();
	}


	static void mergesort(int a[], int n) {
		if (n < 2)
			return;
		int mid = n / 2;
		int left[] = new int[mid];
		int right[] = new int[n - mid];
		copy(a, 0, mid, left, 0);
		copy(a, mid, n, right, 0);
		mergesort(left, mid);
		mergesort(right, n - mid);
		merge(a, left, right, mid, n - mid);
	}
	static void merge(int a[], int left[], int right[],int r, int s) {
		int i, j, k;
		i = j = k = 0;
		while (i < r && j < s) {
			if (left[i] <= right[j]) {
				a[k] = left[i];
				i++;
			} else {
				a[k] = right[j];
				j++;
			}
			k++;
		}
		if (i == r)
			copy(right, j, s, a, k);
		else
			copy(left, i, r, a, k);
	}
	
	
	static void copy(int a[], int x, int y, int b[], int k) {
		while (x < y)
			b[k++] = a[x++];
	}
}