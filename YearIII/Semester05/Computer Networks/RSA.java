import static java.lang.System.out;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;

public class RSA {
	public void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String message1;
		/*
		-- Variablesá explained.
		e: public key.
		d: private key.
		
		*/
		int[] plainText = new int[100];
		int[] cipherText = new int[100];
		int d;
		System.out.println("Enter the values of p and q:");
		int p = sc.nextInt();
		int q = sc.nextInt();
		int n = p * q;
		int z = (p - 1) * (q - 1);
		System.out.println("Select a value for e:");
		int e = sc.nextInt();
		System.out.println("Error message:");
		message1 = br.readLine();
		char[] msg = message1.toCharArray();
		for (int i = 0; i < msg.length; i++)
			plainText[i] = msg[i];
		for (d = 0; d < z; d++)
			if ((e * d) % z == 1)
				break;
		System.out.println("p = " + p + "\tq = " + q + "\tn = " + n + "\tz = " + z + "\te = " + e + "\td = " + d);
		System.out.println("Cipher Text = ");
		for (int i = 0; i < msg.length; i++)
			cipherText[i] = mult(plainText[i], e, n);
		for (int i = 0; i < msg.length; i++)
			System.out.print(cipherText[i] + "\t");
		System.out.println();
		System.out.println("Plain Text = ");
		for (int i = 0; i < msg.length; i++)
			plainText[i] = mult(cipherText[i], d, n);
		for (int i = 0; i < msg.length; i++)
			System.out.print((char) plainText[i]);
		System.out.println();
	}

	static int mult(int x, int y, int n) {
		int k = 1;
		for (int i = 0; i < y; i++)
			k = (k * x) % n;
		return k;
	}
}
