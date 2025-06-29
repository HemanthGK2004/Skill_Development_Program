#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    bool subArrayWithSumZero(vector<int>& arr) {
        unordered_set<int> prefixSumSet;
        int currentSum = 0;

        for (int num : arr) {
            currentSum += num;

            // Check if current sum is zero or if it has been seen before
            if (currentSum == 0 || prefixSumSet.find(currentSum) != prefixSumSet.end()) {
                return true; // Found a subarray with sum zero
            }

            // Add the current sum to the set
            prefixSumSet.insert(currentSum);
        }

        return false; // No subarray with sum zero found
    }
};

int main() {
    Solution solution;
    vector<int> arr = {4, 2, -3, 1, 6}; // Example input
    bool result = solution.subArrayWithSumZero(arr); // Call the function
    cout << (result ? "Subarray with sum zero exists." : "No subarray with sum zero exists.") << endl; // Output the result
    return 0; // Return success
}
