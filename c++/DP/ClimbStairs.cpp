#include<iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n)
    {
        if (n <= 2) return n; // Base cases: 1 way for 1 step, 2 ways for 2 steps
        int first = 1, second = 2, current;
        for (int i = 3; i <= n; ++i) {
            current = first + second; // Current ways is the sum of the previous two
            first = second; // Move to the next step
            second = current; // Update second to current
        }
        return second; // Return the total ways to climb n steps
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;
    cout << "Number of ways to climb " << n << " steps: " << sol.climbStairs(n) << endl;
    return 0; // Return success
}

// int climb(int n, vector<int> &dp) {
//     if (n <= 2) return n;
//     if (dp[n] != -1) return dp[n];
//     return dp[n] = climb(n-1, dp) + climb(n-2, dp);
// }

// int climbStairs(int n) {
//     vector<int> dp(n+1, -1);
//     return climb(n, dp);
// }
