#include<iostream>
#include<vector>

using namespace std;
class Solution {
    public:
    int missingNumber(vector<int>&nums){
        long long n = nums.size();
        long long expectedSum = n *(n+1)/2;
        long long actualSum = 0;
        for(int num: nums){
            actualSum += num;
        }
        return expectedSum - actualSum; // Return the missing number
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1,2,3,5}; // Example input
    int result = solution.missingNumber(nums); // Call the function
    cout << "Missing number: " << result << endl; // Output the result
    return 0; // Return success
}
