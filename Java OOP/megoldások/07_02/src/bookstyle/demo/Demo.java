package bookstyle.demo;

import java.util.Scanner;

import bookstyle.KonyvStilus;

public class Demo {

	public static void main(String[] args) {
		int n = beolvas();
		KonyvStilus[] tomb = new KonyvStilus[n];
		Scanner sc = new Scanner(System.in);

		for (int i = 0; i < tomb.length; i++) {
			System.out.println((i + 1) + ". Kerem a cimet: ");
			String cim = sc.next();

			System.out.println((i + 1) + ". Kerem a szerzot: ");
			String szerzo = sc.next();

			System.out.println((i + 1) + ". Kerem az arat: ");
			double ar = sc.nextDouble();

			System.out.println((i + 1) + ". Kerem az evet: ");
			int ev = sc.nextInt();

			System.out.println((i + 1) + ". Kerem a stilust: ");
			String stilus = sc.next();

			tomb[i] = new KonyvStilus(cim, szerzo, ar, ev, stilus);
		}

		final String scifiStilus = "scifi";
		kiir(tomb);
		System.out.println("Konlonbozo stilusu konyvek szama: " + getKulonbozoStilusuKonyvekSzama(tomb));
		System.out.println("Konlonbozo stilusu konyvek szama2: " + getKulonbozoStilusuKonyvekSzama2(tomb));

		System.out.println("Scifi stilusu konyvek: ");
		KonyvStilus[] scifi = getStilusuKonyvek(tomb, scifiStilus);
		if (scifi.length == 0)
			System.out.println("Nem volt scifi stilusu konyv!");
		else {
			for (KonyvStilus konyvStilus : scifi) {
				System.out.println(konyvStilus);
			}
		}

		System.out.println("Scifi stilusu konyvek atlagara: " + getAtlagAr(tomb, scifiStilus));
	}

	private static void kiir(KonyvStilus[] tomb) {
		for (KonyvStilus konyvStilus : tomb) {
			System.out.println(konyvStilus);
		}
	}

	private static int getKulonbozoStilusuKonyvekSzama(KonyvStilus[] tomb) {
		int counter = 1;

		for (int i = 1; i < tomb.length; i++) {
			boolean found = false;

			for (int j = i - 1; j >= 0; j--) {
				if (tomb[i].getStilus().equalsIgnoreCase(tomb[j].getStilus())) {
					found = true;
					break;
				} else {
					continue;
				}
			}

			if (!found)
				counter++;
		}
		return counter;
	}

	private static int getKulonbozoStilusuKonyvekSzama2(KonyvStilus[] tombIn) {
		String tombKulonbozoStilusok[] = new String[1000];
		int k = 0;
		boolean found = false;
		String stilus = "";
		tombKulonbozoStilusok[0] = tombIn[0].getStilus();
		int kolonbozoStilusokSzama = 0;

		
		for (int i = 0; i < tombIn.length; i++) {
			stilus = tombIn[i].getStilus();

			for (int j = 0; j < tombKulonbozoStilusok.length; j++) {
				if (tombKulonbozoStilusok[j] != null) {
					if (tombKulonbozoStilusok[j].equalsIgnoreCase(stilus)) {
						found = true;
					}
				}
			}

			if (!found) {
				k++;
				tombKulonbozoStilusok[k] = stilus;
			}
			found = false;
		}

		for (String string : tombKulonbozoStilusok) {
			if (string != null)
				kolonbozoStilusokSzama++;
		}

		return kolonbozoStilusokSzama;
	}

	
	private static int beolvas() {
		int n = -1;
		Scanner sc = new Scanner(System.in);

		do {
			System.out.println("Kerem a konyvek szamat: ");

			while (!sc.hasNextInt()) {
				System.out.println("Nem szám!");
				sc.next();
			}

			n = sc.nextInt();
		} while (n < 1 || n > 10);

		return n;
	}

	private static KonyvStilus[] getStilusuKonyvek(KonyvStilus[] tomb, String stilus) {
		int db = 0;

		for (int i = 0; i < tomb.length; i++) {
			if (tomb[i].getStilus().equalsIgnoreCase(stilus))
				db++;
		}

		KonyvStilus[] tmpTomb = new KonyvStilus[db];
		int j = 0;
		for (int i = 0; i < tomb.length; i++) {
			if (tomb[i].getStilus().equalsIgnoreCase(stilus)) {
				tmpTomb[j] = tomb[i];
				j++;
			}
		}

		return tmpTomb;
	}

	private static double getAtlagAr(KonyvStilus[] tomb, String stilus) {
		KonyvStilus[] tmpTomb = getStilusuKonyvek(tomb, stilus);
		double sum = 0;

		for (KonyvStilus konyvStilus : tmpTomb) {
			sum += konyvStilus.getAr();
		}

		return sum / tmpTomb.length;
	}

}