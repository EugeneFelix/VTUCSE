import java.util.Scanner;
public class Subset {
	static int count = 0, d, n;
	static int set[] = new int[10];
	static int isSafe[] = new int[10];
	public void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int target = 0, i;
		System.out.println("Enter the value of n");
		n = in.nextInt();
		System.out.println("Enter the elements");
		for (i = 1; i <= n; i++)
			set[i] = in.nextInt();
		System.out.println("Enter the value of d");
		d = in.nextInt();
		for (i = 1; i <= n; i++)
			isSafe[i] = 0;
		for (i = 1; i <= n; i++)
			target += set[i];
		if (d > target) {
			System.out.println("No Solution");
		} else {
			subset(0, 1, target);
			if (count == 0)
				System.out.println("No solution");
		}
	}
	public void subset(int s, int k, int target) {
		isSafe[k] = 1;
		if (s + set[k] == d)
			printSolution(k);
		else
			if (s + set[k] + set[k + 1] <= d)
				subset(s + set[k], k + 1, target - set[k]);
		if (d <= (s + target - set[k]) && d >= (s + set[k + 1])) {
			isSafe[k] = 0; //do not include s[k]
			subset(s, k + 1, target - set[k]);
		}
	}
	public void printSolution(int k) {
		count++;
		System.out.println("Subset " + count + ":");
		for (int i = 1; i <= k; i++)
			if (isSafe[i] == 1)
				System.out.println(set[i]);
	}
}