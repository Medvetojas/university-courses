package egyetem.demo;

import java.util.*;
import java.util.Comparator;
import egyetem.Kar;
import egyetem.KarNev;
import egyetem.Konyvtar;
import egyetem.SzervezetiEgyseg;

public class Demo {

	public static void main(String[] args) {
		List<SzervezetiEgyseg> lista = new ArrayList<SzervezetiEgyseg>();

		lista.add(new Konyvtar(20, 40000));
		lista.add(new Kar(KarNev.MAK));
		lista.add(new Kar(KarNev.MFK, 100, 500));
		lista.add(new Kar(KarNev.ÁJK, 40, 100));
		lista.add(new Kar(KarNev.GÉIK, 200, 600));

		Comparator<SzervezetiEgyseg> c = new Comparator<SzervezetiEgyseg>() {
			@Override
			public int compare(SzervezetiEgyseg o1, SzervezetiEgyseg o2) {
				return o1.getNev().compareTo(o2.getNev());
			}
		};
		lista.sort(c);
		kiir(lista);

		lista.sort(Comparator.comparing(SzervezetiEgyseg::getLetszam));
		System.out.println();
		kiir(lista);
		
		
		System.out.println();
		System.out.println("Össz hallgatói létszám: " + getOsszHallgatoiLetszam(lista));
		
		
		SzervezetiEgyseg[] listaTomb = new SzervezetiEgyseg[lista.size()];
		lista.toArray(listaTomb);
		
		System.out.println();
		for (SzervezetiEgyseg szervezetiEgyseg : listaTomb) {
			System.out.println(szervezetiEgyseg);
		}
		
	}
	
	
	

	private static void kiir(List<SzervezetiEgyseg> lista) {
		for (SzervezetiEgyseg szervezetiEgyseg2 : lista) {
			System.out.println(szervezetiEgyseg2);
		}
	}

	private static int getOsszHallgatoiLetszam(List<SzervezetiEgyseg> lista) {
		int sum = 0;

		for (SzervezetiEgyseg szervezetiEgyseg2 : lista) {
			if (szervezetiEgyseg2 instanceof Kar) {
				sum += ((Kar) szervezetiEgyseg2).getHallgatoLetszam();
			}
		}

		return sum;
	}

}
