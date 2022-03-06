package teglalap;

import java.util.Scanner;

public class Fut {

	public static void main(String[] args) {
		Teglalap teglalapTomb[] = new Teglalap[10];

		feltolt(teglalapTomb);
		kiir(teglalapTomb);
		System.out.println("A legkisebb teruletu teglalap adatait: " + legkisebbTerulet(teglalapTomb));

		Teglalap uj;
		Scanner sc = new Scanner(System.in);
		System.out.println("Uj teglalap!");
		System.out.println("Kerem az a oldalt:");
		int a = sc.nextInt();
		System.out.println("Kerem a b oldalt:");
		int b = sc.nextInt();
		uj = new Teglalap(a, b);
		System.out.println(uj);
		
		System.out.println("A " + uj.getTerulet() + " nagyobb teruletu taglalapok szama: " + getTeruletNagyobb(teglalapTomb,uj));
		
		
		System.out.println(getVanEEgyezoSzoveg(teglalapTomb, uj));
		
	}
	

	private static String getVanEEgyezoSzoveg(Teglalap[] teglalapTomb, Teglalap uj) {
		int keresEgyezoAdatok = keresEgyezoAdatok(teglalapTomb,uj);

		if(keresEgyezoAdatok != -1) {
			return "Az egyezo adatokkal rendelekezo teglalap indexe:" + keresEgyezoAdatok;
		} else {
			return "Nincs egyezo!";
		}
	}

	private static void kiir(Teglalap[] teglalapTomb) {
		for (Teglalap teglalap : teglalapTomb) {
			System.out.println(teglalap.toString());
		}
	}

	private static void feltolt(Teglalap[] teglalapTomb) {
		for (int i = 0; i < teglalapTomb.length; i++) {
			teglalapTomb[i] = new Teglalap((int) (Math.random() * 8 + 2), (int) (Math.random() * 8 + 2));
		}
	}

	private static Teglalap legkisebbTerulet(Teglalap[] teglalapTomb) {
		Teglalap min = teglalapTomb[0];

		for (Teglalap teglalap : teglalapTomb) {
			if (teglalap.getTerulet() < min.getTerulet()) {
				min = teglalap;
			}
		}

		return min;
	}
	
	public static int getTeruletNagyobb(Teglalap[] tomb, Teglalap t) {
		int db = 0;
		
		for (Teglalap teglalap : tomb) {
			if(teglalap.getTerulet() > t.getTerulet())
				db++;
		}
		
		return db;
	}
	
	
	public static int keresEgyezoAdatok(Teglalap[] tomb, Teglalap t) {
		int index = -1;
		
		for (int i = 0; i < tomb.length; i++) {
			if(tomb[i].getOldalakEgyeznekE(t)) {
				index = i;
				break;
			}
		}
		
		return index;	
	}

}
