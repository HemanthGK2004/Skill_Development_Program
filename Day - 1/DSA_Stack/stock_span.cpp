// stock span problem
#include <bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;
int main()
{
    vector<int>price={100,80,60,70,60,75,85};
    stack<int>st;
    vector<int>ans(price.size(),0);
    for(int i = 0;i<price.size();i++)
    {
        while(st.size()>0 && price[st.top()]<=price[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            ans[i]=i+1;
        }
        else
        {
            ans[i]=i-st.top();
        }
        st.push(i);
    }
    for(int val:ans)
    {
        cout<<val<<" ";
    }
    return 0;
}