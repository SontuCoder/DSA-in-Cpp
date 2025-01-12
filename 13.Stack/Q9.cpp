// Minimum Cost To Make String Valid

#include<iostream>
#include<stack>
using namespace std;

int cost(string s){
    if(s.size()%2) return -1;

    stack<char> st;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '{'){
            st.push(s[i]);
        } else {
            if(!st.empty() && st.top() == '{'){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
    }
    int a=0, b=0;
    while(st.size() != 0){
        if(st.top() =='{'){
            a++;
        } else {
            b++;
        }
        st.pop();
    }

    return (a+1)/2 + (b+1)/2;
}

int main(){
    string s;
    cout<<"Enter :- ";
    cin>>s;
    cout<<"Cost:- "<<cost(s);
    return 0;
}