#include<iostream>
#include<stack>

using namespace std;


int main(){
    stack<int>s;

    cout<<"The stack is empty :"<<s.empty()<<endl;

    s.push(1);
    cout<<"The Top: "<< s.top()<<endl;

    s.push(4);
    cout<<"The Top: "<< s.top()<<endl;
    s.push(2);
    cout<<"The Top: "<< s.top()<<endl;

    cout<<"The size of stack :"<<s.size()<<endl;

    s.pop();
    cout<<"The Top: "<< s.top()<<endl;
    cout<<"The size of stack :"<<s.size()<<endl;

    cout<<"The stack is empty :"<<s.empty()<<endl;

    return 0;
}