import java.util.Scanner;
public class largest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter first number: ");
        int a = sc.nextInt();
        System.out.println("Enter Second number: ");
        int b = sc.nextInt();
        if(a>b){
            System.out.println("Largest Number is "+ a);
        }
        else if(b>a){
            System.out.println("Largest Number is "+ b);
        }
        else{
            System.out.println("Both are equal");
        }
        sc.close();
    }
}
