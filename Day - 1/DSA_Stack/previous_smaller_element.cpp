// Smaller Element
// Given an array of integers, find the smallest element in the array.
// Input
// An array of integers
// Output
// The smallest element in the array
#include <bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;
int main() {
    vector<int>arr={3,1,0,8,6};
    stack<int>st;
    vector<int>ans(arr.size(),0);
    for(int i =0;i<arr.size();i++){
        while(st.size()>0 && st.top()>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    for(int val:ans){
        cout<<val<<" ";
    }
    return 0;
}
// Time Complexity: O(N)
// Space Complexity: O(N)
// Input: arr = [6,8,0,1,3]
// Output: -1 6 -1 0 1
// Explanation: The smallest element in the array is 0. The smallest element to the left of 6 is -1. The smallest element to the left of 8 is 6. The smallest element to the left of 0 is -1. The smallest element to the left of 1 is 0. The smallest element to the left of 3 is 1. Hence the output is -1 6 -1 0 1.