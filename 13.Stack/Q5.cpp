// Insert number in buttom of stack

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

// Approch 1
void insert(stack<int> &s, int n){
    stack<int> s1;
    while(!s.empty()){
        s1.push(s.top());
        s.pop();
    }
    s.push(n);
    while(!s1.empty()){
        s.push(s1.top());
        s1.pop();
    }
}

void insert1(stack<int> &s, int n){
    if(s.empty()){
        s.push(n);
        return;
    }
    int m = s.top();
    s.pop();
    insert(s,n);
    s.push(m);
}


int main(){
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(2);
    print(s);

    int n;
    cout<<"Enter number:- ";
    cin>>n;
    insert1(s,n);
    print(s);
    return 0;
}