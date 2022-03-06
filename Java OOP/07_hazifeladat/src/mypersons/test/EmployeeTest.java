package mypersons.test;

import java.util.Scanner;

import mypersons.Adult;
import mypersons.Child;
import mypersons.Employee;
import mypersons.Person;

public class EmployeeTest{

	public static void main(String[] args) {
		Person Person1, Person2;
		
		Person1 = beolvas();
		Person2 = beolvas();
		
		System.out.println("Person 1 a Person leszármazottja?" + (Person1 instanceof Person));
		System.out.println("Person 2 a Person leszármazottja?" + (Person2 instanceof Person));
		System.out.println(Person1);
		System.out.println(Person2);
		
		//TODO: LEGUTOLSÓ BEKEZDÉS
	}
	
	private static Person beolvas() {
		Scanner input = new Scanner(System.in);
		String name;
		int age;
		Person tempPerson;
		
		System.out.println("Add meg a személy nevét: ");
		name = input.nextLine();
		System.out.println("Add meg a személy korát: ");
		age = input.nextInt();
		
		input.nextLine();
		
		if(age < 18) {
			String school;
			System.out.println("Add meg a gyermek iskoláját: ");
			school = input.nextLine();
			tempPerson = new Child(name, age, school);
			return tempPerson;
		}else {
			String workplace;
			System.out.println("Add meg a felnőtt munkahelyét (lehet üres): ");
			workplace = input.nextLine();
			if(workplace.isEmpty()) {
				tempPerson = new Adult(name, age, workplace);
				return tempPerson;
			}else {
				int fizetes;
				System.out.println("Add meg a dolgozó fizetését: ");
				fizetes = input.nextInt();
				tempPerson = new Employee(name, age, workplace, fizetes);
				return tempPerson;
			}
			
		}
		
	}
	
	
}
