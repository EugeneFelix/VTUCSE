import java.util.Scanner;
public class Students {
	private String usn, name, branch, phone;
	public Students(String usn, String name, String branch, String phone) {
		super();
		this.usn = usn;
		this.name = name;
		this.branch = branch;
		this.phone = phone;
	}
	public void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter total number of students:-");
		int n = in.nextInt();
		Students[] st = new Students[n];
		String usn, name, branch, phone;
		for (int i = 0; i < n; i++) {
			System.out.println("\nEnter details of student " + (i + 1));
			System.out.println("USN:");
			usn = in.next();
			System.out.println("Name:");
			name = in.next();
			System.out.print("Branch:");
			branch = in.next();
			System.out.print("Phone number:");
			phone = in.next();
			st[i] = new Students(usn, name, branch, phone);
		}
		System.out.println("Student Details");
		System.out.println("USN\tName\tBranch\tPhone");
		for (int i = 0; i < n; i++)
			System.out.println(st[i].usn + "\t" + st[i].name + "\t" + st[i].branch + "\t" + st[i].phone);
			in.close();
	}
}