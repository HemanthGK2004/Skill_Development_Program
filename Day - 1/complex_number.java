// Add two complex numbers
import java.util.Scanner;
class complex_number{
    double real, imaginary;

    complex_number(double r, double i) {
        real = r;
        imaginary = i;
    }

    static complex_number add(complex_number c1, complex_number c2) {
        return new complex_number(c1.real + c2.real, c1.imaginary + c2.imaginary);
    }

    void display() {
        System.out.println(real + " + " + imaginary + "i");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            System.out.println("Enter the first complex number:");
            System.out.println("Enter the real part:");
            double r1 = sc.nextDouble();
            System.out.println("Enter the imaginary part:");
            double i1 = sc.nextDouble();
            System.out.println("Enter the second complex number:");
            System.out.println("Enter the real part:");
            double r2 = sc.nextDouble();
            System.out.println("Enter the imaginary part:");
            double i2 = sc.nextDouble();
            complex_number c1 = new complex_number(r1, i1);
            complex_number c2 = new complex_number(r2, i2);
            complex_number c3 = add(c1, c2);
            c1.display();
            c2.display();
            c3.display();
        } finally {
            sc.close();
        }
    }
}