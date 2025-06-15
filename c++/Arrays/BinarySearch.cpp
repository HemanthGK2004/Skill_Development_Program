#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Avoids overflow

            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] < target) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
        return -1; // Target not found
    }
};
int main() {

    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Example sorted array
    int target = 9; // Example target
    int result = solution.binarySearch(nums, target); // Call the function
    if (result != -1) {
        cout << "Element found at index: " << result << endl; // Output the result
    } else {
        cout << "Element not found." << endl; // Element not found
    }
    return 0; // Return success
}