import java.util.ArrayList;

class Student {
    String name;
    String hobby;
    int grade;

    Student(String name, String hobby, int grade) {
        this.name = name;
        this.hobby = hobby;
        this.grade = grade;
    }

    @Override
    public String toString() {
        return name + " - Hobby: " + hobby + ", Grade: " + grade;
    }
}

public class studentManagement {
    public static void main(String[] args) {
        ArrayList<Student> students = new ArrayList<>();

        students.add(new Student("Alice", "Reading", 85));
        students.add(new Student("Bob", "Swimming", 90));
        students.add(new Student("Charlie", "Cycling", 95));


        System.out.println("Adding a new student:");
        students.add(new Student("David", "Gaming", 88));

        System.out.println("\nCurrent Students:");
        displayStudents(students);

        System.out.println("\nUpdating Bob's hobby and grade:");
        for (Student s : students) {
            if (s.name.equals("Bob")) {
                s.hobby = "Dancing";
                s.grade = 92;
            }
        }

        System.out.println("\nUpdated Students:");
        displayStudents(students);

        System.out.println("\nRemoving Charlie:");
        students.removeIf(s -> s.name.equals("Charlie"));

        System.out.println("\nStudents after deletion:");
        displayStudents(students);
    }

    public static void displayStudents(ArrayList<Student> students) {
        for (Student s : students) {
            System.out.println(s);
        }
    }
}
