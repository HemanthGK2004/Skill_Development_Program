// #include<iostream>
// using namespace std;

// class solution{
//     public:
//     void reverseArray(int arr[], int n) {
//         int start = 0; // Initialize start index
//         int end = n - 1; // Initialize end index
//         while (start < end) { // Loop until start index is less than end index
//             swap(arr[start], arr[end]); // Swap elements at start and end indices
//             start++; // Move start index forward
//             end--; // Move end index backward
//         }
//     }
//     void printArray(int arr[], int n) {
//         for (int i = 0; i < n; i++) { // Loop through the array
//             cout << arr[i] << " "; // Print each element
//         }
//         cout << endl; // Print newline after the array
//     }
// };

// int main() {
//     solution sol; // Create an instance of the solution class
//     int arr[] = {1, 2, 3, 4, 5}; // Example array
//     int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
//     cout << "Original array: "; 
//     sol.printArray(arr, n); // Print original array
//     sol.reverseArray(arr, n); // Reverse the array
//     cout << "Reversed array: ";
//     sol.printArray(arr, n); // Print reversed array
//     return 0; // Return success
// }
#include<iostream>
#include<algorithm>
using namespace std;

class solution {
    public:
    void reverseArray(int arr[], int n) {
        reverse(arr, arr + n); // Use std::reverse function
    }
    void printArray(int arr[], int n) {
        for (int i = 0; i < n; i++) { // Loop through the array
            cout << arr[i] << " "; // Print each element
        }
        cout << endl; // Print newline after the array
    }
};

int main() {
    solution sol; // Create an instance of the solution class
    int arr[] = {1, 2, 3, 4, 5}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    cout << "Original array: "; 
    sol.printArray(arr, n); // Print original array
    sol.reverseArray(arr, n); // Reverse the array
    cout << "Reversed array: ";
    sol.printArray(arr, n); // Print reversed array
    return 0; // Return success
}
// This code uses the standard library's reverse function to reverse the array.
// It also includes a print function to display the array before and after reversal.