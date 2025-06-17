import java.util.*;
public class setExample{
    public static void main(String[] args) {
    
        Set<Integer> numbers = new HashSet<>();
        numbers.add(10);
        numbers.add(20);
        numbers.add(30);
        numbers.add(40);
        numbers.add(50);
        numbers.add(60);
        numbers.add(70);
        numbers.add(80);
        numbers.add(90);
        numbers.add(100);
        
        System.out.println("Elements in the Set:");
        for (Integer num : numbers) {
            System.out.println(num);
        }
        // elments in ascending order
        System.out.println("Elements in ascending order:");
        List<Integer> sortedList = new ArrayList<>(numbers);
        Collections.sort(sortedList);
        for (Integer num : sortedList) {
            System.out.println(num);
        }
    }
}
