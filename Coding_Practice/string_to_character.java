public class string_to_character {
    public static void main(String[] args) {
        String str = "Hello";
        char[] charArray = str.toCharArray();
        for (char c : charArray) {
            System.out.println(c);
        }
    }
}
