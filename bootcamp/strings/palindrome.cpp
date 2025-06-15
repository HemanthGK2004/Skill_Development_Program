// Check for a palindrome
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string& str) {
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false; // If characters don't match, it's not a palindrome
            }
            left++;
            right--;
        }
        return true; // All characters matched, it's a palindrome
    }
};

int main() {
    Solution solution;
    string input = "radar"; // Example input
    bool result = solution.isPalindrome(input); // Call the function
    cout << "Is palindrome: " << (result ? "true" : "false") << endl; // Output the result
    return 0; // Return success
}
// This code checks if a given string is a palindrome by comparing characters from both ends towards the center.