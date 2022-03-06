package rel_prim;

import java.util.*;

public class Prim {

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int n;

		do {
			System.out.println("Enter a number between 1 and 10");
			while (!input.hasNextInt()) {
				System.out.println("That's not a number");
				input.next();
			}
			n = input.nextInt();
		} while (n < 1 || n > 10);
		input.close();

		// System.out.println("n = " + n);

		int db = 0;
		for (int i = 10, j = i + 1; db < n; i++, j++) {
			if (rel_prim(i, j)) {
				db++;
				System.out.println("Relatic primek: " + i + " " + j);
			}
		}

		System.out.println(db + " darab relativ prim van.");
	}

	public static boolean rel_prim(int a, int b) {
		if (lnko(a, b) == 1)
			return true;

		return false;
	}

	public static int lnko(int a, int b) {
		while (b != 0) {
			int tmp = b;
			b = a % b;
			a = tmp;
		}

		return a;
	}

}
