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
			                   "\t\t8. Bellman - Ford Algorithm\n" +
			                   "\t\t9. Staff \n" + 
			                   "\t\t10. Customer\n" + 
			                   "\t\t11. Exceptions\n" + 
			                   "\t\t12. Threads\n");
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
		/*  case 8:
				ThreadsDemo td = new ThreadsDemo();
				td.main(null);
				break;
			case 9:
				QuickSort qs = new QuickSort();
				qs.main(null);
				break;
			case 10:
				MergeSort ms = new MergeSort();
				ms.main(null);
				break;
			case 11:
				knapSackDyn kspD = new knapSackDyn();
				kspD.main(null);
				break;
			case 12:
				KnapsackGreedy ksg = new KnapsackGreedy();
				ksg.main(null);
				break; */
			default:
				System.out.println("Invalid choice!");
			}
			System.out.println("Enter next choice, or 0 to exit");
		}
	}
}
