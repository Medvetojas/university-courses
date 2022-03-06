package mybooks;

public class Konyv {
	private String cim;
	private String szerzo;
	private double ar;
	private int ev;
	
	
	public Konyv(String cim, String szerzo, double ar, int ev) {
		super();
		this.cim = cim;
		this.szerzo = szerzo;
		this.ar = ar;
		this.ev = ev;
	}

	public void setArNovel(double szazalek) {
		this.ar = this.ar + (ar * (szazalek / 100));
	}

	public String toString() {
		return "Konyv [cim=" + cim + ", szerzo=" + szerzo + ", ar=" + ar + ", ev=" + ev + "]";
	}

	public String getCim() {
		return cim;
	}

	public void setCim(String cim) {
		this.cim = cim;
	}

	public String getSzerzo() {
		return szerzo;
	}

	public void setSzerzo(String szerzo) {
		this.szerzo = szerzo;
	}

	public double getAr() {
		return ar;
	}

	public void setAr(double ar) {
		this.ar = ar;
	}

	public int getEv() {
		return ev;
	}

	public void setEv(int ev) {
		this.ev = ev;
	}

}
