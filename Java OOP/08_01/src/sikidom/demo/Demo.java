package sikidom.demo;

import sikidom.Henger;
import sikidom.Teglatest;

public class Demo {

	public static void main(String[] args) {
		Henger henger = new Henger(5, 3);
		System.out.println(henger);
		System.out.println("Henger terfogata: " + henger.getTerfogat());

		Teglatest teglatest = new Teglatest(6, 4, 5);
		System.out.println(teglatest);
		System.out.println("Teglatest terfogata: " + teglatest.getTerfogat());

		
		if(henger.getNagyobbTerfogat(teglatest)) {
			System.out.println("A henger terfogata a nagyobb.");
		} else {
			System.out.println("A teglatest terfogata a nagyobb.");

		}
	}

}
