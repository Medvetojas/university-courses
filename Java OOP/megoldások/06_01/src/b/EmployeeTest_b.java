package b;

import java.time.LocalDate;
import java.util.Scanner;

public class EmployeeTest_b {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		System.out.println("Number of employees: ");
		int numberOfEmployees = input.nextInt();
		input.nextLine();
		
		Employee_b[] employeeArray= new Employee_b[numberOfEmployees];
		
		for (int i = 0; i < employeeArray.length; i++) {
			System.out.println( (i+1) + ". employee: ");
			System.out.println("Name: ");
			String name = input.nextLine();
			System.out.println("Birthday: ");
			String instring = input.nextLine();
			String[] birthdayComponents = instring.split("/");
			int year=0, month=0, day=0;
			try {
				year = Integer.parseInt(birthdayComponents[0]);
				day = Integer.parseInt(birthdayComponents[2]);
				month = Integer.parseInt(birthdayComponents[1]);
				employeeArray[i] = new Employee_b(name, year, month, day);
			} catch (Exception NumberFormatException) {
				if (month==0)
					employeeArray[i] = new Employee_b(name, year, birthdayComponents[1], day);
			}
		}

		listEmployeeArray(employeeArray);
		
	}

	private static void listEmployeeArray(Employee_b[] employeeArray) {
		for(Employee_b employee: employeeArray) {
			System.out.println(employee);
			System.out.println(employee.displayInfo("birthday"));
			System.out.println(employee.displayInfo("age"));
		}
	}
	
}
