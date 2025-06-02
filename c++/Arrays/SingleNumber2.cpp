#include<iostream>
#include<vector>

using namespace std;
class Solution {
    public:
    int singleNumber2(vector<int>&nums){
        int result =0;
        for(int i=0;i<32;i++){
            int count =0;
            for(int num: nums){
                if(num&(1<<i)){
                    count++;
                }
            }
            if(count%3!=0){
                result |= (1<<i);
            }
        }
        return result;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2, 2, 3, 2}; // Example input
    int result = solution.singleNumber2(nums); // Call the function
    cout << "Single number appearing once: " << result << endl; // Output the result
    return 0; // Return success
}