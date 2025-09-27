class fourth {
	public static void main(String[] args) {
		String name = args[0];
		int rollno = Integer.parseInt(args[1]);
		float marks = Float.parseFloat(args[2]);
		
		System.out.printf("%.2f marks scored by %s who's roll no. is %d\n", marks, name, rollno);
		}
}
