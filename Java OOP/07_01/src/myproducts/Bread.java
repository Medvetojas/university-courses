package myproducts;

public class Bread extends Product {
	private double mennyiseg;

	public Bread(String nev, int ar, int afakulcs, double mennyiseg) {
		super(nev, ar, afakulcs);
		this.mennyiseg = mennyiseg;
	}

	@Override
	public String toString() {
		return "Bread [" + super.toString() + " egysegar:" + getEgysegar() + "]";
	}

	public int getEgysegar() {
		return (int) (super.getBruttoAr() / this.mennyiseg);
	}

	public double getMennyiseg() {
		return mennyiseg;
	}

	public void setMennyiseg(double mennyiseg) {
		this.mennyiseg = mennyiseg;
	}

	public static boolean egysegarHasonlit(Bread b1, Bread b2) {
		if (b1.getEgysegar() > b2.getEgysegar())
			return true;

		return false;
	}

}
