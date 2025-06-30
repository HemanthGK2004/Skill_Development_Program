#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<unordered_set>
#include<climits>
using namespace std;

class Solution {
    public:
    bool isValidparenthesis(string s) {
        unordered_map<char,char>map;
        map['('] = ')'; // Map opening brackets to their corresponding closing brackets
        map['['] = ']';
        map['{'] = '}';
        map[')'] = '('; // Map closing brackets to their corresponding opening brackets
        map[']'] = '[';
        map['}'] = '{';
        stack<char>st;
        for(int i =0;i<s.size();i++){
            if(s[i]== '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]); // Push opening brackets onto the stack
            }else{
                if(st.empty()||map[st.top()]!=s[i]) {
                    return false; // If stack is empty or top doesn't match, return false
                }
                st.pop(); // Pop the matching opening bracket from the stack
            }
        }
        return st.empty(); // If stack is empty, all brackets matched correctly
    }
};

int main() {
    Solution solution;
    string s = "{[()]}"; // Example input
    bool result = solution.isValidparenthesis(s); // Call the function
    cout << (result ? "Valid Parentheses" : "Invalid Parentheses") << endl; // Output the result
    return 0; // Return success
}