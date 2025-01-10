// Reverse the stack :-


#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s){
    cout<<"Elements :- ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
}

void insert(stack<int> &s, int n){
    if(s.empty()){
        s.push(n);
        return;
    }
    int m = s.top();
    s.pop();
    insert(s,n);
    s.push(m);
}

void reverse(stack<int> &s){
    if(s.empty()) return;

    int n = s.top();
    s.pop();
    reverse(s);
    insert(s,n);
}



int main(){
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(2);
    print(s);

    reverse(s);
    print(s);
    return 0;
}