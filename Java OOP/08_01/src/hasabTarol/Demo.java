package hasabTarol;

import sikidom.Henger;
import sikidom.Teglatest;

public class Demo {

	public static void main(String[] args) {
		HasabTarol hasabTarol = new HasabTarol(5);
		
		Henger h1 = new Henger(5,6);
		Henger h2 = new Henger(2,2);
		Teglatest teglatest = new Teglatest(6, 2, 3);
		
		hasabTarol.set(h1, 0);
		hasabTarol.set(h2, 1);
		hasabTarol.set(teglatest, 2);

		for (int i = 0; i < hasabTarol.getHasabokSzama(); i++) {
			System.out.println(hasabTarol.getIndexuElem(i));
		}
		
		System.out.println("A hasabok atlagos terfogata: " + hasabTarol.getAtlagosTerfogat());
		
		System.out.println("A henger hasabok szama: " + hasabTarol.getHengerHasabokSzama());
	}

}
