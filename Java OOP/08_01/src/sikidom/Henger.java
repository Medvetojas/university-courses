package sikidom;

public class Henger extends Hasab {
	private double r;

	public Henger(int magassag, double r) {
		super(magassag);
		this.r = r;
	}

	@Override
	public String toString() {
		return "sugar:" + this.r + " magassag:" + super.getMagassag() + " terfogat:" + super.getTerfogat();
	}

	@Override
	public double getAlapTerulet() {
		return this.r * this.r * Math.PI;
	}

}
