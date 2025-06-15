#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<limits.h>
#include<string>
using namespace std;
class Solution {
    public:
    int maxAbsoluteSum(vector<int>&nums){
        int sum = 0 , maxSum = 0, minSum = 0;
        for(int num:nums){
            sum+=num;
            if(sum > maxSum){
                maxSum = sum;
            }
            if(sum < minSum){
                minSum = sum;
            }
        }
        return abs(maxSum - minSum);
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1,-3,2,3,-4}; // Example input
    int result = solution.maxAbsoluteSum(nums); // Call the function
    cout << "Maximum absolute sum: " << result << endl; // Output the result
    return 0; // Return success
}