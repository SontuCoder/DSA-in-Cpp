// 442. Find All Duplicates in an Array

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output.

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

vector<int> dupli(vector<int> v){
    vector<int> v1;
    for(int i:v){
        i=abs(i);
        if(v[i-1]>0){
            v[i-1] =0-v[i-1];
        } else {
            v1.push_back(i);
        }
    }
    return v1;
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
    vector<int> v = dupli(a);
    cout<<"The duplicates be: ";
    print(v);
    return 0;
}