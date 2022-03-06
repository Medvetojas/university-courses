package hasabTarol;

import sikidom.Hasab;
import sikidom.Henger;

public class HasabTarol {
	private Hasab[] hasabok;

	public HasabTarol(int hasabokSzama) {
		this.hasabok = new Hasab[hasabokSzama];
	}

	public void set(Hasab hasab, int index) {
		this.hasabok[index] = hasab;
	}

	public int getHasabokSzama() {
		return this.hasabok.length;
	}

	public int getNemNullElemekSzama() {
		int db = 0;

		for (Hasab hasab : hasabok) {
			if (hasab != null) {
				db++;
			}
		}

		return db;
	}

	public Hasab getIndexuElem(int index) {
		return this.hasabok[index];
	}

	public double getAtlagosTerfogat() {
		double sum = 0;

		for (Hasab hasab : hasabok) {
			if (hasab != null) {
				sum += hasab.getTerfogat();
			}
		}

		return sum / getNemNullElemekSzama();
	}

	public int getHengerHasabokSzama() {
		int db = 0;

		for (Hasab hasab : hasabok) {
			if (hasab instanceof Henger) {
				db++;
			}
		}

		return db;
	}

}
