import java.util.ArrayList;
public class ArrayListExample {
    // Method to perform binary search on an ArrayList
    public static int binarySearch(ArrayList<Integer> list, int key) {
        int left = 0;
        int right = list.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) == key) {
                return mid;
            }
            if (list.get(mid) < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        ArrayList<Integer> numbers = new ArrayList<>();
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

        System.out.println("Elements in the ArrayList:");
        for (Integer num : numbers) {
            System.out.println(num);
        }


        // binary search
        int key = 50;
        int index = binarySearch(numbers, key);
        if (index != -1) {
            System.out.println("Element " + key + " found at index: " + index);
        } else {
            System.out.println("Element " + key + " not found in the ArrayList.");
        }
    }

}
