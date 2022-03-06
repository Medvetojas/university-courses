package egyetem;

public class Kar extends SzervezetiEgyseg {
	private String dekan;
	private int hallgatoLetszam;

	public Kar(KarNev nev, int letszam, int hallgatoLetszam) {
		super(nev.name(), letszam);
		this.hallgatoLetszam = hallgatoLetszam;

		switch (nev) {
		case GÉIK:
			this.dekan = "Siménfalvi Zoltán";
			break;
		case MFK:
			this.dekan = "Szûcs Péter";
			break;
		case MAK:
			this.dekan = "Palotás Árpád";
			break;
		case GTK:
			this.dekan = "Somosi Mariann";
			break;
		case ÁJK:
			this.dekan = "Csák Csilla";
			break;
		}
	}

	public Kar(KarNev nev) {
		this(nev, 70, 500);
	}

	@Override
	public String toString() {
		return "Kar [dekan=" + dekan + ", hallgatoLetszam=" + hallgatoLetszam + "]";
	}

	public String getDekan() {
		return dekan;
	}

	public void setDekan(String dekan) {
		this.dekan = dekan;
	}

	public int getHallgatoLetszam() {
		return hallgatoLetszam;
	}

	public void setHallgatoLetszam(int hallgatoLetszam) {
		this.hallgatoLetszam = hallgatoLetszam;
	}

	@Override
	public double getMunkaMennyiseg() {
		return this.hallgatoLetszam / getLetszam();
	}

}
