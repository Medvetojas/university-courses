package sajatcsomag;

import java.time.LocalDate;
import java.util.Comparator;
import sajatcsomag.exceptions.InvalidMarkException;

public class Bejegyzes {
	private String subject;
	private LocalDate date;
	private int mark;
	
	public Bejegyzes(String subject, LocalDate date, int mark) throws InvalidMarkException {
		this.subject = subject;
		this.date = date;
		if(mark < 1 || mark > 5 || mark == 0) {
			throw new InvalidMarkException(mark);
		}else{
			this.mark = mark;
		};
	}
	
	public static class DateSorter implements Comparator<Bejegyzes>{
		public int compare(Bejegyzes o1, Bejegyzes o2) {
			return o1.getDate().compareTo(o2.getDate());
		}
	}

	public String getSubject() {
		return subject;
	}

	public void setSubject(String subject) {
		this.subject = subject;
	}

	public LocalDate getDate() {
		return date;
	}

	public void setDate(LocalDate date) {
		this.date = date;
	}

	public int getMark() {
		return mark;
	}

	public void setMark(int mark) {
		this.mark = mark;
	}

	@Override
	public String toString() {
		return "Bejegyzes [subject=" + subject + ", date=" + date + ", mark=" + mark + "]";
	}
	
	
}
