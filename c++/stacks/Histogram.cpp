#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int histogram(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        int ans = 0;
        stack<int> st;

        // Find nearest smaller to left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack
        while (!st.empty()) st.pop();

        // Find nearest smaller to right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate area
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int curr = heights[i] * width;
            ans = max(ans, curr);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int maxArea = sol.histogram(heights);
    cout << "Largest rectangle area in histogram: " << maxArea << endl;
    return 0;
}
