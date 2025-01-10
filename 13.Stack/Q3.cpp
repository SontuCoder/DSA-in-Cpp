// midd number of stack

#include<iostream>
#include<stack>
using namespace std;

int deleteMid(stack<int> &s){
    stack<int> s1;
    for(int i = 0; i<=s.size()/2; i++){
        s1.push(s.top());
        s.pop();
    }
    s.pop();
    while (s1.size() != 0)
    {
        s.push(s1.top());
        s1.pop();
    }
}

void print(stack<int> s){
    cout<<"stack:-";
    int size = s.size();
    for(int i = 0; i<size; i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}


int main(){
    stack<int> s;
    cout<<"Enter number of elements :- ";
    int n;
    cin>>n;
    for(int i = 0; i<n;i++){
        int a;
        cin>>a;
        s.push(a);
    }
    print(s);
    deleteMid(s);
    print(s);
    return 0;
}