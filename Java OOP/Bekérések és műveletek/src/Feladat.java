import java.util.Scanner;

public class Feladat {
	
	public static double osszeadas(double elsoszam, double masodikszam) {
		return elsoszam + masodikszam;
	}
	
	public static double kivonas(double elsoszam, double masodikszam) {
		return elsoszam - masodikszam;
	}
	
	public static double szorzas(double elsoszam, double masodikszam) {
		return elsoszam * masodikszam;
	}
	
	public static double osztas(double elsoszam, double masodikszam) {
		return elsoszam / masodikszam;
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Add meg az elso szamot: ");
		double elsoszam = scanner.nextDouble();
		scanner.nextLine();
		
		System.out.print("Add meg a masodik szamot: ");
		double masodikszam = scanner.nextDouble();
		scanner.nextLine();
		
		System.out.print("Add meg a muveletet: (osszeadas, kivonas, szorzas, osztas): ");
		String muvelet = scanner.nextLine();
		
		scanner.close();
		
		
		switch(muvelet) {
			case "osszeadas":
				System.out.println("Az osszeadas eredmenye: " + osszeadas(elsoszam, masodikszam));
				break;
			case "kivonas":
				System.out.println("A kivonas eredmenye: " + kivonas(elsoszam, masodikszam));
				break;
			case "szorzas":
				System.out.println("A szorzas eredmenye: " + szorzas(elsoszam, masodikszam));
				break;
			case "osztas":
				System.out.println("Az osztas eredmenye: " + osztas(elsoszam, masodikszam));
				break;
			default:
				System.out.println("Hibas muveletmegadas!");
		}

		}
	}