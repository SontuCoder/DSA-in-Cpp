// Intersection of  two sorted array:-

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

vector<int> dupli(vector<int> v, vector<int> w){
    int i=0;
    int j=0;
    vector<int> v1;
    while(i<v.size() && j<w.size()){
        if(v[i] == w[j]){
            v1.push_back(v[i]);
            i++;
            j++;
        } else if(v[i] > w[j]){
            j++;
        } else {
            i++;
        }
    }
    return v1;
}


int main(){
    vector<int> a;
    int n;
    cout<<"Enter the number the First array numbers:- ";
    cin>>n;
    for(int i = 0;i<n; i++){
        cout<<"Enter the number:- ";
        int j ;
        cin>>j;
        a.push_back(j);
    }
    print(a);

    vector<int> b;
    int n1;
    cout<<"Enter the number the second array numbers:- ";
    cin>>n1;
    for(int i = 0;i<n1; i++){
        cout<<"Enter the number:- ";
        int j ;
        cin>>j;
        b.push_back(j);
    }
    print(b);

    vector<int> v = dupli(a,b);
    cout<<"The Intersection be: ";
    print(v);
    return 0;
}