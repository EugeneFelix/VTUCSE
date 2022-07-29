import java.util.*;
public class KnapsackGreedy {
	public void main(String[] args) {
		int n, M, i;
		float r[] = new float[10];
		float p[] = new float[10];
		float w[] = new float[10];
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the no of items");
		n = in.nextInt();
		System.out.println("*****WEIGHTS*****");
		for (i = 1; i <= n; i++)
			w[i] = in.nextFloat();
		System.out.println("*****PROFITS*****");
		for (i = 1; i <= n; i++)
			p[i] = in.nextFloat();
		System.out.println("Enter the knapsack capacity");
		M = in.nextInt();
		// Create ratio array.
		for (i = 1; i <= n; i++)
			r[i] = p[i] / w[i];
		System.out.println("Before sorting");
		displayinfo(n, w, p, r);
		sortratio(n, w, p, r);
		
		
		System.out.println("After sorting");
		displayinfo(n, w, p, r);
		//Call knapsack.
		knapsack(n, w, p, M);
		in.close();
	}
	static void displayinfo(int n, float w[], float p[], float r[]) {
		System.out.println("Item\tWeight\tProfit\tRatio");
		for (int i = 1; i <= n; i++)
			System.out.println(i + "\t" + w[i] + "\t" + p[i] + "\t" + r[i]);
	}
	
	static void sortratio(int n, float w[], float p[], float r[]) {
		int i, j;
		float temp;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n - i; j++) {
				if (r[j] < r[j + 1]) {
					temp = r[j];
					r[j] = r[j + 1];
					r[j + 1] = temp;
					temp = w[j];
					w[j] = w[j + 1];
					w[j + 1] = temp;
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
		}
	}
	
	static void knapsack(int n, float w[], float p[], int M) {
		float profit = 0, rc;
		int i;
		float x[] = new float[10];
		for (i = 1; i <= n; i++)
			x[i] = 0;
		rc = M;
		for (i = 1; i <= n; i++) {
			if (w[i] > rc) {
				x[i] = rc / w[i];
				profit = profit + x[i] * p[i];
				break;
			} else {
				x[i] = 1;
				rc = rc - w[i];
				profit = profit + x[i] * p[i];
			}
		}
		System.out.println("Fractions of item selected are");
		for (i = 1; i <= n; i++)
			System.out.print(x[i] + "\t");
		System.out.println("\nMaximum profit=" + profit);
	}
}