package demo;

import java.util.Scanner;
import planet.Planet;


public class Demo {

	public static void main(String[] args) {
		int foldTomeg = read();
		
		double mass = foldTomeg / Planet.EARTH.getSurfaceGravity();
		
		for (Planet p : Planet.values()) {
			System.out.printf("A tömeged a %s: %f \n", p, p.surfaceWeight(mass));
		}

		
	}

	public static int read() {
		Scanner sc = new Scanner(System.in);
		int number = 0;

		do {
			System.out.println("Kérem a tömeget: ");
			while (!sc.hasNextInt()) {
				System.out.println("Ez nem egy tömeg!");
				sc.nextLine();
			}
			number = sc.nextInt();

		} while (number < 1 || number > 200);

		return number;
	}

}
