package Hanglemez;

import java.util.Scanner;

public class Fut {

	public static void main(String[] args) {
		Hanglemez[] h = new Hanglemez[3];

		feltolt(h);
		kiir(h);

		System.out.println(getEloado(h, "Tomi"));
	}

	private static void feltolt(Hanglemez[] h) {
		Scanner sc = new Scanner(System.in);

		for (int i = 0; i < h.length; i++) {
			System.out.println("Kerem az " + i + "." + "hanglemez eloadojat:");
			String eloado = sc.next();
			System.out.println("Kerem az " + i + "." + "hanglemez cimet:");
			String cim = sc.next();
			System.out.println("Kerem az " + i + "." + "hanglemez hosszat:");
			int hossz = sc.nextInt();

			h[i] = new Hanglemez(eloado, cim, hossz);
		}
	}

	private static void kiir(Hanglemez[] h) {
		for (Hanglemez hanglemez : h) {
			System.out.println(hanglemez.toString());
		}
	}

	public static String getEloado(Hanglemez[] hTomb, String eloado) {
		for (Hanglemez hanglemez : hTomb) {
			if (hanglemez.getSzerzoEgyezikE(eloado))
				return hanglemez.getEloado();
		}

		return "";
	}

}
