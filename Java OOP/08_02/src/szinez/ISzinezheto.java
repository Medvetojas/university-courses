package szinez;

import java.awt.Color;

public interface ISzinezheto {
	public static final Color szin = Color.red;

	public default Color getSzin() {
		return this.szin;
	}

	public void setSzin(Color szin);

	public static void setAlapertelmezettSzin(ISzinezheto iszinezheto) {
		iszinezheto.setSzin(Color.red);
	}
}