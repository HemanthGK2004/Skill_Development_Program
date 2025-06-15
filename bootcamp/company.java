// Company gives bonus to employees based on their experience less than two years no bonus 2 - 5 years 5000 
// greater than 5 years 10000 calculate bonus display the employess details
import java.util.Scanner;

class Employee {
    int id;
    String name;
    int experience;
    int bonus;

    Employee(int id, String name,int experience) {
        this.id = id;
        this.name = name;
        this.experience = experience;
        this.bonus=calculateBonus();
    }
    int calculateBonus() {
        if (experience < 2) {
            return 0;
        } else if (experience >= 2 && experience <= 5) {
            return 5000;
        } else {
            return 10000;
        }
    }

    void displayDetails() {
        System.out.println("Employee ID: " + id);
        System.out.println("Employee Name: " + name);
        System.out.println("Experience: " + experience + " years");
        System.out.println("Bonus: " + bonus);
    }
}


public class company {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Employee ID: ");
        int id = sc.nextInt();
        sc.nextLine(); // Consume newline left-over
        System.out.println("Enter Employee Name: ");
        String name = sc.nextLine();
        System.out.println("Enter Employee Experience (in years): ");
        int experience = sc.nextInt();

        Employee employee = new Employee(id, name, experience);
        employee.displayDetails();

        // Display bonus based on experience
        if (employee.bonus == 0) {
            System.out.println("No bonus for employees with less than 2 years of experience.");
        } else if (employee.bonus == 5000) {
            System.out.println("Bonus for employees with 2 to 5 years of experience: " + employee.bonus);
        } else {
            System.out.println("Bonus for employees with more than 5 years of experience: " + employee.bonus);
        }
        
        sc.close();
    }
}