package feladat;

public class Leibniz {

	public static void main(String[] args) {
		int numerator = 1;
		int denominator = 1;
		double pi = 0;

		for (int i = 1; i <= 1000; i++) {
			if (i % 2 == 1) {
				pi += (double) numerator / denominator;
			} else {
				pi -= (double) numerator / denominator;
			}
			denominator = denominator + 2;
		}

		System.out.println("A pi kozelitett erteke: " + (4 * pi));
	}

}
