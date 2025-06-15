#include<iostream>
#include<vector>

using namespace std;
class Solution{
    public:
    void quickSort(vector<int>&arr, int low, int high){
        if(low<high){
            int pivot = partition(arr,low,high);
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
    }
    int partition(vector<int>&arr,int low,int high){
        int pivot = arr[high];
        int i = low - 1;
        for(int j = low;j<high;j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
    }
};
int main() {
    Solution solution;
    vector<int> arr = {10, 7, 8, 9, 1, 5}; // Example input
    int n = arr.size();
    solution.quickSort(arr, 0, n - 1); // Call the function
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " "; // Output the sorted array
    }
    cout << endl; // New line for better readability
    return 0; // Return success
}