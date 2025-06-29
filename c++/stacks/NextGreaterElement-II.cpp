#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int>nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int,int>map;
        stack<int>st;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop(); // Pop elements from stack until we find a greater element
            }
            if(st.empty()) {
                map[nums2[i]] = -1; // If stack is empty, no greater element found
            } else {
                map[nums2[i]] = st.top(); // The top of the stack is the next greater element
            }
            st.push(nums2[i]); // Push current element onto the stack
        }
        vector<int>result;
        for(int i = 0; i < nums1.size(); i++) {
            result.push_back(map[nums1[i]]); // Fill result with next greater elements
        }
        return result; // Return the result array
    }
};
int main() {
    Solution solution;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = solution.nextGreaterElement(nums1, nums2); // Call the function
    cout << "Next Greater Elements: ";
    for(int num : result) {
        cout << num << " "; // Output the result
    }
    cout << endl;
    return 0; // Return success
}