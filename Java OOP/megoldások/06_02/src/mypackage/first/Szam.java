package mypackage.first;

public class Szam {
	private static final double TURES = 0.001;

	private double valosSzam;

	public Szam(double valosSzam) {
		super();
		this.valosSzam = valosSzam;
	}
	
	

	@Override
	public String toString() {
		return "Szam [valosSzam=" + valosSzam + "]";
	}



	public boolean teresenBelulVanE(double num) {
		if (Math.abs(this.valosSzam - num) < TURES)
			return true;

		return false;
	}

	public double getValosSzam() {
		return valosSzam;
	}

	public void setValosSzam(double valosSzam) {
		this.valosSzam = valosSzam;
	}

}
