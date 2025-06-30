#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> stockSpan(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n, 1); // Initialize ans array with 1
        stack<int> st; // Stack to store indices of prices
        for (int i = 0; i < n; i++) {
            // Pop elements from stack while the current price is greater than or equal to the price at the index stored at the top of the stack
            while (!st.empty() && prices[st.top()]<=prices[i]) {
                st.pop();
            }
            // If stack is empty, it means all previous prices are less than current price
            if (st.empty()) {
                ans[i] = i + 1; // ans is i + 1
            } else {
                ans[i] = i - st.top(); // Span is current index - index of last higher price
            }
            st.push(i); // Push current index onto the stack
        }
        return ans; // Return the span array
    }
};

int main() {
    Solution solution;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85}; // Example input
    vector<int> result = solution.stockSpan(prices); // Call the function
    cout << "Stock Span: ";
    for (int span : result) {
        cout << span << " "; // Output the result
    }
    cout << endl;
    return 0; // Return success
}
// This code calculates the stock span for each day based on the given prices.
// The stock span is defined as the number of consecutive days before the current day where the price was less than or equal to the current day's price.