#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> st;

        // Step 1: Push all persons onto the stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Step 2: Find the potential celebrity
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            // If a knows b, then a cannot be celebrity, but b might be
            if (M[a][b] == 1) {
                st.push(b);
            } else {
                st.push(a);
            }
        }

        // If no one left
        if (st.empty()) return -1;

        int candidate = st.top();

        // Step 3: Validate candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // Candidate must not know anyone
                if (M[candidate][i] == 1) return -1;
                // Everyone must know candidate
                if (M[i][candidate] == 0) return -1;
            }
        }

        return candidate;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n = 3;
    int result = solution.celebrity(M, n);
    if (result != -1) {
        cout << "Celebrity is person " << result << endl;
    } else {
        cout << "No celebrity found" << endl;
    }
    return 0; // Return success
}