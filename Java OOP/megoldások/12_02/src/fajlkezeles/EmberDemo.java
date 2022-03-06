package fajlkezeles;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class EmberDemo {

	public static void main(String[] args) {
		File fajl = new File("emberek.txt");
		ArrayList<Ember> emberek = null;
		try {
			emberek = fajlbolOlvas(fajl);
		} catch (IOException e) {
			e.printStackTrace();
		}

		if (emberek != null) {
			for (Ember e : emberek) {
				System.out.println(e.toString());
			}
		}

		emberek.sort(Comparator.comparing(Ember::getEletkor));
		System.out.println();
		if (emberek != null) {
			for (Ember e : emberek) {
				System.out.println(e.toString());
			}
		}

	}

	private static ArrayList<Ember> fajlbolOlvas(File falj) throws IOException {
		ArrayList<Ember> emberek = new ArrayList<Ember>();

		FileReader fileReader = new FileReader(falj);
		BufferedReader br = new BufferedReader(fileReader);
		String sor = "";

		while ((sor = br.readLine()) != null) {
			String[] adatok = sor.split(";");
			String nev = adatok[0];
			int eletkor = Integer.parseInt(adatok[1]);

			emberek.add(new Ember(nev, eletkor));
		}

		br.close();

		return emberek;

	}

}
