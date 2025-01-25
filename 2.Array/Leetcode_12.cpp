// Sorted, Rotate the array:-
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    cout<<"The array be:- ";
    for(int i :v){
        cout<<i<<" ";
    }
    cout<<endl;
}

bool sortRotate(vector<int> v){
    int rotate = 0;
    for(int i = 0; i<v.size()-1; i++){
        if(v[i]>v[i+1]){
            rotate++;
        }
    }
    if(v[0]<v[v.size()-1]){
        rotate++;
    }
    return rotate<=1;
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
    cout<<"==============================="<< endl;
    print(v);
    cout<<"==============================="<< endl;
    cout<<"The array be sorted and rotated:- "<<sortRotate(v)<<endl;
    cout<<"==============================="<<endl;
    return 0;
}