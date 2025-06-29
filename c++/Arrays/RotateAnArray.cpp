//Rotate an array by d elements
#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse
using namespace std;

class Solution {
public:
    void rotateArray(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n; // Handle cases where d >= n
        //Right rotate the array by d elements
        reverse(arr.begin(), arr.end()); // Reverse the entire array
        reverse(arr.begin(), arr.begin() + d); // Reverse the first n-d elements
        reverse(arr.begin() + d, arr.end()); // Reverse the last d elements

        //left rotate the array by d elements
        reverse(arr.begin(), arr.begin()+d); // Reverse the first d elem
        reverse(arr.begin()+d, arr.end()); // Reverse the last n-d elements
        reverse(arr.begin(), arr.end()); // Reverse the entire array again
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7}; // Example input
    int d = 3; // Number of positions to rotate
    solution.rotateArray(arr, d); // Call the function
    cout << "Rotated array: ";
    for (int num : arr) {
        cout << num << " "; // Output the rotated array
    }
    cout << endl; // New line for better readability
    return 0; // Return success
}