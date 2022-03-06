package myclasses;

public class Szemely {
	private String name;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Szemely(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return "Szemely [name=" + name + "]";
	}
	
	
}
