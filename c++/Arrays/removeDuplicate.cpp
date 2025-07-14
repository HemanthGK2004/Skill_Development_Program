#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    void removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return;
        
        int index = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[index]) {
                index++;
                nums[index] = nums[i]; // Move unique element to the next position
            }
        }
        nums.resize(index + 1); // Resize the vector to contain only unique elements
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 3, 3, 4}; // Example input with duplicates
    solution.removeDuplicates(nums); // Call the function
    cout << "Array after removing duplicates: ";
    for (int num : nums) {
        cout << num << " "; // Output the result
    }
    cout << endl; // New line for better readability
    return 0; // Return success
}