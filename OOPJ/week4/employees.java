class Employee {
	int e_id;
	String name;
	float salary;
	
	Employee() {
		System.out.println("Employee created!");
	}
	
	Employee(int emp_id, String emp_name, float emp_salary) {
		e_id = emp_id;
		name = emp_name;
		salary = emp_salary;
	}
	
	void display() {
		System.out.println("Employee ID: " + e_id);
		System.out.println("Name: " + name);
		System.out.println("Salary: " + salary);
		System.out.println();
	}
	
}	

public class employees {
	public static void main(String args[]) {
		Employee e1 = new Employee();
		Employee e2 = new Employee(02, "MyName", 1.11F);
		
		e1.display();
		
		e2.display();
				
	}
}

