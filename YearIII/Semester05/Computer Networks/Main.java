import java.io.IOException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		int choice;
		Scanner scanner = new Scanner(System.in);
		while (true) {
			System.out.println("\t\t\tEnter program number, or please get out!" +
							   "...\n" +
							   "\t\t0. Kick me out!\n\n" +
							   "\t\t7. CRC-CCIT\n" +
							   "\t\t8. Bellman Ford\n" +
							   "\t\t9. TCP Protocol\n" +
							   "\t\t10. UDP Protocol\n" +
							   "\t\t11. RSA\n" +
							   "\t\t12. Leaky Bucket\n");
			choice = scanner.nextInt();
			switch (choice) {
			case 0:
				System.out.println("You are officially kicked out, Goodbye!");
				scanner.close();
				System.exit(1);
				break;
			case 7:
				crcCCITT crc = new crcCCITT();
				crc.main(null);
				break;
			case 8:
				bellmanFord2 bf = new bellmanFord2();
				bf.main(null);
				break;
			case 9:
				System.out.println("1. TCP Client\n2. TCP Server");
				int cht = scanner.nextInt();
				switch (cht) {
				case 1:
					TCPClient client = new TCPClient();
					client.main(null);
					break;
				case 2:
					TCPServer server = new TCPServer();
					server.main(null);
					break;
				}
				break;
			case 10:
				System.out.println("1. TCP Client\n2. TCP Server");
				int cht2 = scanner.nextInt();
				switch (cht2) {
				case 1:
					UDPClient clientu = new UDPClient();
					clientu.main(null);
					break;
				case 2:
					UDPServer serveru = new UDPServer();
					serveru.main(null);
					break;
				}
				break;
			case 11:
	            RSA rsa = new RSA();
				rsa.main(null);
				break;
			case 12:
				leakyBucket lb = new leakyBucket();
				lb.main(null);
				break;
			default:
				System.out.println("Invalid choice!");
			}
			System.out.println("Enter next choice, or 0 to exit");
		}
	}
}