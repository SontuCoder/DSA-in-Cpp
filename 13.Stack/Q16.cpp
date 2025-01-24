// infix to postfix :-

#include<iostream>
#include<stack>
#include<map>
using namespace std;

string inToPost(string s){
    map<char, int> m;
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;
    m['^'] = 3;
    stack<char> st;
    string ans = "";
    for(int i = 0; i< s.size(); i++){
        if(s[i] == '(') st.push(s[i]);
        else if(m.find(s[i]) != m.end()){
            if(st.empty() || m[st.top()] < m[s[i]]) st.push(s[i]);
            else{
                while(!st.empty() && m[st.top()] >= m[s[i]]){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        } else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            ans += s[i];
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}



int main(){
    string inFix;
    cout<<"Enter :- ";
    cin>> inFix;
    cout<<inToPost(inFix);
    return 0;
}