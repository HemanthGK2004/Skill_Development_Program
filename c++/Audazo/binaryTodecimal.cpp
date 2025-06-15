#include<iostream>
#include<cmath>
using namespace std;
class Solution {
    public:
    int binaryToDecimal(int n){
        int ans = 0;
        int base = 1; // Initialize base to 1 (2^0)
        while(n > 0){
            int lastDigit = n % 10; // Get the last digit
            ans += lastDigit * base; // Add to the answer
            base *= 2; // Update base to the next power of 2
            n /= 10; // Remove the last digit
        }
        return ans; // Return the decimal value
    }
};
int main() {
    Solution solution;
    int n = 1011; // Example binary input
    int result = solution.binaryToDecimal(n); // Call the function
    cout << "Decimal value: " << result << endl; // Output the result
    return 0; // Return success
}