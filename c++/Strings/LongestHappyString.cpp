#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestPrefixSuffix(string s) {
        int n = s.size();
        vector<int>lps(n, 0);
        int j = 0;
        for (int i = 1; i < n; i++) {
            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
                lps[i] = j;
            }
        }
        return s.substr(0, lps[n - 1]);
    }
};
int main() {
    Solution solution;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    string result = solution.longestPrefixSuffix(s);
    cout << "Longest prefix which is also a suffix: " << result << endl;
    return 0;
}

