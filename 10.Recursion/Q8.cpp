// Subsequences of a string:-

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(vector<string> & ans, string output, int index, string s){
    if(index >= s.size()){
        ans.push_back(output);
        return;
    }

    // exclude
    solve(ans, output, index+1, s);

    //Include
    output.push_back(s[index]);
    solve(ans, output, index+1, s);
}

vector<string> subSequence(string s){
    vector<string> ans;
    string output= "";
    int index = 0;
    solve(ans, output, index, s);
    return ans;
}

int main(){
    string s;
    cout<<"Enter the string:- ";
    cin>>s;
    cout<<"the string:- "<<s<<endl;
    vector<string> v = subSequence(s);
    cout<<"The subsequences be:- "<<endl;
    for(string i: v){
        cout<< i<<endl;
    }
    return 0;
}