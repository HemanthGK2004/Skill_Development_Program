#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include<unordered_map>
class Solution{
    public:
    vector<int>merge2SortedArray(vector<int>&A,int m , vector<int>&B ,int n){
        int idx = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >=0){
            if(A[i]>B[j]){
                A[idx--]=A[i--];
            }
            else{
                A[idx--]=B[j--];
            }
        }
        while(j>=0){
            A[idx--] = B[j--];
        }
        return A;
    }
};
int main() {
    Solution solution;
    vector<int> A = {1, 3, 5, 0, 0, 0}; // Example input
    vector<int> B = {2, 4, 6}; // Example input
    int m = 3; // Number of elements in A
    int n = 3; // Number of elements in B
    vector<int> result = solution.merge2SortedArray(A, m, B, n); // Call the function
    cout << "Merged array: ";
    for (int num : result) {
        cout << num << " "; // Output the result
    }
    cout << endl; // New line for better readability
    return 0; // Return success
}