import java.util.*;

class InvalidInputExp extends Exception
{
	public String toString()
	{
		return "invalid input";
	}
}

public class ExceptionHandlingUserDefined
{
	static void validate(int number) throws InvalidInputExp
	{
		if(number>100)
		{	
		throw new InvalidInputExp();
		}
	System.out.println("Valid Input");
	}

	public static void main(String args[]) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter the number: ");
		int no = scn.nextInt();
		
		try {
			validate(no);
		}
		catch (InvalidInputExp e) {
			System.out.println(e);
		}
	}
}
