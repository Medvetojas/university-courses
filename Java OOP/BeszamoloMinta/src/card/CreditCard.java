package card;

import java.time.LocalDate;

public class CreditCard extends Card{
	private int credit;

	
	public CreditCard(String name, LocalDate valid, int balance, String bank) {
		super(name, valid, balance, bank);
		this.credit = 100000;
	}

	public CreditCard(String name, LocalDate valid, int balance, String bank, int credit) {
		super(name, valid, balance, bank);
		this.credit = credit;
	}
	
	public Boolean penzFelvet(int amount) {
		if(this.valid.isBefore(LocalDate.now())){
			return false;
		}else if(this.balance >= amount) {
			this.balance -= amount;
			return true;
		}else if ((this.balance + this.credit) >= amount){
			int temp = amount - balance;
			this.balance -= amount;
			this.credit -= temp;
			this.balance += Math.abs(balance);
			return true;
		}else {
			return false;
		}
	}

	
	@Override
	public String toString() {
		return "CreditCard [credit=" + credit + ", valid=" + valid + ", balance=" + balance + ", getName()=" + getName()
				+ ", getBank()=" + getBank() + "]";
	}

	
	public int getCredit() {
		return credit;
	}

	public void setCredit(int credit) {
		this.credit = credit;
	}
	
	
}
