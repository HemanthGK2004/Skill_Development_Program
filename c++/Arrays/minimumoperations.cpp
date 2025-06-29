#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            if (num < k) {
                pq.push(num);
            }
        }
        int oper = 0;
        while (pq.size() > 1) { // Need at least two elements to perform operation
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            oper++;
            long long newValue = 2LL * x + y;
            if (newValue < k) {
                pq.push(static_cast<int>(newValue));
            }
        }
        // If one element remains and it's still < k, it's impossible to make it >= k
        if (!pq.empty() && pq.top() < k) {
            return -1; // Or any value that represents failure if required
        }
        return oper;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4}; // Example input
    int k = 10; // Example k value
    int result = solution.minimumOperations(nums, k); // Call the function
    cout << "Minimum operations: " << result << endl; // Output the result
    return 0; // Return success
}
