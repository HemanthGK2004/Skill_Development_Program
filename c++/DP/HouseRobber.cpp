#include<iostream>
using namespace std;
#include<vector>


class Solution {
    public:
    int HouseRobber(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        int prev1 = nums[0];
        int prev2= 0 , curr;
        for(int i =1;i<=n;i++){
            int pickUp = nums[i]+ prev2; // Pick the current house and add to the previous non-adjacent house
            int notPick = prev1; // Do not pick the current house, keep the previous maximum
            curr = max(pickUp, notPick); // Take the maximum of both choices
            prev2 = prev1; // Update previous non-adjacent house
            prev1 = curr; // Update previous house
        }
        return prev1; // Return the maximum amount that can be robbed
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 9, 3, 1}; // Example input
    int result = solution.HouseRobber(nums); // Call the function
    cout << "Maximum amount that can be robbed: " << result << endl; // Output the result
    return 0; // Return success
}

// Note: This code assumes that the input vector 'nums' contains non-negative integers representing the amount of money in each house.
// The function calculates the maximum amount that can be robbed without alerting the police by robbing two adjacent houses.