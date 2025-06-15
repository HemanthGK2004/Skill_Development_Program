import java.util.Scanner;
public class largestNum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] n = new int[5];
        System.out.println("Enter 5 numbers: ");
        for (int i = 0; i < n.length; i++) {
            n[i] = sc.nextInt();
        }
        int largest = n[0];
        for (int i = 1; i < n.length; i++) {
            if (n[i] > largest) {
                largest = n[i];
            }
        }
        System.out.println("The largest number is: " + largest);
        sc.close();
    }
}
