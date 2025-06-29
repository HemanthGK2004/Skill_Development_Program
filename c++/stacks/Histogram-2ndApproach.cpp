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
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        for(int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] >= curr) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<int> heights = {2, 1, 5, 6, 2, 3}; // Example input
    int result = solution.largestRectangleArea(heights); // Call the function
    cout << "Largest Rectangle Area: " << result << endl; // Output the result
    return 0; // Return success
}