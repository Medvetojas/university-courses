package demo;

import java.awt.Color;

import aru.Pen;
import pont.SzinesPont;
import szinez.ISzinezheto;

public class Demo {

	public static void main(String[] args) {
		ISzinezheto szinesPont = new SzinesPont();
		System.out.println(szinesPont);
		
		szinesPont.setSzin(Color.blue);
		System.out.println(szinesPont);
		
		
		ISzinezheto toll = new Pen("pen", Color.red, 250);
		System.out.println(toll);
		toll.setSzin(Color.blue);
		System.out.println(toll);
		ISzinezheto.setAlapertelmezettSzin(toll);
		System.out.println(toll);
	}
	
	
	public static void setDefaultColor(ISzinezheto iszinezheto) {
		iszinezheto.setSzin(Color.red);
	}

}
