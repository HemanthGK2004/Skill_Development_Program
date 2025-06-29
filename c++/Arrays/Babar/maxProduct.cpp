#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int maxProduct(vector<int>& nums){
        int sum = 0;
        int maxSum = 0;
        int minSum = 0;
        for(int num:nums){
            sum+=num;
            if(sum > maxSum){
                maxSum = sum; // Update maxSum if current sum is greater
            }
            if(sum < minSum){
                minSum = sum; // Update minSum if current sum is less
            }
        }
        return abs(maxSum - minSum); // Return the absolute difference between maxSum and minSum
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, -2, 4}; // Example input
    int result = solution.maxProduct(nums); // Call the function
    cout << "Maximum product of contiguous subarray: " << result << endl; // Output the result
    return 0; // Return success
}