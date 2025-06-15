#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution{
    public:
    bool isAnagram(string s, string t){
        if(s.length() != t.length()){
            return false;
        }
        vector<int>freq(26,0);
        for(int i =0;i<s.length();i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for(int count : freq){
            if(count != 0){
                return false;
            }
        }
        return true; // Return true if all counts are zero
    }
};
int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    bool result = solution.isAnagram(s, t); // Call the function
    cout << "Result: " << (result ? "true" : "false") << endl; // Output the result
    return 0; // Return success
}