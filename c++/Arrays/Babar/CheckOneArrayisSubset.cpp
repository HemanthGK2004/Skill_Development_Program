// check one array is subset of another array
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isSubset(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> set1(arr1.begin(), arr1.end()); // Create a set from arr1
        
        // Check if all elements of arr2 are in set1
        for (int num : arr2) {
            if (set1.find(num) == set1.end()) {
                return false; // If any element is not found, return false
            }
        }
        return true; // All elements of arr2 are in arr1
    }
};

int main() {
    Solution solution;
    vector<int> arr1 = {1, 2, 3, 4, 5}; // Example first array
    vector<int> arr2 = {2, 3}; // Example second array
    
    if (solution.isSubset(arr1, arr2)) {
        cout << "Array 2 is a subset of Array 1" << endl;
    } else {
        cout << "Array 2 is not a subset of Array 1" << endl;
    }

    return 0;
}