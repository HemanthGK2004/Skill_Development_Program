#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    vector<int>product(vector<int>&nums){
        int n = nums.size();
        vector<int>ans(n,1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    ans[i] *= nums[j];
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4}; // Example input
    vector<int> result = solution.product(nums); // Call the function
    cout << "Product array: ";
    for (int num : result) {
        cout << num << " "; // Output the result
    }
    cout << endl; // New line for better readability
    return 0; // Return success
}