package teglalap;

public class Teglalap {
	private int a;
	private int b;

	public Teglalap(int a, int b) {
		this.a = a;
		this.b = b;
	}

	public Teglalap(int a) {
		this.a = a;
		this.b = a;
	}

	public int getTerulet() {
		return a * b;
	}

	@Override
	public String toString() {
		return "a:" + this.a + " b:" + this.b + " terulet:" + this.getTerulet();
	}

	public void setOldalak(int a, int b) {
		this.a = a;
		this.b = b;
	}

	public int getA() {
		return a;
	}

	public void setA(int a) {
		this.a = a;
	}

	public int getB() {
		return b;
	}

	public void setB(int b) {
		this.b = b;
	}

	public boolean getNagyobbTerulet(Teglalap masik) {
		if (this.getTerulet() > masik.getTerulet())
			return true;

		return false;
	}

	public boolean getOldalakEgyeznekE(Teglalap masik) {
		if (this.a == masik.a && this.b == masik.b)
			return true;

		return false;
	}

}
