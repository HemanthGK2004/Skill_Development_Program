// Password Checker leetcode problem
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
    public:
    bool checkPassword(string password) {
        int len = password.length();
        if (len < 8) return false;
        bool hasUpper = false;
        bool hasLower = false;
        bool hasDigit = false;
        bool hasSpecial = false;
        for (int i = 0; i < len; i++) {
            char c = password[i];
            if (isupper(c)) hasUpper = true;
            if (islower(c)) hasLower = true;
            if (isdigit(c)) hasDigit = true;
            if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*') hasSpecial = true;
        }
        return hasUpper && hasLower && hasDigit && hasSpecial;
    }
};
int main() {
    Solution s;
    string password = "Password@123";
    cout << s.checkPassword(password) << endl;
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
// Input: Password@123
// Output: 1
// Input: Password123
// Output: 0
// Input: Password@1234
// Output: 0