#include<iostream>
#include<vector>
using namespace std;

class stack{
    vector<int> v;
    public:
    void push(int x){
        v.push_back(x);
    }
    void pop(){
        if(v.size()>0){
            v.pop_back();
        }
    }
    int top(){
        if(v.size()>0){
            return v[v.size()-1];
        }
        return -1;
    }
    bool empty(){
        return v.size()==0;
    }
};
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}