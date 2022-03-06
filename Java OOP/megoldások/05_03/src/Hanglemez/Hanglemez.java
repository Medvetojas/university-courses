package Hanglemez;

public class Hanglemez {
	private String eloado;
	private String cim;
	private int hossz;
	
	
	public Hanglemez(String eloado, String cim, int hossz) {
		this.eloado = eloado;
		this.cim = cim;
		this.hossz = hossz;
	}


	@Override
	public String toString() {
		return "Hanglemez [eloado=" + eloado + ", cim=" + cim + ", hossz=" + hossz + "]";
	}
	
	public int getHosszabb(Hanglemez lemez) {
		if(this.hossz > lemez.hossz)
			return 1;
		else if(this.hossz < lemez.hossz)
			return -1;
		
		return 0;
	}
	
	
	public boolean getSzerzoEgyezikE(String eloado) {
		if(this.eloado.equals(eloado))
			return true;

		return false;
	}


	public String getEloado() {
		return eloado;
	}


	public void setEloado(String eloado) {
		this.eloado = eloado;
	}


	public String getCim() {
		return cim;
	}


	public void setCim(String cim) {
		this.cim = cim;
	}


	public int getHossz() {
		return hossz;
	}


	public void setHossz(int hossz) {
		this.hossz = hossz;
	}
}