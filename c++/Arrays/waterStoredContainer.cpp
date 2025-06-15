#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int waterStoredContainer(vector<int>&heights){
        int maxWater = 0;
        int left = 0;
        int right = heights.size()-1;
        while(left < right){
            int width = right - left;
            int height = min(heights[left],heights[right]);
            int currentWater = width * height;
            maxWater = max(maxWater, currentWater);
            heights[left]<heights[right] ? left++ : right--;
        }
        return maxWater;
    }
};
int main() {
    Solution solution;
    vector<int> heights = {1,8,6,2,5,4,8,3,7}; // Example input
    int result = solution.waterStoredContainer(heights); // Call the function
    cout << "Maximum water stored: " << result << endl; // Output the result
    return 0; // Return success
}