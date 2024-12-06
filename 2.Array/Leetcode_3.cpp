// Problem Statement

// You are given an array 'ARR' of size 'N' containing each number between 1 and 'N'-1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

// For example:
// Consider ARR [1, 2, 3, 4, 4] the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.

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

int dupli(vector<int> v){
    int a=0;
    for(int i:v){
        a^=i;
    }

    for(int i = 1; i<v.size();i++){
        a^=i;
    }
    return a;
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
    cout<<"The duplicate be: "<<dupli(a);
    return 0;
}