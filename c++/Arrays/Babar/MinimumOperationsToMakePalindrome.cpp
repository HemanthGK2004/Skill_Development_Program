// Minimum operatiosn to make palindrome
#include<iostream>
using namespace std;
#include<vector>

class solution{
    public:
    int minOperations(vector<int>&arr){
        int n = arr.size();
        int left = 0, right = n - 1;
        int operations = 0;
        while (left < right) {
            if (arr[left] == arr[right]) {
                left++;
                right--;
            } else if (arr[left] < arr[right]) {
                arr[left + 1] += arr[left];
                left++;
                operations++;
            } else {
                arr[right - 1] += arr[right];
                right--;
                operations++;
            }
        }
        return operations;
    }
};
int main(){
    solution sol;
    vector<int> arr = {1, 4,5,1}; // Example input
    int result = sol.minOperations(arr); // Call the function
    cout << "Minimum operations to make palindrome: " << result << endl; // Output the result
    return 0; // Return success
}