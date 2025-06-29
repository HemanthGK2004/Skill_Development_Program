#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    public:
    void findKthMaxAndMin(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end()); // Sort the array
        int n = arr.size();
        if(k>0 && k <= n) {
            cout << "Kth Maximum: " << arr[n - k] << endl; // Kth maximum element
            cout << "Kth Minimum: " << arr[k - 1] << endl; // Kth minimum element
        } else {
            cout << "Invalid value of k." << endl; // Handle invalid k
        }
    }
};

int main() {
    Solution solution;
    vector<int> arr = {3, 5, 1, 8, 2}; // Example array
    int k = 2; // Example value of k
    solution.findKthMaxAndMin(arr, k); // Call the function
    return 0; // Return success
}