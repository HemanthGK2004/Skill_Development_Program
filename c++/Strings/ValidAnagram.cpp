#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution{
    public:
    string ValidAnagram(string s , string t){
        if(s.length()!= t.length()){
            return "false";
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t ? "true" : "false";
    }
};
int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    string result = solution.ValidAnagram(s, t); // Call the function
    cout << "Result: " << result << endl; // Output the result
    return 0; // Return success
}