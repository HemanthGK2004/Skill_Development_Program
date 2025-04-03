// //Box pattern
// import java.util.Scanner;
// public class star {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         System.out.println("Enter the number of rows: ");
//         int n = sc.nextInt();
//         System.out.println("Enter the number of columns: ");
//         int m = sc.nextInt();
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
//                     System.out.print("* ");
//                 } else {
//                     System.out.print("  ");
//                 }
//             }
//             System.out.println();
//         }
//         System.out.println("The pattern is printed");
//         sc.close();
//     }
// }
// Hallow Diamond pattern
import java.util.Scanner;
public class star {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows: ");
        int n = sc.nextInt();
        System.out.println("Enter the number of columns: ");
        int m = sc.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    System.out.print("* ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
        System.out.println("The pattern is printed");
        sc.close();
    }
}
