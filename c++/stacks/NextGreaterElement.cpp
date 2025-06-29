#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st; // Stack to store indices of elements
        for(int i=n-1; i>=0; i--) {
            while(st.size()>0 && st.top() <= nums[i]) {
                st.pop(); // Pop elements from stack until we find a greater element
            }
            if(st.empty()) {
                result[i] = -1; // If stack is empty, no greater element found
            } else {
                result[i] = st.top(); // The top of the stack is the next greater element
            }
            st.push(nums[i]); // Push current element onto the stack
        }
        return result; // Return the result arra
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 5, 2, 10, 8}; // Example input
    vector<int> result = solution.nextGreaterElement(nums); // Call the function
    cout << "Next Greater Elements: ";
    for(int num : result) {
        cout << num << " "; // Output the result
    }
    cout << endl;
    return 0; // Return success
}