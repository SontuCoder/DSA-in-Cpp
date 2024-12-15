// Move all zeros of the array in right
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

void move_zeros(vector<int> &v){
    int i = 0;
    int j = 0;
    while(i<v.size()){
        if(v[i]!=0){
            swap(v[i],v[j++]);
        }
        i++;
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
    move_zeros(v);
    print(v);
    cout<<"==============================="<<endl;
    return 0;
}