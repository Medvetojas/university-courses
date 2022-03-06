package tomb;

public class Tomb {
	public static void main(String[] args) {
		int[] tomb = new int[10];

		feltolt(tomb);

		for (int i = 0; i < tomb.length; i++) {
			System.out.println(tomb[i]);
		}

		System.out.println("");

		for (int i = tomb.length - 1; i >= 0; i--) {
			System.out.println(tomb[i]);
		}

		System.out.println("Paros szamok atlaga: " + parosSzamokAtlaga(tomb));

		
		
		int min = tomb[0];
		for (int i = 0; i < tomb.length; i++) {
			if(tomb[i] < min) {
				min = tomb[i];
			}
		}
		System.out.println("A tomb legkisebb eleme: " + min);
		
	}

	
	private static void feltolt(int[] tomb) {
		for (int i = 0; i < tomb.length; i++) {
			tomb[i] = (int) (Math.random() * 50) + 1;
		}
	}

	
	private static double parosSzamokAtlaga(int[] tomb) {
		int sum = 0;

		for (int i = 0; i < tomb.length; i++) {
			if (tomb[i] % 2 == 0) {
				sum += tomb[i];
			}
		}

		return (double) sum / tomb.length;
	}

}
