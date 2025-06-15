// Check for a  binary
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isBinary(const string& str) {
        for (char c : str) {
            if (c != '0' && c != '1') {
                return false; // If any character is not '0' or '1', return false
            }
        }
        return true; // All characters are valid binary digits
    }
};

int main() {
    Solution solution;
    string input = "101010"; // Example input
    bool result = solution.isBinary(input); // Call the function
    cout << "Is binary: " << (result ? "true" : "false") << endl; // Output the result
    return 0; // Return success
}