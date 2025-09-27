class ExcHandlingExp
{
	public static void main(String args[]) {
		try {	// outermost try block
			try {	// 1st try-catch block
				int a = 30;
				int b = 0; // before b = 10, but now b = 0
				
				int c = a / b;
				
				System.out.println(c);
			}
			
			catch (ArithmeticException e) {
				System.out.println(e);
			}
			
			try {	// 2nd try-catch block
				int a[] = new int[5];
				a[3] = 2;
				a[6] = 6;	// ArrayIndexOutOfBoundsException
				
				System.out.printf("Array: ");
				for (int i = 0; i < 5; i++) {
					System.out.printf("%d ", a[i]);
				}
				System.out.println();
				
				
				String S = null;
				System.out.println(S.length());	// NullPointerException
						
			}
			
			catch (ArrayIndexOutOfBoundsException e) {
				System.out.println(e);
			}
			
			catch (NullPointerException e) {
				System.out.println(e);
			}
			
			try {	// 3rd try-catch block
				int n = Integer.parseInt("abc");	// "101" is replaced with "abc"
				System.out.println(n);
			}
			
			catch (NumberFormatException e) {
				System.out.println(e);
			}
		}
		
		catch (Exception e) {	// outmost catch block
			System.out.println("All errors are handled!");
			}
		
		finally {	// outermost finally block
			System.out.println("All try-catch blocks were checked");
			System.out.println("Nested try-catch was tried");
			System.out.println("This is the finally block");
		}
	}
}
