class Vehicle {
	int v_id;
	double price;
	String colour;
	
	// default constructor
	Vehicle() {
		v_id = 1001;
		price = 10000;
		colour = "red";
		
		System.out.println("Vehicle is created!");
	}
	
	// parametarized constructor
	Vehicle(int v_id, double price, String colour){
		this.v_id = v_id;
		this.price = price;
		this.colour = colour;
	}
	
	// display() method in Vehicle
	void display() {
		System.out.println("ID: " + v_id);
		System.out.println("Price: " + price);
		System.out.println("Colour: " + colour);
	}
}

class Car extends Vehicle
{
	String model;
	
	// default constructor
	Car() {
		super();
		model = "A10";
		System.out.println("Car is created!");
	}
	
	// parametarized constructor
	Car(int c_id, double c_price, String c_colour, String model) {
		super(c_id, c_price, c_colour);
		this.model = model;
		
		System.out.println("Car ID: " + c_id);
		System.out.println("Car Price: " + c_price);
		System.out.println("Car Colour: " + c_colour);
		System.out.println("Car Model: " + model);
	}
	
	// display() method in Car
	void display() {
		super.display();
		System.out.println("Model: " + model);
	}
	
	void print() {
		System.out.println("ID = " + super.v_id);
		System.out.println("Price = " + super.price);
		System.out.println("Colour = " + super.colour);
		System.out.println("Model = " + model);
	}
}

class BMW extends Car
{
	float performance;
	
	BMW() { System.out.println("BMW Car is created!"); }
}


class Inheritance
{
	public static void main(String[] args) 
	{
		// BMW b = new BMW();
		
		// b.display();
		// b.print();
		
		Car c = new Car(101, 10000, "Black", "B10");
		System.out.println(c);
	}
}
