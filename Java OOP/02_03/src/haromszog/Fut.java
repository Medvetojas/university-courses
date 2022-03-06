package haromszog;

import java.util.Scanner;

public class Fut {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n;

		do {
			System.out.println("Enter a number between 1 and 9");
			while (!input.hasNextInt()) {
				System.out.println("That's not a number");
				input.next();
			}
			n = input.nextInt();
		} while (n < 1 || n > 9);
		input.close();

		System.out.println("n = " + n);

		cimke: for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				System.out.print(i);

				if (i == j) {
					System.out.print("\n");
					continue cimke;
				}

			}

		}

	}

}
