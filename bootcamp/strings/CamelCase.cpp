// Camel Case Conversion
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string camelCaseConversion(const string& str) {
        string result;
        bool toUpper = false; // Flag to indicate if the next character should be uppercase

        for (char c : str) {
            if (c == ' ') {
                toUpper = true; // Next character should be uppercase
            } else {
                if (toUpper) {
                    result += toupper(c); // Convert to uppercase
                    toUpper = false; // Reset the flag
                } else {
                    result += c; // Keep the character as is
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string input = "hello world"; // Example input
    string result = solution.camelCaseConversion(input); // Call the function
    cout << "Camel Case: " << result << endl; // Output the result
    return 0; // Return success
}