import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int choice;
		Scanner scanner = new Scanner(System.in);
		while (true) {
			System.out.println("\t\t\tEnter program number, or please get out!" + 
			                   "...\n" + 
			                   "\t\t0. Kick me out!\n\n" +
			                   "\t\t11. Student\n" + 
			                   "\t\t12. Stacks\n" +
			                   "\t\t21. Staff \n" + 
			                   "\t\t22. Customer\n" + 
			                   "\t\t31. Exceptions\n" + 
			                   "\t\t32. Threads\n" + 
			                   "\t4. QuickSort\n"+ 
			                   "\t5. MergeSort\n" + 
			                   "\t\t61. KnapSack Dynamic\n" + 
			                   "\t\t62. KnapSack Greedy\n" + 
			                   "\t7. Dijkstra\n" + 
			                   "\t8. Kruskal\n" + 
			                   "\t\t91. Floyd\n" + 
			                   "\t\t92. TSP Dynamic\n" + 
			                   "\t10. DJP\n" + 
			                   "\t11 Subset\n" + 
			                   "\t12. Hamiltonian Cycle\n");
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