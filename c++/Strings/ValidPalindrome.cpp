#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isAlpha(char ch) {
        return (ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z');
    }

    bool isPalindrome(string str) {
        int n = str.length();
        int start = 0;
        int end = n - 1;

        while (start < end) {
            if (!isAlpha(str[start])) {
                start++;
                continue;
            }
            if (!isAlpha(str[end])) {
                end--;
                continue;
            }
            if (tolower(str[start]) != tolower(str[end])) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};

int main() {
    Solution solution;
    string str = "A man, a plan, a canal: Panama"; // Example input
    bool result = solution.isPalindrome(str); // Call the function
    cout << "Is palindrome: " << (result ? "true" : "false") << endl;
    return 0;
}
