#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int longestIncreasingSubsequence(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0; // Handle empty array case
        int maxLength = 1; // Initialize maxLength to 1
        vector<int>dp(n, 1); // Initialize dp array with 1s
        for(int i =0;i<n;i++){
            for(int j =0;j<i;j++){
                if(nums[j]< nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1); // Update dp[i] if a longer subsequence is found
                }
            }
            maxLength = max(maxLength, dp[i]); // Update maxLength if a longer subsequence is found
        }
        return maxLength; // Return the length of the longest increasing subsequence
    }
};

int main() {
    Solution solution;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18}; // Example input
    int result = solution.longestIncreasingSubsequence(nums); // Call the function
    cout << "Length of longest increasing subsequence: " << result << endl; // Output the result
    return 0; // Return success
}
