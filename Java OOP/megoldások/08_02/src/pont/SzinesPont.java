package pont;

import java.awt.Color;

import szinez.ISzinezheto;

public class SzinesPont extends Pont implements ISzinezheto {
	private Color szin;
	
	public SzinesPont(Color szin) {
		super(0, 0);
		this.szin = szin;
	}

	public SzinesPont(int x, int y, Color szin) {
		super(x, y);
		this.szin = szin;
	}
	
	public SzinesPont() {
		super(0, 0);
		this.szin = ISzinezheto.szin;
	}

	@Override
	public String toString() {
		return super.toString() + " szin:" + this.szin;
	}

	@Override
	public void setSzin(Color szin) {
		this.szin = szin;
	}
}
