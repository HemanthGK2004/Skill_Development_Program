
public class rightShiftbyOne {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        System.out.println("Original array: ");
        printArray(arr);

        rightShift(arr);
        System.out.println("Array after right shift by one: ");
        printArray(arr);
    }

    static void rightShift(int[] arr) {
        if (arr.length == 0) return; // Handle empty array
        int n = arr.length;
        int lastElement = arr[n - 1];
        for(int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1]; // Shift elements to the right
        }
        arr[0] = lastElement; // Place the last element at the first position
    }

    static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
    
}
