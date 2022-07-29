import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int choice;
		Scanner scanner = new Scanner(System.in);
		System.out.println("\t\tEnter program number... or 0 to exit if you are not in the mood...");
		while (true) {
			choice = scanner.nextInt();
			switch (choice) {
			case 0:
				System.exit(1);
				break;
			/*case 1: Student st = new Student("Hello", "Hello", "Hello", "Hello");
			               st.main(null);
			               break;*/
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