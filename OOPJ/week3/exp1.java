import java.util.Scanner;

public class exp1 {
    public static void main(String[] args) {

        double stockPrice = 0.0;
        double interestRate = 0.0;
        String stockName = "";
        int quantity = 0;
        double totalPrice = 0.0;
        double interestAmount = 0.0;
        double finalPriceWithInterest = 0.0;
        int duration = 0;

        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to Stockerz!!!\n");

        System.out.println("   Stock Name         Price         Interest");
        System.out.println("1. Beliance           Rs. 1,245       15%");
        System.out.println("2. NATA               Rs. 567         20%");
        System.out.println("3. Outfosys           Rs. 1,351       25%");
        System.out.println("4. Nadani             Rs. 2,424       10%");
        System.out.println("5. Moonbucks          Rs. 4,783       5%");

        System.out.print("Enter your choice for buying, else enter other number to exit: ");
        int choice = scanner.nextInt();

        switch (choice) {
            case 1:
                stockName = "Beliance";
                stockPrice = 1245.0;
                interestRate = 0.15;
                break;
            case 2:
                stockName = "NATA";
                stockPrice = 567.0;
                interestRate = 0.20;
                break;
            case 3:
                stockName = "Outfosys";
                stockPrice = 1351.0;
                interestRate = 0.25;
                break;
            case 4:
                stockName = "Nadani";
                stockPrice = 2424.0;
                interestRate = 0.10;
                break;
            case 5:
                stockName = "Moonbucks";
                stockPrice = 4783.0;
                interestRate = 0.05;
                break;
            default:
                System.out.println("Invalid choice. Please select a valid stock (1-5).");
                scanner.close();
                return;
        }

        System.out.print("Enter the quantity you want to buy: ");
        quantity = scanner.nextInt();

        System.out.print("Enter the duration (in years) for which the interest will be calculated: ");
        duration = scanner.nextInt();

        totalPrice = stockPrice * quantity;

        interestAmount = totalPrice * interestRate * duration;
        finalPriceWithInterest = totalPrice + interestAmount;

        System.out.println("\n--- Your Stockerz Invoice ---");
        System.out.println("Stock Name:     " + stockName);
        System.out.println("Price per unit: Rs. " + String.format("%.2f", stockPrice));
        System.out.println("Quantity:       " + quantity);
        System.out.println("Interest Rate:  " + String.format("%.0f%%", interestRate * 100));
        System.out.println("Duration:       " + duration + " years");
        System.out.println("-----------------------------");
        System.out.println("Subtotal:       Rs. " + String.format("%.2f", totalPrice));
        System.out.println("Interest Amount: Rs. " + String.format("%.2f", interestAmount));
        System.out.println("Total Price (with interest): Rs. " + String.format("%.2f", finalPriceWithInterest));
        System.out.println("-----------------------------");
        System.out.println("Thank you for shopping with Stockerz!");

        scanner.close();
    }
}
