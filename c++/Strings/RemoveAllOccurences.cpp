#include<iostream>
#include<vector>
#include<string>

using namespace std;
<<<<<<< HEAD
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};
int main() {
    Solution solution;
    string s = "daabcbaabcbc";
    string part = "abc";
    string result = solution.removeOccurrences(s, part); // Call the function
    cout << "Result: " << result << endl; // Output the result
    return 0; // Return success
}