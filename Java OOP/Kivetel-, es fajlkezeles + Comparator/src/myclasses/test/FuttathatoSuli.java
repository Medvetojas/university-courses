package myclasses.test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

import myclasses.Student;

public class FuttathatoSuli {

	public static void main(String[] args) {
		//Elore feltoltott lista fileba irasa
		ArrayList<Student> list = new ArrayList<Student>();
		list.add(new Student("Kiss Tamás", "ab1234"));
		list.add(new Student("Babik Szilard", "a6nqw1"));
		list.add(new Student("Agbeko Nwida Lmao", "hysw54"));
		File file = new File("students.txt");
		System.out.println("A feltoltott lista kiirasa: " + list);
		writeFile(list, file);
		
		//Az iment megirt file beirasa egy masik listbe
		ArrayList<Student> readList = new ArrayList<Student>();
		readList = readFile(file);
		System.out.println("A visszairt lista kiirasa: " + readList);
		
		//Az iment feltoltott lista nev szerinti rendezese
		Collections.sort(readList, new Student.NameSorter());
		System.out.println("A rendezett lista kiirasa: " + readList);
		
		//Forditva is lehet nev szerint rendezni
		Collections.sort(readList, new Student.NameSorter().reversed());
		System.out.println("A forditva rendezett lista kiirasa: " + readList);
	}

	private static ArrayList<Student> readFile(File file) {
		ArrayList<Student> readListInTry = new ArrayList<Student>();
		try (FileReader fileReader = new FileReader(file); BufferedReader reader = new BufferedReader(fileReader)) {
			String line;
			while((line = reader.readLine()) != null) {
				String[] separator = line.split(";");
				readListInTry.add(new Student(separator[0], separator[1]));
			}
		} catch (IOException e) {
			System.out.println("Error reading file...");
		}
		
		return readListInTry;
	}

	private static void writeFile(ArrayList<Student> list, File file) {
		try (FileWriter fileWriter = new FileWriter(file)) {
			for (Student item : list) {
				fileWriter.write(item.getName() + ";" + item.getNeptun() + "\n");
			}
		} catch (IOException e) {
			System.out.println("Error in writing file...");
		}
	}

}
