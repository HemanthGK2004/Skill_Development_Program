#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    vector<int>threeSum(vector<int>&nums){
        int n = nums.size();
        for(int i =0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        return {nums[i],nums[j],nums[k]};
                    }
                }
            }
        }
        return {};
    }
};
int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; // Example input
    vector<int> result = solution.threeSum(nums); // Call the function
    if (result.size() == 3) {
        cout << "Triplet: " << result[0] << ", " << result[1] << ", " << result[2] << endl; // Output the result
    } else {
        cout << "No triplet found." << endl; // Handle case where no triplet is found
    }
    return 0; // Return success
}