package bookstyle;

import mybooks.Konyv;

public class KonyvStilus extends Konyv {
	private String stilus;

	public KonyvStilus(String cim, String szerzo, double ar, int ev, String stilus) {
		super(cim, szerzo, ar, ev);
		this.stilus = stilus;
	}

	public String getStilus() {
		return stilus;
	}

	public void setStilus(String stilus) {
		this.stilus = stilus;
	}

	@Override
	public String toString() {
		return super.toString() + " KonyvStilus [stilus=" + stilus + "]";
	}

}
