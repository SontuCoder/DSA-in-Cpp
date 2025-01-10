// Reverse a string using stack

#include<iostream>
#include<stack>
using namespace std;


string reverse(string s){
    stack<char> v;
    for(int i = 0; i<s.size(); i++){
        v.push(s[i]);
    }
    s="";
    while(v.size()!=0){
        s.push_back(v.top());
        v.pop();
    }
    return s;
}


int main(){
    string s = "";
    cout<<"Enter the string :-";
    cin>>s;

    string a = reverse(s);
    cout<<"Ans :-"<<a;

    return 0;
}