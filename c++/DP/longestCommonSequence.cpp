#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    int LCS(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return LCSHelper(s1, s2, m, n, dp);
    }

    private:
    int LCSHelper(string &s1, string &s2, int m, int n, vector<vector<int>> &dp) {
        if (m == 0 || n == 0) return 0; // Base case: if either string is empty
        if (dp[m][n] != -1) return dp[m][n]; // Return already computed value

        if(s1[m-1] == s2[n-1]) {
            return dp[m][n] = 1 + LCSHelper(s1, s2, m - 1, n - 1, dp); // Characters match
        }
        else{
            return dp[m][n] = max(LCSHelper(s1, s2, m - 1, n, dp), LCSHelper(s1, s2, m, n - 1, dp)); // Characters do not match
        }
    }
};

int main() {
    Solution solution;
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int result = solution.LCS(s1, s2); // Call the function
    cout << "Length of Longest Common Subsequence: " << result << endl; // Output the result
    return 0; // Return success
}