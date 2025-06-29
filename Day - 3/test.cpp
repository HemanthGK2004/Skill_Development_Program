#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProductSubarray(const vector<int>& nums) {
    int maxProd = nums[0];
    int currMax = nums[0];
    int currMin = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(currMax, currMin);

        currMax = max(nums[i], currMax * nums[i]);
        currMin = min(nums[i], currMin * nums[i]);

        maxProd = max(maxProd, currMax);
    }

    return maxProd;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray: " << maxProductSubarray(nums) << endl;
    return 0;
}
