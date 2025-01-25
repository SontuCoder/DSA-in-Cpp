// Generate all binary strings without consecutive 1’s;

#include<iostream>
#include<vector>
using namespace std;


void add(vector<string> & ans, int n, string &s){
    if(n == 0){
        ans.push_back(s);
        return;
    } 
    s.push_back('0');
    add(ans, n-1, s);
    s.pop_back();
    if(s[s.size()-1] != '1'){
        s.push_back('1');
        add(ans, n-1, s);
        s.pop_back();
    }
}

vector<string> solve(int n){
    vector<string> ans;
    string s = "";
    add(ans, n, s);
    return ans;
}


int main(){
    int n;
    cout<< "Enter n :- ";
    cin>>n;
    vector<string> v = solve(n);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}