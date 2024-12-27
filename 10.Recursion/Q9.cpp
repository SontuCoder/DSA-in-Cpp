// Letter Combination of a Phone Number:- leetcode 17

#include<iostream>
#include<vector>
#include<map>
using namespace std;

void letCom(int i, string s, string out, map<int,string> m, vector<string> &v){
    if(i>=s.length()) {
        v.push_back(out);
        return;
    }
    
    int a =s[i]-'0';

    for(char j: m[a]){
        out = out+ j;
        letCom(i+1, s, out, m, v);
        out.pop_back();
    }    
}


vector <string> letterCombination(string s){
    vector<string> v;
    if(s.length()==0) return v;
    int index = 0;
    string output = "";
    int index1 = 0;
    map<int, string> m;
    m[0] = "";
    m[1] = "";
    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tuv";
    m[9] = "wxyz";
    
    letCom(index, s, output, m, v);
    return v;
}

int main(){
    string s;
    cout<<"Enter the number:- ";
    cin>>s;
    vector<string> s1= letterCombination(s);
    cout<<"The Ans:-"<<endl;
    for(string i:s1){
        cout<<i<<" ";
    }
    return 0;
}