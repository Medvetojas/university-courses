package sikidom;

public class Teglatest extends Hasab {
	private double a;
	private double b;

	public Teglatest(int magassag, double a, double b) {
		super(magassag);
		this.a = a;
		this.b = b;
	}

	@Override
	public double getAlapTerulet() {
		return this.a * this.b;
	}

	@Override
	public String toString() {
		return "a:" + this.a + " b:" + b + " magassag:" + super.getMagassag() + " terfogat:" + super.getTerfogat();
	}

}
