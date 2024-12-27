// Permutation of a String:- Leetcode 46, 

#include<iostream>
#include<vector>
#include<map>
using namespace std;

// first approch:-
void letCom(string s, string out, vector<string> &v){
    int n = s.length();
    if(n==0) {
        v.push_back(out);
        return;
    }
    
    for(int i = 0; i<n; i++){
        char a = s[i];
        out = out+a;
        s.erase(i,1);
        letCom(s,out,v);
        s.insert(i,1,a);
        out.pop_back();
    }
}

vector <string> letterCombination(string s){
    vector<string> v;
    if(s.length()==0) return v;
    string output = "";
    letCom( s, output, v);
    return v; 
}

// 2nd Approch:-

void letterPer(string s, int i, vector<string> &v){
    if(i>=s.length()){
        v.push_back(s);
        return;
    }
    for(int j=i; j<s.length();j++){
        swap(s[i],s[j]);
        letterPer(s,i+1,v);
        swap(s[i],s[j]);
    }
}

vector<string> lettterCom(string s){
    vector<string> v;
    if(s.length()==0) return v;
    int i = 0;
    letterPer( s, i, v);
    

    return v; 
}

int main(){
    string s;
    cout<<"Enter the number:- ";
    cin>>s;
    vector<string> s1= lettterCom(s);
    cout<<"The Ans:-"<<endl;
    for(string i:s1){
        cout<<i<<" ";
    }
    return 0;
}