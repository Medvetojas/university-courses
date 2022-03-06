package myproducts.proba;

import myproducts.Bread;
import myproducts.Product;

public class Proba {

	public static void main(String[] args) {
		Product product = new Product("Kakajo", 300, 5);
		Bread bread = new Bread("kenyer", 250, 5, 4);
		
		System.out.println(product);
		System.out.println(bread);
		
		System.out.println("Dragabb: " + product.melyikDragabb(bread));

		Product product2 = new Bread("kenyer2", 100, 2, 5);
		System.out.println(product2.toString());
		
		Bread bread2 = new Bread("kenyer3", 300, 5, 1);
		
		if(Bread.egysegarHasonlit((Bread)product2, bread2)) {
			System.out.println("Dragabb: " + product2);
		} else
			System.out.println("Dragabb: " + bread2);
		
		
	}

}
