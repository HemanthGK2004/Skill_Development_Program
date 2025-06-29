// Cyclic rotation of an array by one position to the right
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void cyclicRotate(vector<int>& arr) {
        if (arr.empty()) return; // Handle empty array case
        int last = arr.back(); // Store the last element
        for (int i = arr.size() - 1; i > 0; --i) {
            arr[i] = arr[i - 1]; // Shift elements to the right
        }
        arr[0] = last; // Place the last element at the front
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5}; // Example array
    solution.cyclicRotate(arr); // Rotate the array
    cout << "Cyclically rotated array: ";
    for (int num : arr) {
        cout << num << " "; // Output the rotated array
    }
    cout << endl; // New line for better readability
    return 0; //
}