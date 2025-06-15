import  java.util.Scanner;
public class FabinocciSeries{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of terms in the Fibonacci series: ");
        int n = sc.nextInt();
        int a = 0, b = 1;
        System.out.println("Fibonacci series up to " + n + " terms: ");
        for (int i = 1; i <= n; i++) {
            System.out.print(a + " ");
            int nextTerm = a + b;
            a = b;
            b = nextTerm;
        }
        System.out.println();
        System.out.println("The sum of the Fibonacci series is: " + a);
        sc.close();
    }
}