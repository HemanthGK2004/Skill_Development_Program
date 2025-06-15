#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> pairSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < nums.size(); ++i) {
            numWithIndex.push_back({nums[i], i});
        }
        sort(numWithIndex.begin(), numWithIndex.end());
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int sum = numWithIndex[i].first + numWithIndex[j].first;
            if (sum == target) {
                return {numWithIndex[i].second, numWithIndex[j].second};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};
int main() {
    Solution solution;
    vector<int> nums = {5, 2, 11, 1, 7, 15};
    int target = 9;
    vector<int> result = solution.pairSum(nums, target);
    if (result.size() == 2) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }
    return 0;
}