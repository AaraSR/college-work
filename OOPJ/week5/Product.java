public class Product {
	private int id;
	private String name;
	private double price;
	
	static String company;
	
	// constructor
	Product() {
		System.out.println("Product created!");
	}

	// paramaterized constructor using 'this'
	Product(int id, String name, double price) {
		this.id = id;
		this.name = name;
		this.price = price;
	}
	
	
	// Getter methods
	public int getId() {
		return id;
	}
	
	public String getName() {
		return name;
	}
	
	public double getPrice() {
		return price;
	}
	
	
	// Setter methods
	public void setId(int id) {
	    if (id > 0) {
		 this.id = id; // The illegal character was here, replaced with a standard space
	    } else {
		 System.out.println("Product ID must be positive.");
	    }
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setPrice(double price) {
		this.price = price;
	}
	
	// Display method
	public void display() {
		System.out.printf("Company: %s\nProduct ID: %d\nProduct Name: %s\nProduct Price: Rs.%.2f\n", company, id, name, price);
	}	
		
	// main method
	public static void main(String args[]) {
		System.out.println("Hello main!");
	}
}
