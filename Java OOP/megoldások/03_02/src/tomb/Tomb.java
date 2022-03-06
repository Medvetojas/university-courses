package tomb;

import java.util.Arrays;

public class Tomb {

	public static void main(String[] args) {
		int[] tomb = new int[10];
		double[] tomb2 = new double[10];

		feltolt(tomb);
		kiir(tomb);
		Arrays.sort(tomb);
		System.out.println("Rendezes utan:");
		kiir(tomb);
		
		
		System.out.println("Binaris kereses: " + Arrays.binarySearch(tomb, 5));
		System.out.println("Legnagyobb paros: " + getLegnagyobbParos(tomb));
		System.out.println("Legnagyobb paros: " + getLegnagyobbParosForEach(tomb));
		System.out.println("Negyzetszam szama: " + getNegyzetszamokSzama(tomb));
		System.out.println("Tomb egyezoseg: " + Arrays.equals(tomb, tomb));
		
		
		System.out.println();
		
		for (int i = 0; i < tomb2.length; i++) {
			tomb2[i] = (Math.random() * 50) + 1;
		}
		
		for (int i = 0; i < tomb2.length; i++) {
			System.out.println(tomb2[i]);
		}

		System.out.println("Mertani atlag:: " + mertaniAtlag(tomb2));

	}

	
	
	private static void feltolt(int[] tomb) {
		for (int i = 0; i < tomb.length; i++) {
			tomb[i] = (int) (Math.random() * 50) + 1;
		}
	}

	private static void kiir(int[] tomb) {
		// for(int i=0;i<tomb.length;i++)
		// System.out.println(tomb[i]);

		for (int szam : tomb)
			System.out.println("Elem: " + szam);
	}

	private static int getLegnagyobbParos(int[] tomb) {
		int max = -1;

		for (int i = 0; i < tomb.length; i++) {
			if (tomb[i] % 2 == 0 && tomb[i] > max) {
				max = tomb[i];
			}
		}

		return max;
	}

	private static int getLegnagyobbParosForEach(int[] tomb) {
		int max = -1;

		for (int szam : tomb) {
			if (szam % 2 == 0 && szam > max) {
				max = szam;
			}
		}

		return max;
	}

	private static int getNegyzetszamokSzama(int[] tomb) {
		int db = 0;

		for (int szam : tomb) {
			if (Math.sqrt(szam) % 1 == 0) {
				db++;
				System.out.println("Negyzetszam: " + szam);
			}

		}

		return db;
	}
	
	
	private static double mertaniAtlag(double[] tomb) {
		double mean = 1;

		for (double item : tomb) {
			mean *= item;
		}

		return Math.pow(mean, 1.0 / (double) tomb.length);
	}
	
	
	

}
