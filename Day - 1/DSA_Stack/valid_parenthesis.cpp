// valid parenthesis
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    bool isValid(string s){
        stack<char> st;
        unordered_map<char, char> map;
        map['('] = ')';
        map['{'] = '}';
        map['['] = ']';
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty() || map[st.top()]!=s[i]){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
}