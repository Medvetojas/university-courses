package aru;

import java.awt.Color;

import szinez.ISzinezheto;
import szinez.myColor;

public class Pen extends Product implements ISzinezheto {
	private String brandName;
	private Color color;

	public Pen(String brandName, Color color, int price) {
		super("Pen", price, 27);
		this.brandName = brandName;
		this.color = color;
	}

	@Override
	public String toString() {
		myColor mycolor = new myColor(color);
		return "Pen [brandName=" + brandName + ", color=" + mycolor + "]";
	}

	@Override
	public void setSzin(Color szin) {
		this.color = szin;
	}

}