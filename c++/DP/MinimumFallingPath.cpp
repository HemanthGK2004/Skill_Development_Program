#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<string>
using namespace std;

class Solution {
    public:
    int MinimumFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i =1;i<n;i++){
            for(int j =0;j<n;j++){
                int up = dp[i-1][j]; // Coming from the top
                int leftDiagonal = (j > 0) ? dp[i-1][j-1] : INT_MAX;
                int rightDiagonal = (j < n-1) ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({up, leftDiagonal, rightDiagonal}); // Take the minimum of the three options
            }
        }
        int result = INT_MAX;
        for(int j =0;j<n;j++){
            result = min(result, dp[n-1][j]); // Find the minimum in the last row
        }
        return result; // Return the minimum falling path sum
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    int result = solution.MinimumFallingPathSum(matrix); // Call the function
    cout << "Minimum Falling Path Sum: " << result << endl; // Output the result
    return 0; // Return success
}