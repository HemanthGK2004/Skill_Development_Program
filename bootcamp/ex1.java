import java.util.Scanner;
public class ex1 {
    public static void main(String[] args) {
        // Print "Hello, World!" to the console
        Scanner sc = new Scanner(System.in);
        int a,b;
        System.out.println("Enter A:");
        a = sc.nextInt();
        System.out.println("Enter B:");
        b = sc.nextInt();
        System.out.println("Sum is: " + (a + b));
        sc.close();
    }
}