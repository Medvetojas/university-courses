package sajatcsomag.test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDate;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import myclasses.Student;
import sajatcsomag.Bejegyzes;
import sajatcsomag.exceptions.InvalidMarkException;

public class BejegyzesFut {

	public static void main(String[] args) {
		Bejegyzes tomb[] = new Bejegyzes[3];
		tombBeolvas(tomb);
		System.out.println("Alap print: ");
		tombKiir(tomb);
		
		Arrays.sort(tomb, new Bejegyzes.DateSorter());
		System.out.println("Rendezes utani print: ");
		tombKiir(tomb);
		
		Arrays.sort(tomb, new Bejegyzes.DateSorter().reversed());
		System.out.println("Forditott rendezes utani print: ");
		tombKiir(tomb);
		
		File file = new File("students.txt");
		writeFile(tomb, file);
		
		ArrayList<Bejegyzes> beolvtomb = new ArrayList<Bejegyzes>();
		beolvtomb = readFile(file);
		System.out.println("File-ba iras, majd ArrayList-be visszairas utani print: ");
		tombKiir(beolvtomb);
		
	}
	

	private static ArrayList<Bejegyzes> readFile(File file) {
		ArrayList<Bejegyzes> readListInTry = new ArrayList<Bejegyzes>();
		try (FileReader fileReader = new FileReader(file); BufferedReader reader = new BufferedReader(fileReader)) {
			String line;
			while((line = reader.readLine()) != null) {
				String[] separator = line.split(";");
				LocalDate date = LocalDate.parse(separator[1]);
				int mark = Integer.parseInt(separator[2]);
				try {
					readListInTry.add(new Bejegyzes(separator[0], date, mark));
				} catch (InvalidMarkException e) {
					
				}
			}
		} catch (IOException e) {
			System.out.println("Error reading file...");
		}
		
		return readListInTry;
	}
	
	private static void writeFile(Bejegyzes[] tomb, File file) {
		try (FileWriter fileWriter = new FileWriter(file)) {
			for (Bejegyzes bejegyzes : tomb) {
				fileWriter.write(bejegyzes.getSubject() + ";" + bejegyzes.getDate() + ";" + bejegyzes.getMark() + "\n");
			}
		} catch (IOException e) {
			System.out.println("Hiba a fajl irasakor...");
		}
	}

	private static void tombKiir(Bejegyzes[] tomb) {
		for (Bejegyzes bejegyzes : tomb) {
			System.out.println(bejegyzes);
		}
		
	}
	
	private static void tombKiir(ArrayList<Bejegyzes> beolvtomb) {
		for (Bejegyzes bejegyzes : beolvtomb) {
			System.out.println(bejegyzes);
		}
		
	}

	private static void tombBeolvas(Bejegyzes[] tomb) {
		try (Scanner scanner = new Scanner(System.in)) {
		for (int i = 0; i < tomb.length; i++) {
			String subject;
			String mark;
			String date;
			
			// Scanner scanner = new Scanner(System.in);
			
			System.out.println("Add meg a(z) " + (i+1) + ". tantargyat: ");
			subject = scanner.nextLine();
			System.out.println("Add meg a(z) " + (i+1) + ". datumot: ");
			date = scanner.nextLine();
			LocalDate dateInDateFormat = LocalDate.parse(date); //atalakitas datumma
			System.out.println("Add meg a(z) " + (i+1) + ". erdemjegyet: ");
			mark = scanner.nextLine();
			int markInInt = Integer.parseInt(mark);
			
			if (dateInDateFormat == null) {
				dateInDateFormat = LocalDate.now();
			}
			
			if (markInInt == 0) {
				markInInt = 5;
			}
			
			tomb[i] = new Bejegyzes(subject, dateInDateFormat, markInInt);
			
		}
		} catch (DateTimeParseException e){
			System.out.println("Ervenytelen datum!");
		} catch (NumberFormatException e) {
			System.out.println("Nem szamot irtal be...");
		} catch (InvalidMarkException e) {
		
		}
//		} finally {
//			for (Bejegyzes bejegyzes : tomb) {
//				if(bejegyzes == null) {
//					try {
//						bejegyzes = new Bejegyzes("OOP", LocalDate.now(), 5);
//					} catch (InvalidMarkException e) {
//						System.out.println("Ez soha nem fog megtortenni, de ha megis megtortent akkor kaki vagyok.");
//					}
//				}
//			}
//		}
	}

}
