#include<iostream>
#include<vector>

using namespace std;
class Solution{
    public:
    vector<int>productofArray2(vector<int>&nums){
        int n = nums.size();
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
        vector<int>ans(n,1);
        prefix[0]=1;
        suffix[n-1]=1;
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        for(int i = n-2;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }
        for(int i = 0;i<n;i++){
            ans[i] = prefix[i]*suffix[i];
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4}; // Example input
    vector<int> result = solution.productofArray2(nums); // Call the function
    cout << "Product array: ";
    for (int num : result) {
        cout << num << " "; // Output the result
    }
    cout << endl; // New line for better readability
    return 0; // Return success
}