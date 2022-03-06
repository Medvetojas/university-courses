package teglalap;

public class Fut {

	public static void main(String[] args) {
		Teglalap aTeglalap = new Teglalap(4, 6);
		Teglalap bTeglalap = new Teglalap(2, 7);
		Teglalap cTeglalap;
		
		cTeglalap = aTeglalap;
		
		System.out.println(aTeglalap);
		System.out.println(bTeglalap);
		System.out.println(cTeglalap);
		
		System.out.println();
		aTeglalap.setOldalak(8, 2);
		System.out.println(aTeglalap);
		System.out.println(bTeglalap);
		System.out.println(cTeglalap);
		
		System.out.println();
		aTeglalap.setOldalak(2, 7);
		System.out.println(aTeglalap);
		System.out.println(bTeglalap);
		System.out.println(cTeglalap);
		
		System.out.println();
		System.out.println(aTeglalap == bTeglalap);
		System.out.println(aTeglalap == cTeglalap);
		
		
		System.out.println(aTeglalap.getOldalakEgyeznekE(bTeglalap));
		
		
		Teglalap dTeglalap = cTeglalap;
		System.out.println(dTeglalap.toString());

		
	}

}
