package myclasses;

import java.util.Comparator;

public class Student extends Szemely{
	private String neptun;

	public String getNeptun() {
		return neptun;
	}

	public void setNeptun(String neptun) {
		this.neptun = neptun;
	}

	public Student(String name, String neptun) {
		super(name);
		this.neptun = neptun;
	}

	@Override
	public String toString() {
		return "Student [neptun=" + neptun + ", getName()=" + getName() + "]";
	}
	
	//Comparator!!!
	public static class NameSorter implements Comparator<Student>{
		public int compare(Student o1, Student o2) {
			return o1.getName().compareTo(o2.getName());
		}
	}
}
