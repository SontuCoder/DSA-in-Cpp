// Bracket redendent or not

#include<iostream>
#include<stack>
using namespace std;

bool reden(string s){

    if(s.empty()) return true;
    stack<char> st;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            st.push(s[i]);
        } else {
            if(s[i] == ')'){
                bool redendent = true;
                while(st.top() != '('){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                        redendent = false;
                    }
                    st.pop();
                }
                if(redendent){
                    return true;
                }
                st.pop();
            } 
        }
    }
    return false;
}

int main(){
    string s;
    cout<<"Enter Equation:- ";
    cin>>s;
    if(!reden(s)){
        cout<<"redendent";
    } else {
        cout<<"not redendent";
    }
    return 0;
}