import java.util.Scanner;
class DivideByZeroException extends Exception {
    public DivideByZeroException(String message) {
        super(message);
    }
}
public class Divide {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the first number: ");
        double num1 = sc.nextDouble();
        System.out.print("Enter the second number: ");
        double num2 = sc.nextDouble();
        try{
            if (num2 == 0) {
                throw new DivideByZeroException("Cannot divide by zero.");
            }
            double result = num1 / num2;
            System.out.println("Result: " + result);
        }
        catch(DivideByZeroException e) {
            System.out.println("Error: " + e.getMessage());
        }
        finally {
            sc.close();
        }
    }
}
