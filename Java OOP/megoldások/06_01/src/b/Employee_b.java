package b;

import java.time.LocalDate;

public class Employee_b {
	private String name;
	private LocalDate birthday;
	private long salary;
	
	private static final int retirementAge = 65;
	
	private static String[] monthNames;
	
	static {
		 monthNames = new String[13];
		 monthNames[0] = " ";
		 monthNames[1] = "januar";
		 monthNames[2] = "februar";
		 monthNames[3] = "marcius"; 
		 monthNames[4] = "aprilis";
		 monthNames[5] = "majus";
		 monthNames[6] = "junius";
		 monthNames[7] = "julius";
		 monthNames[8] = "augusztus";
		 monthNames[9] = "szeptember";
		 monthNames[10] = "oktober";
		 monthNames[11] = "november";
		 monthNames[12] = "december";
	}
	
	public Employee_b(String name, LocalDate birthday, long salary) {
		this.name = name;
		this.birthday = birthday;
		this.salary = salary;
	}
	
	//A konstruktorban a getAge() példányszintű metódus nem hívható
	public Employee_b(String name, int year, int month, int day) {
		this.name = name;
		this.birthday = LocalDate.of(year, month, day);
		this.salary = 10000*(LocalDate.now().getYear()-birthday.getYear());
	}
	
	public Employee_b(String name, int year, String month, int day) {
		this.name = name;
		int monthvalue;
		if(convertMonthName(month)==0)
			monthvalue = 1;		//default: január
		else
			monthvalue = convertMonthName(month);
		this.birthday = LocalDate.of(year, monthvalue, day);
		this.salary = 10000*(LocalDate.now().getYear()-birthday.getYear());
	}
	
	public int yearsUntilRetirement() {
		return retirementAge - this.getAge();
	}
	
	public int getAge() {
		return LocalDate.now().getYear()-birthday.getYear();
	}
	
	public String displayInfo(String str) {
		String info = " ";
		switch(str) {
			case "age" : 
				info = name + ", kora: " + getAge() + " év";
				break;
			case "birthday" : 
				info = name + ", szül.: " + getHunBirthday();
		}
		return info;
	}
	
	public String getHunBirthday() {
		int year = birthday.getYear();
		int monthvalue = birthday.getMonthValue();
		String monthname = convertMonthValue(monthvalue);
		int day = birthday.getDayOfMonth();
		return year + ". " + monthname + " " + day + ".";
	}
	
	public String convertMonthValue(int monthvalue) {
		return monthNames[monthvalue];
	}
	
	public int convertMonthName(String monthname) {
		for(int i=1; i<monthNames.length; i++) {
			if (monthNames[i].equalsIgnoreCase(monthname))
				return i;
		}
		return 0;
	}
	
	/*******/
	
	@Override
	public String toString() {
		return name + ", " + birthday + ", Fizetése: " + salary + " Ft/hó, Nyugdíjig hátralévő évek száma: " + yearsUntilRetirement();
	}
	
	//Getter, setter methods
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public long getSalary() {
		return salary;
	}

	public void setSalary(long salary) {
		this.salary = salary;
	}
	
	public LocalDate getBirthday() {
		return birthday;
	}

	public void setBirthday(LocalDate day) {
		this.birthday = day;
	}
	
	public static int getRetirementAge() {
		return retirementAge;
	}

}
