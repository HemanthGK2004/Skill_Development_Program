//create an object arrayList and add 5 elements to it
import java.util.ArrayList;

public class example {

    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        ArrayList<Integer> list2 = new ArrayList<>(); // Initial capacity of 10

        list.add(10);
        list.add(20);
        list.add(30);
        list.add(40);
        list.add(50);

        list2.add(60);
        list2.add(70);
        list2.add(80);
        list2.add(90);
        list2.add(100);

        System.out.println("Elements in the first ArrayList:");
        for (Integer num : list) {
            System.out.println(num);
        }
        // list.remove(4);
        // System.out.println("After removing the element at index 4:");
        // for (Integer num : list) {
        //     System.out.println(num);
        // }
        // System.out.println("Number of elements in the ArrayList: " + list.size());
        
        System.out.println("Elements in the second ArrayList:");
        for (Integer num : list2) {
            System.out.println(num);
        }

        list.addAll(list2);
        System.out.println("After combining both ArrayLists:");
        for (Integer num : list) {
            System.out.println(num);
        }

        System.out.println("Total number of elements in the combined ArrayList: " + list.size());
        int x = 50;
        for(int num : list) {
            if(num == x) {
                System.out.println("Found " + x + " in the ArrayList.");
                break;
            }
        }
        
    }
}