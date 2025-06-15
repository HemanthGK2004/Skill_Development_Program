#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
    int lengthLongestFibonacciSequence(vector<int>&nums){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        int maxLength = 0;
        for(int curr = 2;curr<n;curr++){
            int start = 0;
            int end = curr-1;
            while(start < end){
                int pairSum = nums[start] + nums[end];
                if(pairSum > nums[curr]){
                    end--;
                }
                else if(pairSum < nums[curr]){
                    start++;
                }
                else{
                    dp[end][curr] = dp[start][end] + 1;
                    maxLength = max(maxLength,dp[end][curr]);
                    start++;
                    end--;
                }
            }
        }
        return maxLength == 0 ? 0 : maxLength + 2;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1,2,3,4,5,6,7,8}; // Example input
    int result = solution.lengthLongestFibonacciSequence(nums); // Call the function
    cout << "Length of longest Fibonacci-like subsequence: " << result << endl; // Output the result
    return 0; // Return success
}