package bank;

import kivetelek.InsufficientFundsException;

public class Bankszamla {
	private int bankszamlaSzam;
	private double bankszamlaEgyenleg;

	public Bankszamla(int bankszamlaSzam) {
		this.bankszamlaEgyenleg = 0;
		this.bankszamlaSzam = bankszamlaSzam;
	}

	@Override
	public String toString() {
		return "Bankszamla [bankszamlaSzam=" + bankszamlaSzam + ", bankszamlaEgyenleg=" + bankszamlaEgyenleg + "]";
	}

	public int getBankszamlaSzam() {
		return bankszamlaSzam;
	}

	public void setBankszamlaSzam(int bankszamlaSzam) {
		this.bankszamlaSzam = bankszamlaSzam;
	}

	public double getBankszamlaEgyenleg() {
		return bankszamlaEgyenleg;
	}

	public void setBankszamlaEgyenleg(double bankszamlaEgyenleg) {
		this.bankszamlaEgyenleg = bankszamlaEgyenleg;
	}

	public void penzBevet(double osszeg) {
		this.bankszamlaEgyenleg += osszeg;
	}

	public void penzKivet(double osszeg) throws InsufficientFundsException {
		if (osszeg <= this.bankszamlaEgyenleg) {
			this.bankszamlaEgyenleg -= osszeg;
		} else {
			double hianyzoOsszeg = osszeg - this.bankszamlaEgyenleg;
			throw new InsufficientFundsException(hianyzoOsszeg);
		}

	}

}
