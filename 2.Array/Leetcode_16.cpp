// Longest Consecutive Sequence in an Array :-

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lCS(vector<int> v){
    sort(v.begin(), v.end());
    int maxLen = 0;
    int len = 0;
    for(int i = 0; i<v.size()-1; i++){
        if(v[i]+1 == v[i+1]){
            len++;
        } else if(v[i] == v[i+1]){
            continue;
        }
        else {
            maxLen = max(maxLen, len+1);
            len = 0;
        }
    }
    maxLen = max(maxLen, len+1);
    return maxLen;
}

int main(){
    vector<int> v ={3, 8, 5, 7, 6};
    cout<<"Longest seq :- "<<lCS(v);
    return 0;
}