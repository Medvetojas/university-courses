package mypersons;

public class Person {
	private String name;
	private int age;
	
	
	public Person(String name, int age) {
		super();
		this.name = name;
		this.age = age;
	}


	public String getName() {
		return name;
	}


	public int getAge() {
		return age;
	}


	@Override
	public String toString() {
		return "Person [nev=" + name + ", kor=" + age + "]";
	}
	
	public Boolean compareEletkor(Person person2) {
		if(this.getAge() > person2.getAge()) {
			return true;
		}else {
			return false;
		}
	}
	
	
}
