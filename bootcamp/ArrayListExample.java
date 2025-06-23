import java.util.ArrayList;
public class ArrayListExample {
    // Method to perform binary search on an ArrayList
    // public static int binarySearch(ArrayList<Integer> list, int key) {
    //     int left = 0;
    //     int right = list.size() - 1;

    //     while (left <= right) {
    //         int mid = left + (right - left) / 2;
    //         if (list.get(mid) == key) {
    //             return mid;
    //         }
    //         if (list.get(mid) < key) {
    //             left = mid + 1;
    //         } else {
    //             right = mid - 1;
    //         }
    //     }
    //     return -1;
    // }
    public static void main(String[] args) {
        ArrayList<Integer> numbers = new ArrayList<>();
        numbers.add(50);
        numbers.add(60);
        numbers.add(10);
        numbers.add(5);
        numbers.add(10);
        numbers.add(25);
        numbers.add(70);
        numbers.add(65);
        numbers.add(80);
        numbers.add(90);

        System.out.println("Elements in the ArrayList:");
        for (Integer num : numbers) {
            System.out.println(num);
        }
        for (int i = 0; i < numbers.size() - 1; i++) {
            for (int j = 0; j < numbers.size() - i - 1; j++) {
                if (numbers.get(j)> numbers.get(j + 1)) {
                    int temp = numbers.get(j);
                    numbers.set(j, numbers.get(j + 1));
                    numbers.set(j + 1, temp);
                }
            }
        }

        System.out.println("Sorted ArrayList:");
        for (Integer num : numbers) {
            System.out.println(num);
        }
    }

}
