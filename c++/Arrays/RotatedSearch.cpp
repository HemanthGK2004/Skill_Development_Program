#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    int rotateSearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Target found
            }

            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Search in the left half
                } else {
                    left = mid + 1; // Search in the right half
                }
            }
            
            else { // Right half is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // Search in the right half
                } else {
                    right = mid - 1; // Search in the left half
                }
            }
        }
        return -1; // Target not found
    }
};
int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Example rotated sorted array
    int target = 0; // Example target
    int result = solution.rotateSearch(nums, target); // Call the function
    if (result != -1) {
        cout << "Element found at index: " << result << endl; // Output the result
    } else {
        cout << "Element not found." << endl; // Element not found
    }
    return 0; // Return success
}