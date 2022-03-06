package mypackage.second;

import mypackage.first.Szam;

public class Proba {
	public static void main(String[] args) {
		final Szam szam = new Szam(0.25);
		System.out.println(szam);

		szam.setValosSzam(0.99);
		System.out.println(szam);

		int counter = 0;
		boolean found = false;

		while (!found) {
			double randomSzam = Math.random();
			System.out.println("Random szam: " + randomSzam);
			counter++;

			if (szam.teresenBelulVanE(randomSzam)) {
				found = true;
			}
		}

		System.out.println("Genrealt veletenszamok szama: " + counter);

		// szam = new Szam(0.11);
		// System.out.println(szam);

	}

}