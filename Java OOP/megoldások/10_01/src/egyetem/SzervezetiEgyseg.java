package egyetem;

public abstract class SzervezetiEgyseg {
	private String nev;
	private int letszam;

	public SzervezetiEgyseg(String nev, int letszam) {
		super();
		this.nev = nev;
		this.letszam = letszam;
	}

	@Override
	public String toString() {
		return "SzervezetiEgyseg [nev=" + nev + ", letszam=" + letszam + "]";
	}

	public String getNev() {
		return nev;
	}

	public void setNev(String nev) {
		this.nev = nev;
	}

	public int getLetszam() {
		return letszam;
	}

	public void setLetszam(int letszam) {
		this.letszam = letszam;
	}
	
	public abstract double getMunkaMennyiseg();

}
