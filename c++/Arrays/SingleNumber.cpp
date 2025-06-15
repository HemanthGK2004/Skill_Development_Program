#include<iostream>
#include<vector>

using namespace std;
class Solution {
    public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int num: nums){
            result ^= num; // XOR operation
        }
        return result; // Return the single number
    }
};
int main() {
    Solution solution;
    vector<int> nums = {4, 1, 2, 1, 2}; // Example input
    int result = solution.singleNumber(nums); // Call the function
    cout << "Single number: " << result << endl; // Output the result
    return 0; // Return success
}