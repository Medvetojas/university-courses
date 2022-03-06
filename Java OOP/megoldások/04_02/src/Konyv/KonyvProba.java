package Konyv;

public class KonyvProba {

	public static void main(String[] args) {
		Konyv k1 = new Konyv();

		k1.setAr(1200);
		k1.setCim("Nemtudom");
		k1.setEv(2020);
		k1.setSzerzo("En");

		System.out.println(k1.toString());
		
		Konyv k2 = new Konyv();

		k2.setAr(2200);
		k2.setCim("Nemtudom2");
		k2.setEv(2021);
		k2.setSzerzo("En2");

		System.out.println(k2.toString());

	}

}
