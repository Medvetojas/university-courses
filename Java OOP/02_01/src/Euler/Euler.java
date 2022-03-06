package Euler;

public class Euler {

	public static void main(String[] args) {
		double e_number = 0;

		for (int n = 0; n <= 10; n++) {
			e_number += 1.0 / factorial(n);
		}
		System.out.println("Az e szam: " + e_number);
	}

	public static int factorial(int number) {
		int fact = 1;
		while (number > 0) {
			fact *= number;
			number--;
		}

		return fact;
	}

}