import java.util.*;

public class SortBasedOnFrequency {
    public static void main(String[] args) {
        int arr[] = {5,3,1,2,2,2,4,5,3,5,2};
        
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for (int num : arr) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }
        List<Integer> list = new ArrayList<>();
        for (int num : arr) {
            list.add(num);
        }
        
        list.sort((a, b) -> {
            int freqA = frequencyMap.get(a);
            int freqB = frequencyMap.get(b);
            if (freqA != freqB) {
                return Integer.compare(freqA, freqB);
            } else {
                return Integer.compare(b, a);
            }
        });
        System.out.println(list);
    }
}
