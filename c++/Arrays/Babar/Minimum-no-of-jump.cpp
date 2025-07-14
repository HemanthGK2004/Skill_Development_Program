// minimum number of jumps to reach the end of the array
#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0; // No jumps needed if array has 1 or fewer elements
        int jumps = 0; // Number of jumps made
        int currentEnd = 0; // End of the current jump range
        int farthest = 0; // Farthest point reachable in the next jump
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + arr[i]); // Update the farthest point reachable
            if (i == currentEnd) { // If we have reached the end of the current jump range
                jumps++; // Increment jump count
                currentEnd = farthest; // Update the end of the current jump range
                if (currentEnd >= n - 1) break; // If we can reach or exceed the last index, break
            }
        }
        return jumps; // Return the total number of jumps made
    }
};

int main() {
    Solution solution;
    vector<int> arr = {2, 3, 1, 1, 4}; // Example input
    int result = solution.minJumps(arr); // Call the function
    cout << "Minimum number of jumps to reach the end: " << result << endl; // Output the result
    return 0; // Return success
}