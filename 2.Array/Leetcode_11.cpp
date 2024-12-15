// Rotate the array:-
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

vector<int> rotate(vector<int> v, int k){
    vector<int> v1(v.size());
    for(int i=0; i<v.size(); i++){
        v1[(i+k)%(v.size())] = v[i];
    }
    return v1;
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
    int k;
    cout<<"Enter the number of rotation:- ";
    cin>>k;
    cout<<"==============================="<< endl;
    vector<int> v1= rotate(v,k);
    print(v1);
    cout<<"==============================="<<endl;
    return 0;
}