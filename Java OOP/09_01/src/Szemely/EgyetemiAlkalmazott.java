package Szemely;

public class EgyetemiAlkalmazott extends Alkalmazott implements Comparable<EgyetemiAlkalmazott> {
	private Beosztas beosztas;
	private static int alapber = 500000;

	public EgyetemiAlkalmazott(String nev, int kor, String munkahely, Beosztas beosztas) {
		super(nev, kor, munkahely, 0);
		this.beosztas = beosztas;

		switch (beosztas) {
		case PROF:
			setFizetes(alapber);
			break;
		case OKTATO:
			setFizetes(alapber * 50 / 100);
			break;
		case ADMIN:
			setFizetes(alapber * 30 / 100);
			break;
		}
	}

	@Override
	public String toString() {
		return "EgyetemiAlkalmazott [beosztas=" + beosztas + "]" + " " + super.toString();
	}

	public Beosztas getBeosztas() {
		return beosztas;
	}

	public void setBeosztas(Beosztas beosztas) {
		this.beosztas = beosztas;
	}

	public static int getAlapber() {
		return alapber;
	}

	public static void setAlapber(int alapber) {
		EgyetemiAlkalmazott.alapber = alapber;
	}

	@Override
	public int compareTo(EgyetemiAlkalmazott o) {
		return this.getKor() - o.getKor();
	}

}
