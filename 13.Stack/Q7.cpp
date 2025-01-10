// sort a stack :-

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

void insertSort(stack<int> &s, int n){
    if(s.empty() ||(s.top()<=n)){
        s.push(n);
        return;
    }
    int m = s.top();
    s.pop();
    insertSort(s,n);
    s.push(m);
}

void sort(stack<int> &s){
    if(s.empty()) return;

    int m = s.top();
    s.pop();
    sort(s);
    insertSort(s,m);
}


int main(){
    stack<int> s;
    s.push(-2);
    s.push(3);
    s.push(9);
    s.push(-1);
    s.push(-2);
    s.push(0);

    print(s);
    sort(s);
    print(s);

    return 0;
}