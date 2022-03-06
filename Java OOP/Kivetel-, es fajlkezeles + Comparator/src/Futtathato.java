import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Futtathato {

	public static void main(String[] args) {
		ArrayList<String> names = new ArrayList<String>();
		names.add("Kiss Katalin");
		System.out.println("Manualis adatfeltoltes utan...");
		System.out.println(names);
		
		File file = new File("names.txt");
		writeInFile(file, names);
		names = readFromFileWithFileReader(file);
		System.out.println("Fajlba iras utan...");
		System.out.println(names);
		
		Collections.sort(names); //Kizárólag ha nem objektumokat tartalmaz a lista...
		System.out.println("Rendezes utan...");
		System.out.println(names);
		
		
	}
	
	
	private static void writeInFile(File file, ArrayList<String> names) {
		//Ha a fájlt hozzáírásra (append) akarjuk megnyitni, akkor
		//a FileWriter 2 paraméteres konstruktorát kell használni úgy,
		//hogy a másik hívási argumentum 'true'
		
		try(FileWriter fileWriter = new FileWriter(file)){
			for (String name : names) {
				fileWriter.write(name + "\n");
			}
			fileWriter.flush(); //output buffer kiürítése
		} catch (IOException e) {
			System.out.println("Error in writing file...");
		}
	}
	
	private static ArrayList<String> readFromFileWithFileReader(File file) {		
		ArrayList<String> names = new ArrayList<String>();
		String line;
		
		try(FileReader fileReader = new FileReader(file); BufferedReader reader = new BufferedReader(fileReader)) {
			while ((line = reader.readLine()) != null) {
				names.add(line);
			}
		} catch (IOException e) {
			System.out.println("Error in reading file...");
		}
		
		return names;
	}
	
	private static ArrayList<String> readFromFileWithScanner(File file) {		
		ArrayList<String> names = new ArrayList<String>();
		try (Scanner scanner = new Scanner(file)) {
			while(scanner.hasNextLine()) {
				names.add(scanner.nextLine());
			}
		} catch (FileNotFoundException e) {
			System.out.println("Cannot find file...");
		}
		
		return names;
	}

}
