#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int MatrixChainMultiplication(vector<int>& arr, int N) {
        vector<vector<int>> dp(N, vector<int>(N, -1)); // Use -1 for uninitialized cells
        return MatrixChainHelper(arr, 1, N - 1, dp);
    }

private:
    int MatrixChainHelper(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int result = INT_MAX;
        for (int k = i; k < j; k++) {
            int cost = MatrixChainHelper(arr, i, k, dp)
                    + MatrixChainHelper(arr, k + 1, j, dp)
                    + arr[i - 1] * arr[k] * arr[j];
            result = min(result, cost);
        }

        return dp[i][j] = result;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {10, 20, 30, 40, 30}; // Example dimensions
    int N = arr.size();
    int result = solution.MatrixChainMultiplication(arr, N);
    cout << "Minimum number of multiplications is: " << result << endl;
    return 0;
}
