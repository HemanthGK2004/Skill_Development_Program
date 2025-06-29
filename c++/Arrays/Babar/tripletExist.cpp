#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool tripletExist(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // Sort the array
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if(sum==target) {
                    return true; // Triplet found
                }
                else if (sum < target) {
                    left++; // Move left pointer to increase sum
                } else {
                    right--; // Move right pointer to decrease sum
                }
            }
        }
        return false; // No triplet found
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5}; // Example input
    int target = 9; // Example target sum
    bool result = solution.tripletExist(arr, target); // Call the function
    cout << (result ? "Triplet exists." : "No triplet exists.") << endl; // Output the result
    return 0; // Return success
}
// This code checks if there exists a triplet in the array that sums up to the target value.
// It sorts the array and uses a two-pointer technique to find the triplet efficiently.