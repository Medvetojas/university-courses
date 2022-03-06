package a;

public class Alkalmazott {
	private String nev;
	private int kor;
	private long fizetes;
	
	private static int nyugdijKorhatar = 65;

	public Alkalmazott(String nev, int kor, long fizetes) {
		super();
		this.nev = nev;
		this.kor = kor;
		this.fizetes = fizetes;
	}
	
	public Alkalmazott(String nev, int kor) {
		this(nev, kor, 10000*kor);
	}
	
	public int getEvekSzamaNyugdijig() {
		return Alkalmazott.nyugdijKorhatar - this.getKor();
	}

	@Override
	public String toString() {
		return "nev:" + nev + " kor:" + kor + " fizetes:" + fizetes + " evek szama a nyugdijig:" + getEvekSzamaNyugdijig();
	}
	
	public static Alkalmazott getFitalabb(Alkalmazott alk1, Alkalmazott alk2) {
		if(alk1.getEvekSzamaNyugdijig() > alk2.getEvekSzamaNyugdijig()) {
			return alk1;
		} else
			return alk2;
	}
	
	public static void setNyugdijKorhatar(int nyugdijKorhatar) {
		Alkalmazott.nyugdijKorhatar = nyugdijKorhatar;
	}

	
	public String getNev() {
		return nev;
	}

	public void setNev(String nev) {
		this.nev = nev;
	}

	public int getKor() {
		return kor;
	}

	public void setKor(int kor) {
		this.kor = kor;
	}

	public long getFizetes() {
		return fizetes;
	}

	public void setFizetes(long fizetes) {
		this.fizetes = fizetes;
	}

	public static int getNyugdijKorhatar() {
		return nyugdijKorhatar;
	}
}