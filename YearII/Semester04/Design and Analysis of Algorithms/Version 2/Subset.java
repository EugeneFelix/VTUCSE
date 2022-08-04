import java.util.Scanner;
public class Subset {
	static int count = 0, d, n;
	static int w[] = new int[10];
	static int x[] = new int[10];
	public void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int sum = 0, i;
		System.out.println("Enter the value of n");
		n = in.nextInt();
		System.out.println("Enter the elements");
		for (i = 1; i <= n; i++) {
			w[i] = in.nextInt();
		}
		System.out.println("Enter the value of d");
		d = in.nextInt();
		for (i = 1; i <= n; i++) {
			x[i] = 0;
		}
		for (i = 1; i <= n; i++) {
			sum = sum + w[i];
		}
		if (d > sum) {
			System.out.println("No Solution");
		} else {
			subset(0, 1, sum);
			if (count == 0) {
				System.out.println("No solution");
			}
		}
	}
	public void subset(int s, int k, int u) {
		int i;
		x[k] = 1;
		if (s + w[k] == d) {
			count++;
			System.out.println("Subset" + count);
			for (i = 1; i <= k; i++) {
				if (x[i] == 1) {
					System.out.println(+w[i]);
				}
			}
		}
		else if(s + w[k] + w[k + 1] <= d) {
			subset(s + w[k], k + 1, u - w[k]);
		}
		if ((s + u - w[k]) >= d && (s + w[k + 1]) <= d) {
			x[k] = 0;
			subset(s, k + 1, u - w[k]);
		}
	}
}