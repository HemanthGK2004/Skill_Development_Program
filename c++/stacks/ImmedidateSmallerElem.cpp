#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    public:
    void immediateSmaller(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(arr[i+1]<arr[i]){
                arr[i] = arr[i+1]; // If next element is smaller, replace current element with next
            }
            else{
                arr[i] = -1; // If next element is not smaller, replace current element with -1
            }
        }
        arr[n-1] = -1; // The last element has no next element, so set it to -1
    }
};
int main() {
    Solution obj;
    vector<int> arr = {4, 5, 2, 10, 8}; // Example input
    obj.immediateSmaller(arr);
    for(int i : arr) {
        cout << i << " ";
    }
    return 0;
} 
