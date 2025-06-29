#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int totalWaysToCover(int n) {
        if(n==0) return 1; // Base case: 1 way to cover 0 length
        if(n < 0) return 0; // No way to cover negative length
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // 1 way to cover length 0
        
        for(int i = 1; i <= n; i++) {
            if(i >= 1)   dp[i] += dp[i - 1]; // Cover with 1 step
            if(i >= 2) dp[i] += dp[i - 2]; // Cover with 2 steps
            if(i >= 3) dp[i] += dp[i - 3]; // Cover with 3 steps
        }
        return dp[n]; // Return the total ways to cover length n
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the length to cover: ";
    cin >> n; // Input the length
    cout << "Total ways to cover length " << n << ": " << solution.totalWaysToCover(n) << endl; // Output the result
    return 0; // Return success
}
// This code uses dynamic programming to efficiently calculate the total ways to cover a length n using steps of 1, 2, or 3.
// It initializes a dp array where dp[i] represents the number of ways to cover length i.
// The final result is stored in dp[n], which is returned at the end.
