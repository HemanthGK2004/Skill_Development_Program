#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
#include<set>

class Solution {
public:
    vector<int> unionOfArrays(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        set<int> uniqueElements; // Use a set to store unique elements
        
        // Insert elements from the first array
        for (int num : arr1) {
            uniqueElements.insert(num);
        }
        
        // Insert elements from the second array
        for (int num : arr2) {
            uniqueElements.insert(num);
        }
        
        // Copy unique elements to the result vector
        for (int num : uniqueElements) {
            result.push_back(num);
        }
        
        return result; // Return the union of both arrays
    }
    void intersectionOfArrays(vector<int>& arr1, vector<int>& arr2) {
        set<int> set1(arr1.begin(), arr1.end()); // Create a set from arr1
        set<int> intersection; // Set to store intersection elements
        
        // Find intersection elements
        for (int num : arr2) {
            if (set1.find(num) != set1.end()) {
                intersection.insert(num); // If num is in set1, add to intersection
            }
        }
        
        // Print the intersection elements
        cout << "Intersection: ";
        for (int num : intersection) {
            cout << num << " "; // Output each element in the intersection
        }
        cout << endl; // New line for better readability
    }   
};
int main() {
    Solution solution;
    vector<int> arr1 = {1, 2, 3, 4, 5}; // Example first array
    vector<int> arr2 = {4, 5, 6, 7, 8}; // Example second array
    
    // Find union of both arrays
    vector<int> unionResult = solution.unionOfArrays(arr1, arr2);
    cout << "Union: ";
    for (int num : unionResult) {
        cout << num << " "; // Output each element in the union
    }
    cout << endl; // New line for better readability
    
    // Find intersection of both arrays
    solution.intersectionOfArrays(arr1, arr2);
    
    return 0; // Return success
}
