public class StudentMarks {
    public static void main(String[] args) {
        int [] marks = {85,85 , 78, 92, 88, 76, 90, 90, 84, 91};
        String [] names = {"Anb", "Ana", "Charlie", "David", "Eve", "Frank", "Irace", "Hannah", "Ian", "Jack"};
        //sorting marks and names in descending order and if mars are same then alphabetically by nam
        // for (int i = 0; i < marks.length - 1; i++)
        // {
        //     for (int j = 0; j < marks.length - i - 1; j++)
        //     {
        //         if (marks[j] < marks[j + 1])
        //         {
        //             int tempMark = marks[j];
        //             marks[j] = marks[j + 1];
        //             marks[j + 1] = tempMark;

        //             String tempName = names[j];
        //             names[j] = names[j + 1];
        //             names[j + 1] = tempName;
        //         }
        //     }
        // }
        for (int i = 0; i < marks.length - 1; i++) {
            for (int j = 0; j < marks.length - i - 1; j++) {
                if (marks[j] < marks[j + 1] || (marks[j] == marks[j + 1] && names[j].compareTo(names[j + 1]) > 0)) {
                    int tempMark = marks[j];
                    marks[j] = marks[j + 1];
                    marks[j + 1] = tempMark;

                    String tempName = names[j];
                    names[j] = names[j + 1];
                    names[j + 1] = tempName;
                }
            }
        }

        // Displaying sorted marks and names
        System.out.println("Sorted Marks and Names in Descending Order:");
        for (int i = 0; i < marks.length; i++) {
            System.out.println(names[i] + ": " + marks[i]);
        }
        // System.out.println("Sorted Marks and Names:");
        // for (int i = 0; i < marks.length; i++) {
        //     System.out.println(names[i] + ": " + marks[i]);
        // }

    }
}
