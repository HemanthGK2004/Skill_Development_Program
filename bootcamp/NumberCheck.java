//take input from user and check whether it is a float or not and also even or odd and in this we can also check whether it is a positive or negative number
//with typecasting concept
import java.util.Scanner;

public class NumberCheck {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        double input = sc.nextDouble();

        // Typecasting double to int
        int intValue = (int) input;

        // Checking if float or not
        if (input == intValue) {
            System.out.println("It is an Integer.");

            // Even or Odd check
            if (intValue % 2 == 0) {
                System.out.println("It is Even.");
            } else {
                System.out.println("It is Odd.");
            }
        } else {
            System.out.println("It is a Float number.");
        }

        // Positive or Negative check
        if (input > 0) {
            System.out.println("It is Positive.");
        } else if (input < 0) {
            System.out.println("It is Negative.");
        } else {
            System.out.println("It is Zero.");
        }

        sc.close();
    }
}
