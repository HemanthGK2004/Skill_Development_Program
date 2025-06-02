#include<iostream>
#include<vector>

using namespace std;
class Solution {
    public:
    int missingNumber(vector<int>&nums){
        int n = nums.size();
        int expectedSum = n *(n+1)/2;
        int actualSum = 0;
        for(int num: nums){
            actualSum += num;
        }
        return expectedSum - actualSum; // Return the missing number
    }
};
int main() {
    Solution solution;
    vector<int> nums = {3, 0, 1}; // Example input
    int result = solution.missingNumber(nums); // Call the function
    cout << "Missing number: " << result << endl; // Output the result
    return 0; // Return success
}
