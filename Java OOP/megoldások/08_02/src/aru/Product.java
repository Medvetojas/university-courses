package aru;

public class Product {
	private String nev;
	private int ar;
	private int afakulcs;

	public Product(String nev, int ar, int afakulcs) {
		super();
		this.nev = nev;
		this.ar = ar;
		this.afakulcs = afakulcs;
	}

	public int getBruttoAr() {
		return this.ar + (this.ar * this.afakulcs / 100);
	}

	@Override
	public String toString() {
		return "Product [nev=" + nev + ", ar=" + ar + "]";
	}

	public void arNovelSzazalekkal(int szazalek) {
		this.ar += this.ar * szazalek / 100;
	}

	public int melyikDragabb(Product p) {
		if (this.getBruttoAr() > p.getBruttoAr())
			return 1;
		else if (this.getBruttoAr() == p.getBruttoAr())
			return 0;

		return -1;
	}

}
