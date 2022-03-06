package Szemely;

import java.util.Arrays;
import java.util.Comparator;

public class AlkalmazottDemo {

	public static void main(String[] args) {
		EgyetemiAlkalmazott[] alkalmazottak = new EgyetemiAlkalmazott[5];

		alkalmazottak[0] = new EgyetemiAlkalmazott("Tomi", 32, "IIT", Beosztas.OKTATO);
		alkalmazottak[1] = new EgyetemiAlkalmazott("Szivleszter", 55, "IIT", Beosztas.PROF);
		alkalmazottak[2] = new EgyetemiAlkalmazott("Miki", 40, "IIT", Beosztas.OKTATO);
		alkalmazottak[3] = new EgyetemiAlkalmazott("Erika", 40, "IIT", Beosztas.OKTATO);
		alkalmazottak[4] = new EgyetemiAlkalmazott("Mónika", 18, "IIT", Beosztas.ADMIN);

		kiir(alkalmazottak);

		System.out.println();
		System.out.println("Statisztika:");
		statisztika(alkalmazottak);
		
		System.out.println("Kor szerint rendezve:");
		Arrays.sort(alkalmazottak);
		kiir(alkalmazottak);
		
		System.out.println();
		System.out.println("Nev szerint rendezve:");
		Arrays.sort(alkalmazottak, new NameSorter());
		kiir(alkalmazottak);
		
		
		System.out.println();
		System.out.println("Kor szerint rendezve Java8:");
		Arrays.sort(alkalmazottak, Comparator.comparing(Szemely::getKor));
		kiir(alkalmazottak);
		
		
		System.out.println();
		System.out.println("Kor szerint csokkeno sorrendbe rendezve Java8:");
		Comparator<Alkalmazott> compByAge = Comparator.comparing(Szemely::getKor);
		Arrays.sort(alkalmazottak, compByAge.reversed());
		kiir(alkalmazottak);
		
		
		
		System.out.println();
		System.out.println("Java8 rednezes tobb szempont szerint:");
		Arrays.sort(alkalmazottak, Comparator.comparing(Alkalmazott::getFizetes).
				thenComparing(Szemely::getKor).
				thenComparing(Szemely::getNev));
		kiir(alkalmazottak);
	}

	private static void kiir(Alkalmazott[] alkalmazottak) {
		for (Alkalmazott alkalmazott : alkalmazottak) {
			System.out.println(alkalmazott);
		}
	}

	public static void statisztika(EgyetemiAlkalmazott[] alkalmazottak) {
		next: for (int i = 0; i < alkalmazottak.length; i++) {
			Beosztas beosztas = alkalmazottak[i].getBeosztas();

			for (int j = 0; j < i; j++) {
				if (alkalmazottak[j].getBeosztas() == beosztas) {
					continue next;
				}
			}

			System.out.print(alkalmazottak[i].getBeosztas() + ": ");
			int counter = 1;
			for (int j = i + 1; j < alkalmazottak.length; j++) {
				if (alkalmazottak[i].getBeosztas() == alkalmazottak[j].getBeosztas()) {
					counter++;
				}
			}

			System.out.println(counter);
		}
		System.out.println();

	}

}