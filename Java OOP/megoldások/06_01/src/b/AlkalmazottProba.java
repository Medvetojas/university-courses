package b;

import java.time.LocalDate;
import java.util.Iterator;
import java.util.Scanner;

public class AlkalmazottProba {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		System.out.println("Kerem az alkalmazottak szamat:");
		int n = sc.nextInt();
		sc.nextLine();

		Alkalmazott alkTomb[] = new Alkalmazott[n];

		for (int i = 0; i < alkTomb.length; i++) {
			System.out.println((i + 1) + " Kerem a nevet:");
			String nev = sc.nextLine();
			
			System.out.println((i + 1) + " Kerem a szueltesi datumot (yyyy/mm/dd):");
			String instring = sc.nextLine();
			String[] birthdayComponents = instring.split("/");
			int ev = Integer.parseInt(birthdayComponents[0]);
			int honap = Integer.parseInt(birthdayComponents[1]);
			int nap = Integer.parseInt(birthdayComponents[2]);
			LocalDate szulDatum = LocalDate.of(ev,honap,nap);
			
			System.out.println((i + 1) + " Kerem a fezetest:");
			long fizetes = sc.nextLong();
			sc.nextLine();

			alkTomb[i] = new Alkalmazott(nev, szulDatum, fizetes);
		}

		kiir(alkTomb);
		
		System.out.println("Nyugdikkorhatar modosítasa!");
		Alkalmazott.setNyugdijKorhatar(40);
		kiir(alkTomb);
		
		
		System.out.println("5 evnel kevesebb van hatra:");
		getOtEvnelKevesebbVanHatra(alkTomb);

		System.out.println("Az atlagnal tobb van hatra:");
		getAtlagnalTobb(alkTomb);

		System.out.println("Rendezett tomb:");
		tombRendezeseNyugdijigHatraLevoEvekAlapjan(alkTomb);
		kiir(alkTomb);
	}

	private static void kiir(Alkalmazott[] alkTomb) {
		for (Alkalmazott alkalmazott : alkTomb) {
			System.out.println(alkalmazott);
		}
	}

	private static void getOtEvnelKevesebbVanHatra(Alkalmazott[] alkTomb) {
		for (Alkalmazott alkalmazott : alkTomb) {
			if (alkalmazott.getEvekSzamaNyugdijig() <= 5)
				System.out.println(alkalmazott);
		}
	}

	private static void getAtlagnalTobb(Alkalmazott[] alkTomb) {
		double atlag = getAtlagEvekNyugdijig(alkTomb);

		for (Alkalmazott alkalmazott : alkTomb) {
			if (alkalmazott.getEvekSzamaNyugdijig() > atlag) {
				System.out.println(alkalmazott);
			}
		}
	}

	private static double getAtlagEvekNyugdijig(Alkalmazott[] alkTomb) {
		double sum = 0;

		for (Alkalmazott alkalmazott : alkTomb) {
			sum += alkalmazott.getEvekSzamaNyugdijig();
		}

		return sum / alkTomb.length;
	}

	private static void tombRendezeseNyugdijigHatraLevoEvekAlapjan(Alkalmazott[] employeeArray) {
		for (int i = 0; i < employeeArray.length; i++) {
			int minIndex = i;
			for (int j = i + 1; j < employeeArray.length; j++) {
				if (employeeArray[j].getEvekSzamaNyugdijig() < employeeArray[minIndex].getEvekSzamaNyugdijig()) {
					minIndex = j;
				}
			}
			// Helycsere, ha szükséges
			if (minIndex != i) {
				Alkalmazott tmp = employeeArray[i];
				employeeArray[i] = employeeArray[minIndex];
				employeeArray[minIndex] = tmp;
			}
		}
	}

}
