#include<iostream>
#include<vector>
using namespace std;

vector<int>twoSum(vector<int>&nums, int target){
        int n = nums.size();

        for(int i =0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
}
int main(){
    vector<int>nums = {5,2,11,1,7,15};
    int target = 9;
    vector<int>result = twoSum(nums, target);
    if(result.size() == 2){
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }
    // Test case
    return 0;
}