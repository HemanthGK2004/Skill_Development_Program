// Common elements in three sorted arrays
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<int> commonElements(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> result;
        int i = 0, j = 0, k = 0;
        while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                result.push_back(arr1[i]); // Found common element
                i++; j++; k++; // Move all pointers forward
            } else if (arr1[i] < arr2[j]) {
                i++; // Move pointer of arr1 forward
            } else if (arr2[j] < arr3[k]) {
                j++; // Move pointer of arr2 forward
            } else {
                k++; // Move pointer of arr3 forward
            }
        }
        return result; // Return the vector of common elements
    }
};

int main() {
    Solution solution;
   vector<int>arr1= {1, 5, 10, 20, 40, 80};
    vector<int>arr2 = {6, 7, 20, 80, 100};
    vector<int>arr3= {3, 4, 15, 20, 30, 70, 80, 120};
    
    // Sort the arrays before finding common elements
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    sort(arr3.begin(), arr3.end());
    
    vector<int> result = solution.commonElements(arr1, arr2, arr3);
    
    cout << "Common elements: ";
    for (int num : result) {
        cout << num << " "; // Output each common element
    }
    cout << endl; // New line for better readability
    return 0; // Return success
}
// This code finds common elements in three sorted arrays and prints them.
// It uses a three-pointer technique to efficiently find common elements in O(n) time complexity.