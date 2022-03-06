package sajatcsomag.exceptions;

public class InvalidMarkException extends Exception{
	
	private static final long serialVersionUID = 1L;
	
	private int mark;

	public InvalidMarkException(int mark) {
		System.out.println("A megadott [" + mark + "] erdemjegy nem ervenyes!");
	}

	public int getMark() {
		return mark;
	}
	
	
}
