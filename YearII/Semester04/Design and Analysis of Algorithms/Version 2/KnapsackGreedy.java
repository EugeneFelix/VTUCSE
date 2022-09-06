import java.util.*;
public class KnapsackGreedy {
	public void main(String[] args) {
		int n, capacity, i;
		float r[] = new float[10];
		float p[] = new float[10];
		float w[] = new float[10];
		Scanner in = new Scanner(System.in);
		System.out.println("\t\tEnter the number of items");
		n = in.nextInt();
		System.out.println("*****WEIGHTS*****");
		for (i = 1; i <= n; i++)
			w[i] = in.nextFloat();
		System.out.println("*****PROFITS*****");
		for (i = 1; i <= n; i++)
			p[i] = in.nextFloat();
		System.out.println("\t\tEnter the knapsack capacity");
		capacity = in.nextInt();
		
		// Create ratio array.
		for (i = 1; i <= n; i++)
			r[i] = p[i] / w[i];
			
		System.out.println("\t\tBefore sorting");
		displayinfo(n, w, p, r);
		
		sortratio(n, w, p, r);
		
		System.out.println("\t\tAfter sorting");
		displayinfo(n, w, p, r);
		//Call him Greedy.
		knapsack(n, w, p, capacity);
	}
	static void displayinfo(int n, float w[], float p[], float r[]) {
		System.out.println("Item\tWeight\tProfit\tRatio");
		for (int i = 1; i <= n; i++)
			System.out.println(i + "\t" + w[i] + "\t" + p[i] + "\t" + r[i]);
	}
	
	static void sortratio(int n, float w[], float p[], float r[]) {
		int i, j;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n - i; j++) {
				if (r[j] < r[j + 1]) {
					swap(r, j);
					swap(w, j);
					swap(p, j);
				}
			}
		}
	}
	
	static void knapsack(int n, float w[], float p[], int capacity) {
		float profit = 0, rc = capacity;
		float x[] = new float[10];
		
		for (int i = 1; i <= n; i++)
			x[i] = 0;
			
		for (int i = 1; i <= n; i++) {
			if (w[i] > rc) {
				x[i] = rc / w[i];
				profit = profit + x[i] * p[i];
				///////////BrEaK!!/////////////
				break;
			} else {
				x[i] = 1;
				rc = rc - w[i];
				profit = profit + x[i] * p[i];
			}
		}
		System.out.println("Fractions of item selected are");
		for (int i = 1; i <= n; i++)
			System.out.print(x[i] + "\t");
		System.out.println("\nMaximum profit=" + profit);
	}
	static void swap(float s[], int i) {
		float temp = s[i];
	           	s[i] = s[i + 1];
	           	s[i + 1] = temp;
	}
}