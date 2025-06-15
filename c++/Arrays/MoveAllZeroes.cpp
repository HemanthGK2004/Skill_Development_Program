//Move all zeros to the end of the array
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void moveAllZeroes(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[index++] = nums[i]; // Move non-zero elements to the front
            }
        }
        while (index < n) {
            nums[index++] = 0; // Fill the rest of the array with zeros
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12}; // Example input
    solution.moveAllZeroes(nums); // Call the function
    cout << "Array after moving all zeroes: ";
    for (int num : nums) {
        cout << num << " "; // Output the result
    }
    cout << endl; // New line for better readability
    return 0; // Return success
}