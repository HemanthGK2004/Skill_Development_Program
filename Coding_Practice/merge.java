public class merge {
    public static void main(String[] args) {
        int[] arr1 = {1,5,2,4};
        int[] arr2 = {4,6,0,1,3};
        int[] mergedArray = mergeArrays(arr1, arr2);
        
        System.out.print("Merged Array: ");
        for (int num : mergedArray) {
            System.out.print(num + " ");
        }
    }

    public static int[] mergeArrays(int[] arr1, int[] arr2) {
        int n = arr1.length + arr2.length;
        int[] mergedArray = new int[n];
        
        int i = 0, j = 0, k = 0;
        
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] < arr2[j]) {
                mergedArray[k++] = arr1[i++];
            } else {
                mergedArray[k++] = arr2[j++];
            }
        }
        
        while (i < arr1.length) {
            mergedArray[k++] = arr1[i++];
        }
        
        while (j < arr2.length) {
            mergedArray[k++] = arr2[j++];
        }
        
        return mergedArray;
    }
}
