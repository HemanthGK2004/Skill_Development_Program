#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    bool isSubsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        return isSubsetSumHelper(nums, n, target, dp);
    }

    private:
    bool isSubsetSumHelper(vector<int>& nums, int n, int target, vector<vector<bool>>& dp) {
        // Base case: If target is 0, we can always form it with an empty subset
        if(target == 0) return true;
        if(n<= 0) return false; // If no elements left, we cannot form a positive target

        if(dp[n][target] != false) return dp[n][target]; // Return already computed value

        // If the last element is greater than the target, we cannot include it
        if(nums[n - 1] > target) {
            return dp[n][target] = isSubsetSumHelper(nums, n - 1, target, dp);
        }

        // Check if we can form the target by either including or excluding the last element
        return dp[n][target] = isSubsetSumHelper(nums, n - 1, target, dp) || isSubsetSumHelper(nums, n - 1, target - nums[n - 1], dp);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9; // Example target
    if(solution.isSubsetSum(nums, target)) {
        cout << "Subset with given sum exists." << endl;
    } else {
        cout << "No subset with given sum exists." << endl;
    }
    return 0; // Return success
}