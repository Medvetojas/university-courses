package mypersons;

public class Employee extends Adult {
	private int fizetes;
	private final int nyugdijkorhatar = 65;
	
	
	public Employee(String name, int age, String workplace, int fizetes) {
		super(name, age, workplace);
		this.fizetes = fizetes;
	}


	public int getFizetes() {
		return fizetes;
	}


	@Override
	public String toString() {
		return "Employee [fizetes=" + fizetes + ", getWorkplace()=" + getWorkplace() + ", getName()=" + getName()
				+ ", getAge()=" + getAge() + "]";
	}
	
	
}
