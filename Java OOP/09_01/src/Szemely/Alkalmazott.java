package Szemely;

public class Alkalmazott extends Szemely {
	private String munkahely;
	private int fizetes;

	public Alkalmazott(String nev, int kor, String munkahely, int fizetes) {
		super(nev, kor);
		this.munkahely = munkahely;
		this.fizetes = fizetes;
	}

	@Override
	public String toString() {
		return "Alkalmazott [munkahely=" + munkahely + ", fizetes=" + fizetes + "]" + "  " + super.toString() ;
	}

	public String getMunkahely() {
		return munkahely;
	}

	public void setMunkahely(String munkahely) {
		this.munkahely = munkahely;
	}

	public int getFizetes() {
		return fizetes;
	}

	public void setFizetes(int fizetes) {
		this.fizetes = fizetes;
	}

}
