package egyenlet;

import java.util.Scanner;
import static java.lang.Math.sqrt;

public class Masokfoku {

	public static void main(String[] args) {
		double discriminant = 0;
		double x1, x2 = 0;	
		int a = 0, b = 0, c = 0;
		boolean ok;
		
		Scanner input = new Scanner(System.in);
		
		do {
			System.out.print("Az egyenlet konstansai vesszõvel elválasztva: ");
			String inString = input.nextLine();
			String[] strArray = inString.split(",");
			
			ok = true;
			
			try {
				a = Integer.parseInt(strArray[0]);
				b = Integer.parseInt(strArray[1]);
				c = Integer.parseInt(strArray[2]);
			} catch (NumberFormatException ex) {
				System.out.println(ex.getMessage());
				ok = false;
			}
		} while (!ok);
		
		input.close();

		discriminant = getDiscriminant(a, b, c);

		if (discriminant < 0) {
			System.out.println("Nincs valós megoldás!");
		} else {
			x1 = getEgyutthato1(a,b, discriminant);
			x2 = getEgyutthato2(a,b, discriminant);

			System.out.println("A megoldások: " + "x1:" + x1 + " x2:" + x2);
		}
	}

	
	
	
	
	private static double getDiscriminant(int a, int b, int c) {
		return (b * b) - (4 * a * c);
	}
	
	private static double getEgyutthato1(int a, int b, double discriminant) {
		return (b * (-1) + sqrt(discriminant)) / (2 * a);
	}
	
	private static double getEgyutthato2(int a, int b, double discriminant) {
		return (b * (-1) - sqrt(discriminant)) / (2 * a);
	}

}
