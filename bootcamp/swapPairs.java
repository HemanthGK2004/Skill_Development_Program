// swap pairs in a array
public class swapPairs {

    public static void main(String[] args) {
        int[] arr = {17,19,25,20,16,18};
        System.out.println("Original Array:");
        printArray(arr);

        swapAdjacentPairs(arr);
        System.out.println("Array after swapping pairs:");
        printArray(arr);
    }

    public static void swapAdjacentPairs(int[] arr) {
        for (int i = 0; i < arr.length - 1; i += 2) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
