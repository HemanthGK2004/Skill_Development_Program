//
import java.util.*;
public class LibraryManagement {
    public static void main(String[] args) {

        ArrayList<String> issuedBooks = new ArrayList<>();
        issuedBooks.add("Java Programming");
        issuedBooks.add("Data Structures");
        issuedBooks.add("Algorithms");
        issuedBooks.add("Database Management Systems");
        issuedBooks.add("Operating Systems");
        issuedBooks.add("Computer Networks");
        issuedBooks.add("Web Development");
        issuedBooks.add("Java Programming");
        issuedBooks.add("Data Structures");

        HashSet<String> uniqueBooks = new HashSet<>(issuedBooks);

        System.out.println("Issued Books:");
        for (String book : issuedBooks) {
            System.out.println(book);
        }

        System.out.println("\nUnique Book Names:");
        for (String book : uniqueBooks) {
            System.out.println(book);
        }

    }
}
