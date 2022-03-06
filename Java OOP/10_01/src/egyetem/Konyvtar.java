package egyetem;

public class Konyvtar extends SzervezetiEgyseg {
	private int konyvekSzama;

	public Konyvtar(int letszam, int konyvekSzama) {
		super("Könyvtár", letszam);
		this.konyvekSzama = konyvekSzama;
	}

	@Override
	public String toString() {
		return "Konyvtar [konyvekSzama=" + konyvekSzama + "]";
	}

	public int getKonyvekSzama() {
		return konyvekSzama;
	}

	public void setKonyvekSzama(int konyvekSzama) {
		this.konyvekSzama = konyvekSzama;
	}

	@Override
	public double getMunkaMennyiseg() {
		return this.konyvekSzama / getLetszam();
	}

}
