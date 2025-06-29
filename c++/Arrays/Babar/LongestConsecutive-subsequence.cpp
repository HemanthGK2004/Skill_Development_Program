#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(const vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLength = 0;

    for (int num : nums) {
        // Start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currNum = num;
            int currLength = 1;

            while (numSet.find(currNum + 1) != numSet.end()) {
                currNum++;
                currLength++;
            }

            maxLength = max(maxLength, currLength);
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Length of longest consecutive subsequence: " << longestConsecutive(nums) << endl;
    return 0;
}
