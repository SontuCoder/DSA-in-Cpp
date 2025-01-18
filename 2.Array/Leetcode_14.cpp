// Second minimum element in Array:-

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int sec(vector<int> v){
    int first = INT_MAX;
    int second =INT_MAX;
    for(int i = 0; i<v.size(); i++){
        first = min(first, v[i]);
    }
    for(int i = 0; i<v.size(); i++){
        if(v[i]!= first){
            second = min(second, v[i]);
        }
    }
    
    return second;
}


int main(){
    int n;
    cout<<"Enter the number of element:- ";
    cin>>n;
    cout<<"==============================="<< endl;
    vector<int> v;
    for(int i=0; i<n; i++){
        int a;
        cout<<"Enter the number:- ";
        cin>>a;
        v.push_back(a);
    }
    cout<<"Second Largest Element:- "<<sec(v);
    return 0;
}