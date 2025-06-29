#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int totalWaysToCover(int n) {
        if (n== 0) return 1; // Base case: 1 way to cover 0 length
        if (n < 0) return 0; // No way to cover negative length

        // Recursive case: sum of ways to cover n-1, n-2, and n-3 lengths
        return totalWaysToCover(n - 1) + totalWaysToCover(n - 2) + totalWaysToCover(n - 3);
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the length to cover: ";
    cin >> n; // Input the length
    cout << "Total ways to cover length " << n << ": " << solution.totalWaysToCover(n) << endl; // Output the result
    return 0; // Return success
}