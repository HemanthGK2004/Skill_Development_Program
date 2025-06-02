#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution{
    public:
    string removeAllOccurences(string s , string part){
        if(s.length() > 0  && s.find(part)<s.length()){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};
int main() {
    Solution solution;
    string s = "daabcbaabcbc";
    string part = "abc";
    string result = solution.removeAllOccurences(s, part); // Call the function
    cout << "Result: " << result << endl; // Output the result
    return 0; // Return success
}