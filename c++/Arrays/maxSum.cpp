#include<iostream>
#include<vector>

using namespace std;
class Solution {
    public:
    int maximumSubArray(vector<int>&nums){
        int maxSum[82] = {0}; // Initialize maxSum array to 0
        int ans = -1;
        for(int x :nums){
            int sum = 0,temp = x;
            while(temp!= 0){
                sum += temp%10; // Calculate the sum of digits
                temp /= 10; // Reduce temp by dividing by 10
            }
            if(maxSum[sum]!= 0){
                ans = max(ans,x+maxSum[sum]); // Update ans if a better sum is found
            }
            maxSum[sum] = max(maxSum[sum],x); // Update maxSum for the current digit sum
        }
        return ans; // Return the maximum sum found
    }
};
int  main() {
    Solution solution;
    vector<int> nums = {18,43,36,13,7}; // Example input
    int result = solution.maximumSubArray(nums); // Call the function
    cout << "Maximum sum of contiguous subarray: " << result << endl; // Output the result
    return 0; // Return success
}
