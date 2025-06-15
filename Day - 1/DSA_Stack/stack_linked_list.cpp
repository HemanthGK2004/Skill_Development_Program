// Stack using linked list
#include<iostream>
using namespace std;
#include <list>

class stack{
    list<int> l;
    public:
    void push(int x){
        l.push_front(x);
    }
    void pop(){
        if(l.size()>0){
            l.pop_front();
        }
    }
    int top(){
        if(l.size()>0){
            return l.front();
        }
        return -1;
    }
    bool empty(){
        return l.size()==0;
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
}c