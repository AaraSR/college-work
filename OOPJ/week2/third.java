import java.util.*;

class third {
	public static void main(String[] args) {
		int rollno;
		float marks;
		String name;
		
		Scanner s1 = new Scanner(System.in);
		
		System.out.println("Enter your roll no.: ");
		rollno = s1.nextInt();
		s1.nextLine();
		
		System.out.println("Enter the name: ");
		name = s1.nextLine();
		
		System.out.println("Enter the marks: ");
		marks = s1.nextFloat();
		
		System.out.printf("%.2f marks scored by %s who's roll no. is %d\n", marks, name, rollno);
		
		}
}
