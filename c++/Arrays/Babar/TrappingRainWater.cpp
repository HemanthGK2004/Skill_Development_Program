// Traping rain water problem
// https://leetcode.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> left(n), right(n);
    left[0] = height[0];
    for (int i = 1; i < n; ++i) {
        left[i] = max(left[i - 1], height[i]);
    }

    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        right[i] = max(right[i + 1], height[i]);
    }

    int waterTrapped = 0;
    for (int i = 0; i < n; ++i) {
        waterTrapped += min(left[i], right[i]) - height[i];
    }

    return waterTrapped;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1}; // Example input
    int result = trap(height); // Call the function
    cout << "Total water trapped: " << result << endl; // Output the result
    return 0; // Return success
}