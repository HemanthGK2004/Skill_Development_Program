#include<iostream>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
};

int main() {
    Solution solution;
    int a = 56, b = 98; // Example input
    int result = solution.gcd(a, b); // Call the function
    cout << "GCD of " << a << " and " << b << " is: " << result << endl; // Output the result
    return 0; // Return success
}
