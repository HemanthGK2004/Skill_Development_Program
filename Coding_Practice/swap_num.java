public class swap_num {
    public static void main(String[] args) {
        int a = 10;
        int b = 20;
        System.out.println("Before swapping: a = " + a + ", b = " + b);
        // Swap  without using temporary variable
        a = a + b; // a now becomes 30
        b = a - b; // b becomes 10
        a = a - b; // a becomes 20
        System.out.println("After swapping: a = " + a + ", b = " + b);
        // Swap using temporary variable
        int temp = a;
        a = b;
        b = temp;
        System.out.println("After swapping using temp variable: a = " + a + ", b = " + b);
        // Swap using bitwise XOR
        a = a ^ b; // a now becomes 30
        b = a ^ b; // b becomes 10
        a = a ^ b; // a becomes 20
        System.out.println("After swapping using XOR: a = " + a + ", b = " + b);
    }
}
