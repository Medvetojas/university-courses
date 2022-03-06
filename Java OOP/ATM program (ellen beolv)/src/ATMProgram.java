import java.util.Scanner;

public class ATMProgram {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int moneyAmount;
		do {
			System.out.print("Adja meg a felvenni kivant osszeget: ");
			while(!input.hasNextInt()) {
				System.out.println("Ervenytelen szam!");
				input.next();
			}
			moneyAmount = input.nextInt();
		} while(moneyAmount < 5 || moneyAmount % 5 != 0);
		input.close();
		
		int remainingAmount = moneyAmount;
		int currencies[] = {20_000, 10_000, 5_000, 2_000, 1_000, 500, 200, 100, 50, 20, 10, 5};
		int counterbycurr[] = new int[currencies.length];
		
		for (int i = 0; i < currencies.length; i++) {
			counterbycurr[i] = remainingAmount / currencies[i];
			remainingAmount = remainingAmount % currencies[i];
		}
		
		int counter = 0;
		for (int i = 0; i < counterbycurr.length; i++) {
			counter += counterbycurr[i];
		}
		System.out.println("A megadott penzosszeg " + counter + " db cimletben adhato ki.");
		System.out.println("A szukseges cimletek:");
		
		for(int i =0; i<currencies.length; i++) {
			System.out.println(currencies[i] + " Ft: " + counterbycurr[i]);
		}
		
	}
}
