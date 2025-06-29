#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> previousSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1); // Initialize ans array with -1
        stack<int> st; // Stack to store indices of elements
        for (int i = 0; i < n; i++) {
            // Pop elements from stack while the current element is less than or equal to the element at the index stored at the top of the stack
            while (!st.empty() && arr[i] <= st.top()) {
                st.pop();
            }
            // If stack is empty, it means no previous smaller element exists
            if (st.empty()) {
                ans[i] = -1; // No previous smaller element
            } else {
                ans[i] = st.top(); // The top of the stack is the previous smaller element
            }
            st.push(arr[i]); // Push current index onto the stack
        }
        return ans; // Return the previous smaller elements array
    }
};

int main() {
    Solution solution;
    vector<int> arr = {4, 5, 2, 10, 8}; // Example input
    vector<int> result = solution.previousSmaller(arr); // Call the function
    cout << "Previous Smaller Elements: ";
    for (int num : result) {
        cout << num << " "; // Output the result
    }
    cout << endl;
    return 0; // Return success
}