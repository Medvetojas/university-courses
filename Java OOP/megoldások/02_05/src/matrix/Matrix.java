package matrix;

import java.util.Scanner;

public class Matrix {

	public static void main(String[] args) {

		int[][] matrix = new int[5][3];
		feltolt(matrix);
		//System.out.println(matrix.length + " " + matrix[0].length);
		kiir(matrix);

		int keresett = readInt();
		System.out.println(lin_kereses(matrix, keresett));
	}
	

	public static void feltolt(int[][] tomb) {
		for (int i = 0; i < tomb.length; i++) {
			for (int j = 0; j < tomb[0].length; j++) {
				tomb[i][j] = (int) (Math.random() * 50) + 1;
			}
		}
	}

	public static void kiir(int[][] tomb) {
		for (int i = 0; i < tomb.length; i++) {
			for (int j = 0; j < tomb[0].length; j++) {
				System.out.print(tomb[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static int readInt() {
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

		return n;

	}

	private static boolean lin_kereses(int[][] matrix, int keresett) {
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[0].length; j++) {
				if (matrix[i][j] == keresett)
					return true;
			}

		}

		return false;
	}

}