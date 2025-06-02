#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate =0, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate; // This assumes a majority element always exists
    }
};

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2}; // Example input
    Solution solution; // Create object
    int result = solution.majorityElement(nums); // Call the function
    cout << "Majority element: " << result << endl; // Output the result
    return 0;
}
