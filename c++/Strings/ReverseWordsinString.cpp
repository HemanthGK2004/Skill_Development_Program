#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution{
    public:
    string reverseWords(string s){
        string ans = "";
        int n = s.length();
        reverse(s.begin(), s.end());
        for(int i =0;i<n;i++){
            string word = "";
            while(i<n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.length() > 0){
                ans += word + " ";
            }
        }
        return ans.substr(0, ans.length() - 1); // Remove the trailing space
    }
};
int main() {
    Solution solution;
    string s = "the sky is blue";
    string result = solution.reverseWords(s); // Call the function
    cout << "Result: " << result << endl; // Output the result
    return 0; // Return success
}