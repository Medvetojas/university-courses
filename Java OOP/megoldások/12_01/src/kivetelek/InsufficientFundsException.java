package kivetelek;

public class InsufficientFundsException extends Exception {
	private double hianyzoOsszeg;

	public InsufficientFundsException(double hianyzoOsszeg) {
		super();
		this.hianyzoOsszeg = hianyzoOsszeg;
	}

	public double getHianyzoOsszeg() {
		return hianyzoOsszeg;
	}

	@Override
	public String toString() {
		return "InsufficientFundsException [hianyzoOsszeg=" + hianyzoOsszeg + "]";
	}
	
	

}
