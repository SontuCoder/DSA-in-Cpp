// Reverse the array
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

void reverse(vector<int> &v){
    int i = 0;
    int j = v.size()-1;
    while(i<j){
        swap(v[i++],v[j--]);
    }
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
    reverse(v);
    print(v);
    cout<<"==============================="<<endl;
    return 0;
}