#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

class Solution {
    public:
    pair<int, int> findMaxAndMin(vector<int>& arr) {
        if (arr.empty()) {
            return {0, 0}; // Return 0, 0 for empty array
        }
        int maxEle = arr[0], minEle = arr[0];
        for(int num: arr) {
            maxEle = max(maxEle, num); // Update maximum element
            minEle = min(minEle, num); // Update minimum element
        }
        return {maxEle, minEle}; // Return pair of maximum and minimum elements
    }
};

int main() {
    Solution solution;
    vector<int> arr = {3, 5, 1, 8, 2}; // Example array
    pair<int, int> result = solution.findMaxAndMin(arr); // Call the function
    cout << "Maximum: " << result.first << ", Minimum: " << result.second << endl; // Output the result
    return 0; // Return success
}