#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    int powerOf2(int n){
        if(n==0) return 0;
        return (n & (n-1)) == 0; // Check if n is a power of 2
    }
};
int main() {
    Solution solution;
    int n = 16; // Example input
    int result = solution.powerOf2(n); // Call the function
    cout << "Is " << n << " a power of 2? " << (result ? "Yes" : "No") << endl; // Output the result
    return 0; // Return success
}