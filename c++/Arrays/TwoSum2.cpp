#include<iostream>
#include<vector>
using namespace std;
#include<unordered_map>
class Solution {
    public:
    vector<int>TwoSum2(vector<int>& nums ,int target){
        vector<int>ans;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int first = nums[i];
            int second = target - first;
            if(mp.find(second)!=mp.end()){
                ans.push_back(i);
                ans.push_back(second);
                break;
            }
            mp[first] = i;
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15}; // Example input
    int target = 9; // Example target value
    vector<int> result = solution.TwoSum2(nums, target); // Call the function
    if (result.size() == 2) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl; // Output the result
    } else {
        cout << "No two sum solution found." << endl; // Handle case where no solution is found
    }
    return 0; // Return success
}