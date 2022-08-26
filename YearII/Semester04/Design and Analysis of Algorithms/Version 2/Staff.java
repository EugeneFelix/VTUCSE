import java.util.Scanner;
class Staff {
	protected String staffId, name, ph;
	protected float salary;
	public Staff(String staffId, String name, float salary2, String ph) {
		super();
		this.staffId = staffId;
		this.name = name;
		this.salary = salary2;
		this.ph = ph;
	}
	@Override public String toString() {
		return "Staff [staffId=" + staffId + ", name=" + name + ", salary=" + salary + ", ph=" + ph + "]";
	}
}
class Teaching extends Staff {
	private String domian, publication;
	public Teaching(String staffId, String name, float salary, String ph, String domian, String publication) {
		super(staffId, name, salary, ph);
		this.domian = domian;
		this.publication = publication;
	}
	@Override public String toString() {
		return "Teaching [domian=" + domian + ", publication=" + publication + ", staffId=" + staffId + ", name=" + name + ", ph=" + ph + ", salary=" + salary + "]";
	}
}
class Technical extends Staff {
	private String skills;
	public Technical(String staffId, String name, float salary, String ph, String skills) {
		super(staffId, name, salary, ph);
		this.skills = skills;
	}
	@Override
	public String toString() {
		return "Technical [skills=" + skills + ", staffId=" + staffId + ", name=" + name + ", ph=" + ph + ", salary=" + salary + "]";
	}
}
class Contract extends Staff {
	private String period;
	public Contract(String staffId, String name, float salary, String ph, String period) {
		super(staffId, name, salary, ph);
		this.period = period;
	}
	@Override public String toString() {
		return "Contract [period=" + period + ", staffId=" + staffId + ", name=" + name + ", ph=" + ph + ", salary=" + salary + "]";
	}
}