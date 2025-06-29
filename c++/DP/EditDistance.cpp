#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int editMindistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases
        for (int i = 0; i <= m; i++) dp[i][0] = i; // Deletion
        for (int j = 0; j <= n; j++) dp[0][j] = j; // Insertion

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) { // ✅ corrected j <= n
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({ dp[i][j - 1],     // Insert
                                         dp[i - 1][j],     // Delete
                                         dp[i - 1][j - 1]  // Replace
                                    });
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string s1 = "kitten";
    string s2 = "sitting";
    int result = sol.editMindistance(s1, s2);
    cout << "Minimum Edit Distance: " << result << endl;
    return 0;
}
