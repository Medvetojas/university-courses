package Szemely;

import java.util.Comparator;

public class NameSorter implements Comparator<Alkalmazott> {

	@Override
	public int compare(Alkalmazott o1, Alkalmazott o2) {
		return o1.getNev().compareTo(o2.getNev());
	}

}
