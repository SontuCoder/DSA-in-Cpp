// Problem Statement
// You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
// Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
// You need to find and return that number which is unique in the array/list.

// same Leetcode - 1207

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    cout<<"The array:- ";
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> a;
    int n;
    cout<<"Enter the number the numbers:- ";
    cin>>n;
    for(int i = 0;i<n; i++){
        cout<<"Enter the number:- ";
        int j ;
        cin>>j;
        a.push_back(j);
    }
    print(a);
    int result=0;
    for(int j: a){
        result = result^j;
    }
    cout<<"The unique number be: "<<result<<endl;
    return 0;
}