#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int firstNonRepeatingChar(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;  // Return index
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    string s = "leetcode";
    int index = solution.firstNonRepeatingChar(s);
    if (index != -1) {
        cout << "First non-repeating character: " << s[index] << endl;
    } else {
        cout << "No non-repeating character found." << endl;
    }
    return 0;
}
