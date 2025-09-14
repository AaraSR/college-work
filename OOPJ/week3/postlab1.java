import java.util.Scanner;

public class postlab1 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your percentage score: ");
        float percentage = scanner.nextFloat();

        String grade = calculateGrade(percentage);

        System.out.println("Your Grade: " + grade);

        scanner.close();
    }

    public static String calculateGrade(float score) {
        if (score < 40) {
            return "F";
        } else if (score >= 40 && score <= 60) {
            return "D";
        } else if (score >= 61 && score <= 80) {
            return "C";
        } else if (score >= 81 && score <= 90) {
            return "B";
        } else if (score >= 91) {
            return "A";
        } else {
            return "Invalid Score";
        }
    }
}
