// daily temperature problem
// https://leetcode.com/problems/daily-temperatures/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0); // Initialize result array with 0
        stack<int> st; // Stack to store indices of temperatures
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int index = st.top(); // Get the index of the previous temperature
                st.pop(); // Remove it from the stack
                result[index] = i - index; // Calculate the number of days until a warmer temperature
            }
            st.push(i); // Push current index onto the stack
        }
        return result; // Return the result array
    }
};

int main() {
    Solution solution;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73}; // Example input
    vector<int> result = solution.dailyTemperatures(temperatures); // Call the function

    cout << "Days until warmer temperature: ";
    for (int days : result) {
        cout << days << " "; // Output the result
    }
    cout << endl;

    return 0; // Return success
}