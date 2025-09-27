import java.util.Scanner;

class InvalidRadiusException extends Exception {
	@Override
    public String toString() {
        return "Invalid Radius!";
    }
}

public class AreaOfCircle
{
	static void validate(double radius) throws InvalidRadiusException {
        if (radius < 0) {
            throw new InvalidRadiusException();
        }
    }

    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        System.out.print("Enter the radius of the circle: ");
        double radius = scn.nextDouble();

        double area = 3.14 * radius * radius;

        try {
            validate(radius);
            System.out.println("Area of the circle: " + area);
        }

        catch (InvalidRadiusException e) {
            System.out.println(e);
        }

        scn.close();
    }
}