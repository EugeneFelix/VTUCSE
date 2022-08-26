import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int choice;
		Scanner scanner = new Scanner(System.in);
		while (true) {
			System.out.println("Enter program number, or please get out!" + 
			                   "...\n" + 
			                   "0. Kick me out!\n\n" +
			                   "11. Student\n" + 
			                   "12. Stacks\n" +
			                   "21. Staff \n" + 
			                   "22. Customer\n" + 
			                   "31. Exceptions\n" + 
			                   "32. Threads\n" + 
			                   "4. QuickSort\n"+ 
			                   "5. MergeSort\n" + 
			                   "61. KnapSack Dynamic\n" + 
			                   "62. KnapSack Greedy\n" + 
			                   "7. Dijkstra\n" + 
			                   "8. Kruskal\n" + 
			                   "91. Floyd\n" + 
			                   "92. TSP Dynamic\n" + 
			                   "10. DJP\n" + 
			                   "11 Subset\n" + 
			                   "12. Hamiltonian Cycle\n");
			choice = scanner.nextInt();
			switch (choice) {
			case 0:
				System.out.println("You are officially kicked out, Goodbye!");
				System.exit(1);
				break;
			case 1:
				Students st = new Students("Hello", "Hello", "Hello", "Hello");
				st.main(null);
				break;
			case 31:
				ThreadsDemo td = new ThreadsDemo();
				td.main(null);
				break;
			case 4:
				QuickSort qs = new QuickSort();
				qs.main(null);
				break;
			case 5:
				MergeSort ms = new MergeSort();
				ms.main(null);
				break;
			case 61:
				knapSackDyn kspD = new knapSackDyn();
				kspD.main(null);
				break;
			case 62:
				KnapsackGreedy ksg = new KnapsackGreedy();
				ksg.main(null);
				break;
			case 7:
				Dijkstra djk = new Dijkstra();
				djk.main(null);
				break;
			case 8:
				Kruskal krs = new Kruskal();
				krs.main(null);
				break;
			case 91:
				Floyd fld = new Floyd();
				fld.main(null);
				break;
			case 92:
				TSPDyn tspdyn = new TSPDyn();
				tspdyn.main(null);
				break;
			case 10:
				Prim prim = new Prim();
				prim.main(null);
				break;
			case 11:
				Subset subset = new Subset();
				subset.main(null);
				break;
			case 12:
				Hamiltonian hml = new Hamiltonian();
				hml.main(null);
				break;
			default:
				System.out.println("Invalid choice!");
			}
			System.out.println("Enter next choice, or 0 to exit");
		}
	}
}