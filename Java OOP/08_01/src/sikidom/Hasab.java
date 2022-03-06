package sikidom;

public abstract class Hasab {
	private int magassag;

	public Hasab(int magassag) {
		super();
		this.magassag = magassag;
	}

	public int getMagassag() {
		return magassag;
	}

	public void setMagassag(int magassag) {
		this.magassag = magassag;
	}

	public abstract double getAlapTerulet();

	public double getTerfogat() {
		return getAlapTerulet() * this.magassag;
	}

	public boolean getNagyobbTerfogat(Hasab h) {
		if (this.getTerfogat() > h.getTerfogat()) {
			return true;
		}

		return false;
	}

}
