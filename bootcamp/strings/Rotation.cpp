// Check rotation of a string
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isRotation(const string& str1, const string& str2) {
        if (str1.length() != str2.length()) {
            return false; // If lengths are different, they can't be rotations
        }
        string concatenated = str1 + str1; // Concatenate str1 with itself
        return concatenated.find(str2) != string::npos; // Check if str2 is a substring of the concatenated string
    }
};

int main() {
    Solution solution;
    string str1 = "waterbottle"; // Example input
    string str2 = "erbottlewat"; // Example input
    bool result = solution.isRotation(str1, str2); // Call the function
    cout << "Is rotation: " << (result ? "true" : "false") << endl; // Output the result
    return 0; // Return success
}