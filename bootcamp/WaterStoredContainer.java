public class WaterStoredContainer {
    public static void main(String[] args)
    {
        int[] heights ={1,8,6,2,5,4,8,3,7};
        int waterStored = calculateWaterStored(heights);
        System.out.println("Total water stored: " + waterStored + " units");
    }

    public static int calculateWaterStored(int[] heights) {
        int n = heights.length;
        int maxWater = 0;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int width = right - left;
            int minHeight = Math.min(heights[left], heights[right]);
            int currWater = width * minHeight;
            maxWater = Math.max(maxWater, currWater);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
}
