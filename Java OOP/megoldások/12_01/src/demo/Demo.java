package demo;

import bank.Bankszamla;
import kivetelek.InsufficientFundsException;

public class Demo {

	public static void main(String[] args) {

		Bankszamla otp = new Bankszamla(101101);
		System.out.println(otp);
		otp.penzBevet(1000);
		System.out.println(otp);

		try {
			otp.penzKivet(320);
			otp.penzBevet(200);
			otp.penzKivet(320);
			otp.penzKivet(2320);
		} catch (InsufficientFundsException e) {
			e.printStackTrace();
			System.out.println("Nincs eleg zseton! A hianyzo osszeg: " + e.getHianyzoOsszeg());
		} catch (Exception e) {
			System.out.println("talcsika: " + e.getMessage());
		} finally {
			System.out.println(otp);
		}

	}

}
