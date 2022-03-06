package card;

import java.time.LocalDate;

public class Card {
	private String name;
	protected LocalDate valid;
	protected int balance;
	private Bank bank;
	
	public enum Bank {
		OTP, KH, ERSTE, CIB;
	}

	
	public Card(String name, LocalDate valid, int balance, String bank) {
		this.name = name;
		this.valid = valid;
		this.balance = balance;
		
		for (Bank bankenum : Bank.values()) {
			if(bankenum.toString().equalsIgnoreCase(bank)) {
				this.bank = bankenum;
			}
		}
	}


	public String getName() {
		return name;
	}

	public LocalDate getValid() {
		return valid;
	}

	public int getBalance() {
		return balance;
	}

	public Bank getBank() {
		return bank;
	}
	
	public void setBalance(int balance) {
		this.balance = balance;
	}
	
	public Boolean penzFelvet(int amount) {
		if(this.valid.isBefore(LocalDate.now())){
			return false;
		}else if(this.balance >= amount) {
			this.balance -= amount;
			return true;
		}else {
			return false;
		}
	}
	
	
	@Override
	public String toString() {
		return "Card [name=" + name + ", valid=" + valid + ", balance=" + balance + ", bank=" + bank + "]";
	}
	
	
}
