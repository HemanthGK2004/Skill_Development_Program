#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
    vector<int>dutchNationalFlag(vector<int>&arr){
        int low = 0;
        int mid = 0;
        int high = arr.size()-1;
        while(mid<=high)
        {
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
        return arr;
    }
};
int main() {
    Solution solution;
    vector<int> arr = {2, 0, 2, 1, 1, 0}; // Example input
    solution.dutchNationalFlag(arr); // Call the function
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " "; // Output the sorted array
    }
    cout << endl; // New line for better readability
    return 0; // Return success
}