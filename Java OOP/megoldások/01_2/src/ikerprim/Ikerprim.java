package ikerprim;

public class Ikerprim {

	public static void main(String[] args) {
		int db = 0;

		for (int i = 1; i <= 100; i++) {
			for (int j = i + 1; j < 100; j++) {

				if (ikerPrim(i, j)) {
					System.out.println(i + " " + j);
					db++;
				}

			}
		}

		System.out.println("1-100 kozotti ikerprimek szama: " + db);
	}

	private static boolean ikerPrim(int a, int b) {
		if (prim(a) && prim(b) && difference(a, b) == 2) {
			return true;
		}

		return false;
	}

	private static boolean prim(int number) {
		for (int i = 2; i <= number / 2; i++) {
			if (number % i == 0) {
				return false;
			}

		}

		return true;
	}

	private static int difference(int a, int b) {
		return Math.abs(a - b);
	}

}