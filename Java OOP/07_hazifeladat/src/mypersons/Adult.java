package mypersons;

public class Adult extends Person {
	
	private String workplace;
	
	public Adult(String name, int age, String workplace) {
		super(name, age);
		this.workplace = workplace;
	}

	
	public String getWorkplace() {
		return workplace;
	}


	@Override
	public String toString() {
		return "Adult [workplace=" + workplace + ", getName()=" + getName() + ", getAge()=" + getAge() + "]";
	}
	
	
}
