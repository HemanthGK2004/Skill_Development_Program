import java.util.Scanner;

class Employee {
    String name;
    int age;
    double salary;
    int id;

    // Constructor to initialize employee details
    Employee(String n, int a, double s, int i) {
        this.name = n;
        this.age = a;
        this.salary = s;
        this.id = i;
    }

    // Method to display employee details
    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Salary: " + salary);
        System.out.println("ID: " + id);
    }
}

public class Main {
    public static void main(String[] args) {
        Employee[] array = new Employee[3];
        Scanner sc = new Scanner(System.in);

        // Taking employee details as input
        for (int i = 0; i < 3; i++) {
            System.out.println("Enter details for Employee " + (i + 1) + ":");

            sc.nextLine();  // Consume the newline left by previous input
            System.out.print("Enter the name: ");
            String n = sc.nextLine();

            System.out.print("Enter the age: ");
            int a = sc.nextInt();

            System.out.print("Enter the salary: ");
            double s = sc.nextDouble();

            System.out.print("Enter the ID: ");
            int id = sc.nextInt();

            array[i] = new Employee(n, a, s, id);
        }

        System.out.println("\nEmployee Details (Before Sorting):");
        for (int i = 0; i < 3; i++) {
            array[i].displayDetails();
            System.out.println();
        }

        // Sorting employees based on salary (Ascending Order)
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (array[i].salary > array[j].salary) {
                    Employee temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }

        System.out.println("Employee Details (After Sorting by Salary):");
        for (int i = 0; i < 3; i++) {
            array[i].displayDetails();
            System.out.println();
        }

        // Close scanner
        sc.close();
    }
}
