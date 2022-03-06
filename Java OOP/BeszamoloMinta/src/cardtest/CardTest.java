package cardtest;

import java.time.DateTimeException;
import java.time.LocalDate;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

import card.Card;
import card.CreditCard;

public class CardTest {

	public static void main(String[] args) throws DateTimeException {
		Card cards[] = new Card[setNumber()];
		Scanner input = new Scanner(System.in);
		
		for (int i = 0; i < cards.length; i++) {
			
			System.out.println("Enter the Card Owner: ");
			String name = input.nextLine();
			
			System.out.println("Enter the Validity Date (example: 2021-04-26): ");
			String date = input.nextLine();
			LocalDate validity = LocalDate.parse(date);
			
			System.out.println("Enter the Bank Name: ");
			String bank = input.nextLine();
			
			System.out.println("Enter the Balance: ");
			int balance = input.nextInt();
			
			System.out.println("Is it a Credit Card (1 - yes, 0 - no): ");
			int isItCredit = input.nextInt();
			
			if(isItCredit == 1) {
				cards[i] = new CreditCard(name, validity, balance, bank);
			}else {
				cards[i] = new Card(name, validity, balance, bank);
			}
		}
		
		System.out.println("Feltoltott kartya tomb: ");
		for (Card card : cards) {
			System.out.println(card);
		}
		
		for (Card card : cards) {
			System.out.println("Mennyit szeretnel felvenni? ");
			int amount = input.nextInt();
			
			System.out.println("A felvet sikeressege (1 - igen, 0 - nem): " + card.penzFelvet(amount));
			System.out.println(card);
		}
		
		System.out.println("A CIB-esek szama: " + countCIB(cards));
		
		System.out.println("Rendezes ervenyessegi datum alapjan...");
		sortCards(cards);
		
		System.out.println("Kiiras rendezes utan...");
		printCards(cards);
	}
	
	private static void sortCards(Card[] cards) {
		Comparator<Card> c = new Comparator<Card>() {
			public int compare(Card c1, Card c2) {
				return c1.getValid().compareTo(c2.getValid());
			}
		};
		
		Arrays.sort(cards, c);
	}

	private static void printCards(Card[] cards) {
		for (Card card : cards) {
			System.out.println(card);
		}
	}
	
	private static int countCIB(Card[] cards) {
		int count = 0;
		for (int i = 0; i < cards.length; i++) {
			
			
			if(cards[i].getBank().toString().equalsIgnoreCase("CIB")) {
				count++;
			}
			
		}
		return count;
	}

	private static int setNumber() {
		Scanner input = new Scanner(System.in);
		int size;

		do {
			System.out.println("Enter a number between 1 and 10");
			while (!input.hasNextInt()) {
				System.out.println("That's not a number");
				input.next();
			}
			size = input.nextInt();
		} while (size < 1 || size >= 10);
		return size;
	}

}
