// valid parenthesis

#include <iostream>
#include <stack>
using namespace std;

// Approch 1
bool valid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (!st.empty())
        {
            if (st.top() == '(' && s[i] == ')')
            {
                st.pop();
            }
            else if (st.top() == '{' && s[i] == '}')
            {
                st.pop();
            }
            else if (st.top() == '[' && s[i] == ']')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    return st.size() == 0;
}

// Approch 2

bool valid2(string s){
    stack<char> st;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        } else {
            if(s.empty()) return false;

            if ((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}


int main()
{
    string s;
    cout << "Enter the parenthesis:- ";
    cin >> s;
    cout << "Valid:- " << valid2(s);
    return 0;
}