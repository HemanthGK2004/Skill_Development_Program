#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    // Function to count the number of 1 bits in an integer
    int hammingWeight(int n){
        int count =0;
        while(n >0){
            count += (n & 1);
            n >>= 1; // Right shift n by 1
        }
        return count; // Return the number of 1 bits
    }
};
int main() {
    Solution solution;
    int n = 11; // Example input
    int result = solution.hammingWeight(n); // Call the function
    cout << "Number of 1 bits in " << n << ": " << result << endl; // Output the result
    return 0; // Return success
}