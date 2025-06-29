//find the longest substring without repeating characters
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
    public:
    int lengthOfLongestSubstring(string s){
        unordered_map<char,int>lastSeen;
        int maxLength = 0;
        int left = 0;
        int n = s.size();
        for(int right =0;right < n;right++){
            char currentChar = s[right];
            if((lastSeen.find(currentChar) != lastSeen.end()) &&(lastSeen[currentChar] >= left)){
                left = lastSeen[currentChar] + 1;
            }
            lastSeen[currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
int main() {
    Solution solution;
    string s = "abcabcbb"; // Example input
    int result = solution.lengthOfLongestSubstring(s); // Call the function
    cout << "Length of longest substring without repeating characters: " << result << endl; // Output the result
    return 0; // Return success
}