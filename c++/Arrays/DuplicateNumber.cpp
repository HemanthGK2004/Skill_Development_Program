#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public :
    int duplicateNumber(vector<int>&nums){
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        slow = nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow; // Return the duplicate number
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 3,4, 4, 2, 2}; // Example input
    int result = solution.duplicateNumber(nums); // Call the function
    cout << "Duplicate number: " << result << endl; // Output the result
    return 0; // Return success
}
// This code uses Floyd's Tortoise and Hare algorithm to find the duplicate number in an array.
// The array is assumed to contain n + 1 integers where each integer is between 1 and n (inclusive).
// The algorithm uses two pointers to detect a cycle in the array, which indicates the duplicate number.
// The time complexity is O(n) and the space complexity is O(1).
// The code is designed to be efficient and works well for large inputs.
// The main function demonstrates how to use the Solution class to find the duplicate number in a sample array.