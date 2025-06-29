#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0), right(n, 0);
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        
        // Fill left max array
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        // Fill right max array
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        // Calculate trapped water
        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            totalWater += min(left[i], right[i]) - height[i];
        }
        
        return totalWater;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1}; // Example input
    cout << "Trapped rainwater: " << sol.trap(height) << endl; // Output the result
    return 0; // Return success
}