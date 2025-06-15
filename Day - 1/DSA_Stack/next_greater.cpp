// Next greater element
#include <bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;
int main()
{
    vector<int>arr={6,8,0,1,3};
    stack<int>st;
    vector<int>ans(arr.size(),0);
    for(int i = arr.size()-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    for(int val:ans)
    {
        cout<<val<<" ";
    }
    return 0;
}