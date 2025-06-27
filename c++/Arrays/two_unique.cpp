//two unique numbers in an array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoUniqueNumbers(vector<int>& nums) {
        int xorResult = 0;
        for (int num : nums) {
            xorResult ^= num; // XOR all numbers
        }

        // Find the rightmost set bit in xorResult
        int rightmostSetBit = xorResult & -xorResult;

        int firstUnique = 0, secondUnique = 0;
        for (int num : nums) {
            if (num & rightmostSetBit) {
                firstUnique ^= num; // First unique number
            } else {
                secondUnique ^= num; // Second unique number
            }
        }

        return {firstUnique, secondUnique}; // Return the two unique numbers
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 4, 5, 7}; // Example input
    vector<int> result = solution.twoUniqueNumbers(nums); // Call the function
    cout << "Two unique numbers: " << result[0] << ", " << result[1] << endl; // Output the result
    return 0; // Return success
}