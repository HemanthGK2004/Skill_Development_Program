#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
    public:
    vector<int> nextGreaterElement(vector<int>& nums){
        int n = nums.size();
        vector<int> result(n, -1); // Initialize result array with -1
        stack<int> st; // Stack to store indices of elements
        for(int i=0;i<2*n;i++) {
            int index = i % n; // Use modulo to wrap around the array
            while(!st.empty() && nums[st.top()] < nums[index]) {
                result[st.top()] = nums[index]; // Update result with next greater element
                st.pop(); // Pop the index from stack
            }
            if(i < n) { // Only push indices for the first pass
                st.push(index); // Push current index onto the stack
            }
        }
        return result; // Return the result array
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1};
    vector<int> result = solution.nextGreaterElement(nums); // Call the function
    cout << "Next Greater Elements: ";
    for(int num : result) {
        cout << num << " "; // Output the result
    }
    cout << endl;
    return 0; // Return success
}
// This code finds the next greater element for each element in a circular array.
// It uses a stack to keep track of indices and updates the result array with the next greater elements.