// Make Power set of a set:- Leetcode 78

#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>>& ans, vector<int> output, int index, vector<int>v){
    if(index >= v.size()) {
        ans.push_back(output);
        return;
    }
    // exclude
    solve(ans, output, index+1, v);

    // include
    output.push_back(v[index]);
    solve(ans, output, index+1, v);
}

vector<vector<int>> powerSet(vector<int> &v){
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(ans, output, index, v);
    return ans;
}

void print1D(vector<int> v){
    cout<<"============================\n The vector be:- ";
    for(int i:v){
        cout<<i<<" ";
    } cout<<endl;
}

void print2D(vector<vector <int>> v){
    cout<<"============================\n The vector be:- "<<endl;
    for(vector<int> i:v){
        for(int j:i){
            cout<<j<<" ";
        }cout<<endl;
    } cout<<endl;
}

int main(){
    int n;
    cout<<"Enter size of set:-";
    cin>>n;
    vector <int> v(n,0);
    for(int i=0; i<n; i++){
        cout<<"Enter data:-";
        cin>>v[i];
    }
    print1D(v);
    vector<vector<int>> v2 = powerSet(v);
    print2D(v2);
    return 0;
}