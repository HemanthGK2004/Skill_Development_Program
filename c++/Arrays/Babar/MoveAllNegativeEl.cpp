#include<iostream>
using namespace std;
#include<vector>

class solution{
    public:
    void moveAllNegativeEl(vector<int>&arr){
        int n = arr.size();
        int j = 0; // Pointer for the next position to place a non-negative element
        for(int i = 0; i < n; i++){
            if(arr[i] >= 0){ // If the current element is non-negative
                swap(arr[i], arr[j]); // Swap it with the element at position j
                j++; // Move j to the next position
            }
        }
    }
};

int main() {
    solution sol; // Create an instance of the solution class
    vector<int> arr = {-1, 2, -3, 4, -5, 6}; // Example array with negative and non-negative elements
    cout << "Original array: ";
    for(int num : arr) {
        cout << num << " "; // Print original array
    }
    cout << endl;
    
    sol.moveAllNegativeEl(arr); // Move all negative elements to the end
    
    cout << "Array after moving all negative elements: ";
    for(int num : arr) {
        cout << num << " "; // Print modified array
    }
    cout << endl; // New line for better readability
    return 0; // Return success
}