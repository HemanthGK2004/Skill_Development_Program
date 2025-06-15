// print the all possible permutation of the given string
#include <bits/stdc++.h>
using namespace std;
void printPermutation(string s, string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        string left=s.substr(0,i);
        string right=s.substr(i+1);
        string rest=left+right;
        printPermutation(rest,ans+ch);
    }
}
int main(){
    string s="abc";
    printPermutation(s,"");
    return 0;
}