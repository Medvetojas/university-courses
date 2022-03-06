package fajlkezeles;

public class Ember {
	private String nev;
	private int eletkor;

	public Ember(String nev, int eletkor) {
		super();
		this.nev = nev;
		this.eletkor = eletkor;
	}

	public String getNev() {
		return nev;
	}

	public void setNev(String nev) {
		this.nev = nev;
	}

	public int getEletkor() {
		return eletkor;
	}

	public void setEletkor(int eletkor) {
		this.eletkor = eletkor;
	}

	@Override
	public String toString() {
		return "Ember [nev=" + nev + ", eletkor=" + eletkor + "]";
	}

}
