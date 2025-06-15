#include<iostream>
#include<vector>
using namespace std;
// Function to find the maximum sum of a contiguous subarray
class Solution {
    public:
    int maxSubarray(vector<int>& nums) {
        int max_sum = INT_MIN; // Initialize max_sum to the smallest integer
        int current_sum = 0; // Initialize current_sum to 0

        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i]; // Add the current element to current_sum
            max_sum = max(max_sum, current_sum); // Update max_sum if current_sum is greater

            if (current_sum < 0) { // If current_sum becomes negative, reset it to 0
                current_sum = 0;
            }
        }
        return max_sum; // Return the maximum sum found
    }
};
int main() {
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input
    int result = solution.maxSubarray(nums); // Call the function
    cout << "Maximum sum of contiguous subarray: " << result << endl; // Output the result
    return 0; // Return success
}
// This code implements Kadanes algorithm to find the maximum sum of a contiguous subarray.