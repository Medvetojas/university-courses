package fajlkezeles;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;

public class Demo {

	public static void main(String[] args) {
		ArrayList<String> nevek = new ArrayList<String>();

		feltolt(nevek);
		kiir(nevek);

		File fajl = new File("nevek.txt");
		try {
			fajlbaIr(fajl, nevek);
		} catch (IOException e) {
			e.printStackTrace();
		}

		ArrayList<String> olvasottAdatok = new ArrayList<String>();
		try {
			olvasottAdatok = fajlbolOlvas(fajl);
		} catch (FileNotFoundException e) {
			System.out.println("Nem talahato a fajl!");
			e.printStackTrace();
		} catch (IOException e) {
			System.out.println("IO error!");
			e.printStackTrace();
		}
		System.out.println("Olvasott adatok:");
		kiir(olvasottAdatok);

		nevek.add("Valaki2");
		try {
			fajlbaIr(fajl, nevek);
		} catch (IOException e) {
			e.printStackTrace();
		}

		try {
			olvasottAdatok = fajlbolOlvas(fajl);
		} catch (FileNotFoundException e) {
			System.out.println("Nem talahato a fajl!");
			e.printStackTrace();
		} catch (IOException e) {
			System.out.println("IO error!");
			e.printStackTrace();
		}
		System.out.println("Olvasott adatok:");
		kiir(olvasottAdatok);

		nevek.remove(0);
		try {
			fajlbaIr(fajl, nevek);
		} catch (IOException e) {
			e.printStackTrace();
		}

		try {
			olvasottAdatok = fajlbolOlvas(fajl);
		} catch (FileNotFoundException e) {
			System.out.println("Nem talahato a fajl!");
			e.printStackTrace();
		} catch (IOException e) {
			System.out.println("IO error!");
			e.printStackTrace();
		}
		System.out.println("Olvasott adatok:");
		kiir(olvasottAdatok);
		
		
		
		
		nevek.sort(Comparator.naturalOrder());
		try {
			fajlbaIr(fajl, nevek);
		} catch (IOException e) {
			e.printStackTrace();
		}

		try {
			olvasottAdatok = fajlbolOlvas(fajl);
		} catch (FileNotFoundException e) {
			System.out.println("Nem talahato a fajl!");
			e.printStackTrace();
		} catch (IOException e) {
			System.out.println("IO error!");
			e.printStackTrace();
		}
		System.out.println("Olvasott adatok rendezve:");
		kiir(olvasottAdatok);


	}

	
	
	
	private static void kiir(ArrayList<String> nevek) {
		for (String string : nevek) {
			System.out.println(string);
		}
	}

	private static void feltolt(ArrayList<String> nevek) {
		nevek.add("Kiss Pista");
		nevek.add("Erõs Pista");
		nevek.add("Fel Elek");
		nevek.add("Megegy Elek");
		nevek.add("Valaki");
	}

	private static void fajlbaIr(File falj, ArrayList<String> nevek) throws IOException {
		FileWriter fileWriter = new FileWriter(falj);

		for (String adat : nevek) {
			fileWriter.write(adat + "\n");
		}
		fileWriter.flush();

		if (fileWriter != null)
			fileWriter.close();
	}

	private static ArrayList<String> fajlbolOlvas(File falj) throws IOException {
		ArrayList<String> nevek = new ArrayList<String>();

		FileReader fileReader = new FileReader(falj);
		BufferedReader br = new BufferedReader(fileReader);
		String sor = "";

		while ((sor = br.readLine()) != null) {
			nevek.add(sor);
		}

		br.close();

		return nevek;

	}

}
