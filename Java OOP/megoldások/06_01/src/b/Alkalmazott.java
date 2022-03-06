package b;

import java.time.LocalDate;

public class Alkalmazott {
	private String nev;
	private LocalDate szulDatum;
	private long fizetes;

	private static int nyugdijKorhatar = 65;

	private static String[] honapNevek;

	static {
		honapNevek = new String[13];
		honapNevek[0] = " ";
		honapNevek[1] = "januar";
		honapNevek[2] = "februar";
		honapNevek[3] = "marcius";
		honapNevek[4] = "aprilis";
		honapNevek[5] = "majus";
		honapNevek[6] = "junius";
		honapNevek[7] = "julius";
		honapNevek[8] = "augusztus";
		honapNevek[9] = "szeptember";
		honapNevek[10] = "oktober";
		honapNevek[11] = "november";
		honapNevek[12] = "december";
	}

	public Alkalmazott(String nev, LocalDate szulDatum, long fizetes) {
		super();
		this.nev = nev;
		this.szulDatum = szulDatum;
		this.fizetes = fizetes;
	}

	public int getKor() {
		LocalDate jelenlegiDatum = java.time.LocalDate.now();
		int jelenlegiEv = jelenlegiDatum.getYear();
		int szulEv = this.szulDatum.getYear();

		return jelenlegiEv - szulEv;
	}

	@Override
	public String toString() {
		int monthvalue = this.szulDatum.getMonthValue();
		String monthname = convertMonthValue(monthvalue);

		return "Nev:" + nev + " szulDatum:" + this.szulDatum.getYear() + "." + monthname + "."
				+ this.szulDatum.getDayOfMonth() + "." + " fizetes:" + fizetes + " evek szama nyugdijig:"
				+ getEvekSzamaNyugdijig();
	}

	public int getEvekSzamaNyugdijig() {
		return Alkalmazott.nyugdijKorhatar - this.getKor();
	}

	public static Alkalmazott getFitalabb(Alkalmazott alk1, Alkalmazott alk2) {
		if (alk1.getEvekSzamaNyugdijig() > alk2.getEvekSzamaNyugdijig()) {
			return alk1;
		} else
			return alk2;
	}

	public static void setNyugdijKorhatar(int nyugdijKorhatar) {
		Alkalmazott.nyugdijKorhatar = nyugdijKorhatar;
	}

	public String convertMonthValue(int monthvalue) {
		return honapNevek[monthvalue];
	}

	public int convertMonthName(String monthname) {
		for (int i = 1; i < honapNevek.length; i++) {
			if (honapNevek[i].equalsIgnoreCase(monthname))
				return i;
		}
		return 0;
	}

	public String getNev() {
		return nev;
	}

	public void setNev(String nev) {
		this.nev = nev;
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