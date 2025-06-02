#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (n == 0) return 1;
        if (x == -1) return (n % 2 == 0) ? 1 : -1;

        long long binary = n;
        if (binary < 0) binary = -binary;

        double ans = 1;
        while (binary > 0) {
            if (binary % 2 == 1) {
                ans *= x;
            }
            x *= x;
            binary /= 2;
        }

        return (n < 0) ? 1 / ans : ans;
    }
};

int main() {
    Solution solution;
    double x = 2.0; // Example base
    int n = -3;     // Example negative exponent
    double result = solution.myPow(x, n); // Call the function
    cout << "Result: " << result << endl; // Output the result
    return 0;
}
